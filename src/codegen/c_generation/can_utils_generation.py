'''
Codegen for .h and .c files for CAN utils file (for message packing/unpacking).
'''


from ...can_database import *
from ...utils import *
from .shared_c_generation import *
from .c_config import *


APP_CANMSG_PACK = '''\
    // Pack {msg_bytes}-byte ({msg_bits}-bit) message {msg_name}.
    
{signal_packers}'''

APP_CANMSG_UNPACK = '''\
    // Unpack {msg_bytes}-byte ({msg_bits}-bit) message {msg_name}.
    
{signal_unpackers}'''

PACK_FUNC_CALL = '{name}({value}, {shift}, {mask})'

PACK_TEMPLATE = '''\
    out_data[{byte_index}] |= {func_call};   // Packs bits {bits_comment} (mask={mask_comment}) of message byte {byte_index}'''

UNPACK_TEMPLATE = '''\
    {var_name} |= {func_call};   // Unpacks bits {bits_comment} of message byte {byte_index} (mask={mask_comment})'''


class AppCanUtilsGenerator(EmbeddedFileGenerator):
    '''
    Generates code shared by .h and .c for CAN utils.
    '''

    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_functions()

    def _init_functions(self):
        # Generate all packing functions for transmitted CAN messages
        for msg in self._db.messages_transmitted_by_node(self._node):
            signal_packers = [gen_signal_packing_code(signal=signal, msg=msg) for signal in msg.signals]
            self._functions.append(
                CFunction(
                    signature=f'void {UtilFuncNames.PACK.format(msg=msg.name)}(const {StructNames.MSG_STRUCT.format(msg=msg.name)}* const in_msg, uint8_t* const out_data)',
                    comment=f'Pack signal data for CAN message {msg.name}.',
                    body=APP_CANMSG_PACK.format(
                        msg_bytes=msg.bytes(),
                        msg_bits=msg.bytes()*BYTE_SIZE,
                        msg_name = msg.name,
                        signal_packers = '\n\n'.join(signal_packers),
                    )
                )
            )

        # Generate all unpacking functions for received CAN messages
        for msg in self._db.messages_received_by_node(self._node):
            signal_unpackers = [gen_signal_unpacking_code(signal=signal, msg=msg) for signal in msg.signals]
            self._functions.append(
                CFunction(
                    signature=f'void {UtilFuncNames.UNPACK.format(msg=msg.name)}(const uint8_t* const in_data, {StructNames.MSG_STRUCT.format(msg=msg.name)}* const out_msg)',
                    comment=f'Unpack signal data for CAN message {msg.name}.',
                    body=APP_CANMSG_UNPACK.format(
                        msg_bytes=msg.bytes(),
                        msg_bits=msg.bytes()*BYTE_SIZE,
                        msg_name = msg.name,
                        signal_unpackers = '\n\n'.join(signal_unpackers),
                    )
                )
            )

class AppCanMsgsHeaderGenerator(AppCanUtilsGenerator):
    '''
    Generates .h specific code for CAN utils.
    '''

    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()
        self._init_macros()
        self._init_enums()
        self._init_structs()

    def _init_includes(self):
            header_names = ['<stdint.h>', '<stdbool.h>']
            self._includes= [CHeaderInclude(name) for name in header_names]

    def _init_macros(self):
        # Message ID macros
        self._macros_text += f'// Message IDs\n'
        for msg in self._db.messages_for_node(self._node):
            self._macros_text += CMacro(
                name=AttributeMacros.ID.format(msg=msg.name),
                body=CIntLiteral(msg.id).hex()
            ).declaration() + '\n'
            
        # Tx message length macros
        self._macros_text += f'\n// Message lengths in bytes\n'
        for msg in self._db.messages_transmitted_by_node(self._node):
            self._macros_text += CMacro(
                name=AttributeMacros.BYTES.format(msg=msg.name),
                body=CIntLiteral(msg.bytes()).dec()
            ).declaration() + '\n'
            
        # Tx message cycle time macros
        self._macros_text += f'\n// Message cycle times in ms\n'
        for msg in self._db.messages_transmitted_by_node(self._node):
            if msg.is_periodic():
                self._macros_text += CMacro(
                    name=AttributeMacros.CYCLE_TIME.format(msg=msg.name),
                    body=CIntLiteral(msg.cycle_time).dec()
                ).declaration() + '\n'

        # Signal initial value macros
        self._macros_text += f'\n// Signal default starting values\n'
        for msg in self._db.messages_for_node(self._node):
            for signal in msg.signals:
                start_val = signal.start_value if signal.has_non_default_start_val() else self._db.bus_params.start_value_default

                self._macros_text += CMacro(
                    name=AttributeMacros.START_VAL.format(msg=msg.name, signal=signal.name),
                    body=start_val,
                ).declaration() + (f' // {signal.unit} \n' if signal.has_unit() else '\n')

        # Tx scale macros
        self._macros_text += f'\n// Scale values for encoding/decoding signals\n'
        for msg in self._db.messages_for_node(self._node):
            for signal in msg.signals:
                self._macros_text += CMacro(
                    name=AttributeMacros.SCALE.format(msg=msg.name, signal=signal.name),
                    body=f'{int(signal.scale)}' if signal.represent_as_integer() else f'{float_to_str(signal.scale)}f',
                ).declaration() + '\n'

         # Offset macros
        self._macros_text += f'\n// Offset values for encoding/decoding signals\n'
        for msg in self._db.messages_for_node(self._node):
            for signal in msg.signals:
                self._macros_text += CMacro(
                    name=AttributeMacros.OFFSET.format(msg=msg.name, signal=signal.name),
                    body=f'{int(signal.offset)}' if signal.represent_as_integer() else f'{float_to_str(signal.offset)}f',
                ).declaration() + '\n'

        # Minimum value macros
        self._macros_text += f'\n// Minimum allowed values for signals\n'
        for msg in self._db.messages_for_node(self._node):
            for signal in msg.signals:
                self._macros_text += CMacro(
                    name=AttributeMacros.MIN.format(msg=msg.name, signal=signal.name),
                    body=f'{int(signal.min_val)}' if signal.represent_as_integer() else f'{float_to_str(signal.min_val)}f',
                ).declaration() + '\n'

        # Maximum value macros
        self._macros_text += f'\n// Maximum allowed values for signals\n'
        for msg in self._db.messages_for_node(self._node):
            for signal in msg.signals:
                self._macros_text += CMacro(
                    name=AttributeMacros.MAX.format(msg=msg.name, signal=signal.name),
                    body=f'{int(signal.max_val)}' if signal.represent_as_integer() else f'{float_to_str(signal.max_val)}f',
                ).declaration() + '\n'

    def _init_enums(self):
        # Tx signal enums
        for msg in self._db.messages_for_node(self._node):
            for signal in msg.signals:
                if signal.enum:
                    self._enums.append(CEnum(
                        name=signal.enum.name,
                        members=[(entry.name, entry.value) for entry in signal.enum.items]
                    ))

    def _init_structs(self):
        msg_desc = '''\
    * Description: {description}
    * Range: {min}{unit} to {max}{unit}
    * Unit: {unit_desc}'''

        # Message structs
        for msg in self._db.messages_for_node(self._node):
            self._structs.append(
                CStruct(
                    name = StructNames.MSG_STRUCT.format(msg=msg.name),
                    comment = f'Signals in CAN message {msg.name}.',
                    members=[
                        CVarDeclaration(
                            name=f'{signal.name}_value',
                            type=signal.datatype(),
                            comment=msg_desc.format(
                                description=signal.description,
                                min=signal.min_val,
                                max=signal.max_val,
                                unit=signal.unit,
                                unit_desc=signal.unit if signal.has_unit() else 'No units',
                            )
                        ) for signal in msg.signals
                    ]
                ) 
            )


class AppCanUtilsSourceGenerator(AppCanUtilsGenerator):
    '''
    Generates .c specific code for CAN utils.
    '''
    
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()
        self._init_static_functions()

    # TODO: Make these actually static?
    def _init_static_functions(self):
        # Pack left
        self._static_functions.append(
            CFunction(
                signature=f'uint8_t {UtilFuncNames.PACK_LEFT}(uint32_t input, uint8_t shift, uint8_t mask)',
                body='''\
    return (uint8_t)((uint8_t)(input << shift) & mask);''',
                comment='Shift input left by shift bits, and apply mask, for packing CAN messages.'
            )
        )

        # Pack right
        self._static_functions.append(
            CFunction(
                signature=f'uint8_t {UtilFuncNames.PACK_RIGHT}(uint32_t input, uint8_t shift, uint8_t mask)',
                body='''\
    return (uint8_t)((uint8_t)(input >> shift) & mask);''',
                comment='Shift input right by shift bits, and apply mask, for packing CAN messages.'
            )
        )

        # Unpack left
        self._static_functions.append(
            CFunction(
                signature=f'uint32_t {UtilFuncNames.UNPACK_LEFT}(uint8_t input, uint8_t shift, uint8_t mask)',
                body='''\
    return (uint32_t)((uint32_t)(input & mask) << shift);''',
                comment='Apply mask, then shift input left by shift bits, for unpacking CAN messages.'
            )
        )

        # Unpack right
        self._static_functions.append(
            CFunction(
                signature=f'uint32_t {UtilFuncNames.UNPACK_RIGHT}(uint8_t input, uint8_t shift, uint8_t mask)',
                body='''\
    return (uint32_t)((uint32_t)(input & mask) >> shift);''',
                comment='Apply mask, then shift input right by shift bits, for unpacking CAN messages.'
            )
        )

        # Encoding functions (uint, int, and float)
        types_for_encoding = {
            CanSignalDatatype.UINT: UtilFuncNames.ENCODE_UINT,
            CanSignalDatatype.INT: UtilFuncNames.ENCODE_INT,
            CanSignalDatatype.DECIMAL: UtilFuncNames.ENCODE_FLOAT,
        }

        for type, encoding_func_name in types_for_encoding.items():
            self._static_functions.append(
                CFunction(
                    signature=f'uint32_t {encoding_func_name}({type} input, {type} scale, {type} offset)',
                    body='''\
    return (uint32_t)((input - offset) / scale);''',
                    comment='Encode signal value to get CAN payload represenation.'
                )
            )

        # Decoding functions (uint, int, and float)
        types_for_decoding = {
            CanSignalDatatype.UINT: UtilFuncNames.DECODE_UINT,
            CanSignalDatatype.INT: UtilFuncNames.DECODE_INT,
            CanSignalDatatype.DECIMAL: UtilFuncNames.DECODE_FLOAT,
        }

        for type, decoding_func_name in types_for_decoding.items():
            self._static_functions.append(
                CFunction(
                    signature=f'{type} {decoding_func_name}(uint32_t input, {type} scale, {type} offset)',
                    body=f'''\
    return ({type})(({type})input * scale + offset);''',
                    comment='Decode payload bits to get signal value.'
                )
            )

    def _init_includes(self):
        header_names = ['"App_CanUtils.h"']
        self._includes= [CHeaderInclude(name) for name in header_names]

    
def gen_signal_packing_code(signal: CanSignal, msg: CanMessage):
    '''
    Generate code for packing a signal into a raw message payload.
    '''
    starting_byte = signal.start_bit // BYTE_SIZE
    packed_bits = 0

    # Bit position signal will begin on the first byte it occupies
    bit_start = signal.start_bit - starting_byte * BYTE_SIZE 

    signal_val_var_name = f'{signal.name}_value'
    signal_raw_var_name = f'{signal.name}_raw'
    body = [f'''\
    // Pack {signal.bits}-bit signal {signal.name} into message (at bit {signal.start_bit} to bit {signal.start_bit+signal.bits}).
    const {signal.datatype()} {signal_val_var_name} = in_msg->{signal.name}_value;''']

    # Encoding function name
    encode_func_name = ''
    if signal.datatype_internal() == CanSignalDatatype.UINT:
        encode_func_name = UtilFuncNames.ENCODE_UINT
    elif signal.datatype_internal() == CanSignalDatatype.INT:
        encode_func_name = UtilFuncNames.ENCODE_INT
    else: 
        encode_func_name = UtilFuncNames.ENCODE_FLOAT

    body.append(f'''\
    const uint32_t {signal_raw_var_name} = {encode_func_name}({signal_val_var_name}, \
{AttributeMacros.SCALE.format(msg=msg.name, signal=signal.name)}, \
{AttributeMacros.OFFSET.format(msg=msg.name, signal=signal.name)});''')

    while packed_bits < signal.bits:
        # Bits to pack this iteration is either how many bits can fit in current byte (8 - start) 
        # or the remaining unpacked bits (length in bits - packed bits) (whichever is lower)
        bits_to_pack = min(BYTE_SIZE - bit_start, signal.bits - packed_bits)

        # Positive is shifting to right, negative is shifting to left
        # Shift right by packed_bits to remove what was already packed
        # Shift left by bit_start so LSB lies at bit_start
        shift = packed_bits - bit_start

        # Make mask: 1 at each digit we're packing, 0 everywhere else
        mask = max_uint_for_bits(bits_to_pack) << bit_start # TODO: Confirm this works in Python like C
        mask_text = CIntLiteral(mask).hex()

        # Make comment
        comment_data = ['_'] * BYTE_SIZE
        for i in range(bit_start, bit_start + bits_to_pack):
            comment_data[i] = '#'

        # Format shift function and append
        body.append(PACK_TEMPLATE.format(
            byte_index=starting_byte,
            func_call='{name}({value}, {shift}, {mask})'.format(
                name=UtilFuncNames.PACK_RIGHT if shift >= 0 else UtilFuncNames.PACK_LEFT,
                value=signal_raw_var_name,
                shift=abs(shift),
                mask=mask_text
            ),
            bits_comment=''.join(reversed(comment_data)),
            mask_comment= CIntLiteral(mask).bin()
        ))

        bit_start = 0 # After first iteration, further packings all start at bit 0
        packed_bits += bits_to_pack
        starting_byte += 1 

    return '\n'.join(body)

def gen_signal_unpacking_code(signal: CanSignal, msg: CanMessage):
    '''
    Generate code for unpacking a signal from a raw message payload.
    '''
    starting_byte = signal.start_bit // BYTE_SIZE
    unpacked_bits = 0

    # Bit position signal will begin on the first byte it occupies
    bit_start = signal.start_bit - starting_byte * BYTE_SIZE 

    signal_val_var_name = f'{signal.name}_value'
    signal_raw_var_name = f'{signal.name}_raw'
    body = [f'''\
    // Unpack {signal.bits}-bit signal {signal.name} from CAN message payload (at bit {signal.start_bit} to bit {signal.start_bit+signal.bits}).
    uint32_t {signal_raw_var_name} = 0;''']

    while unpacked_bits < signal.bits:
        # Bits to unpack this iteration is either how many bits can get from the current byte (8 - start) 
        # or the remaining packed bits (length in bits - unpacked bits) (whichever is lower)
        bits_to_unpack = min(BYTE_SIZE - bit_start, signal.bits - unpacked_bits)

        # Positive is shifting to right, negative is shifting to left
        # Shift right by bit_start so LSB of signal lies at LSB of signal uint variable
        # Shift left by unpacked_bits to add new data after previously unpacked bits
        shift = bit_start - unpacked_bits

        # Make mask: 1 at each digit we're unpacking, 0 everywhere else
        mask = max_uint_for_bits(bits_to_unpack) << bit_start # TODO: Confirm this works in Python like C
        mask_text = CIntLiteral(mask).hex()

        # Make comment
        comment_data = ['_'] * BYTE_SIZE
        for i in range(bit_start, bit_start + bits_to_unpack):
            comment_data[i] = '#'

        # Format shift function and append
        body.append(UNPACK_TEMPLATE.format(
            var_name=signal_raw_var_name,
            byte_index=starting_byte,
            func_call='{name}({value}, {shift}, {mask})'.format(
                name=UtilFuncNames.UNPACK_RIGHT if shift >= 0 else UtilFuncNames.UNPACK_LEFT,
                value=f'in_data[{starting_byte}]',
                shift=abs(shift),
                mask=mask_text
            ),
            bits_comment=''.join(reversed(comment_data)),
            mask_comment= CIntLiteral(mask).bin()
        ))

        bit_start = 0 # After first iteration, further packings all start at bit 0
        unpacked_bits += bits_to_unpack
        starting_byte += 1 
        
    # Decoding function name
    decode_func_name = ''
    if signal.datatype_internal() == CanSignalDatatype.UINT:
        decode_func_name = UtilFuncNames.DECODE_UINT
    elif signal.datatype_internal() == CanSignalDatatype.INT:
        decode_func_name = UtilFuncNames.DECODE_INT
    else: 
        decode_func_name = UtilFuncNames.DECODE_FLOAT

    # Decode raw payload bits
    body.append(f'''\
    const {signal.datatype()} {signal_val_var_name} = {decode_func_name}({signal_raw_var_name}, \
{AttributeMacros.SCALE.format(msg=msg.name, signal=signal.name)}, \
{AttributeMacros.OFFSET.format(msg=msg.name, signal=signal.name)});''')

    # Assign variable in output ptr
    body.append(f'''\
    out_msg->{signal.name}_value = {signal_val_var_name};''')

    return '\n'.join(body)
