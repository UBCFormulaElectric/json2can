from unicodedata import name
from ...can_database import *
from ...utils import *
from .c_config import *
from .c_writer import *

PACK_SHIFT_LEFT_FUNC = "packShiftLeft"
PACK_SHIFT_RIGHT_FUNC = "packShiftRight"
UNPACK_SHIFT_LEFT_FUNC = "unpackShiftLeft"
UNPACK_SHIFT_RIGHT_FUNC = "unpackShiftRight"

ENCODE_MACRO = "CAN_ENCODE"
DECODE_MACRO = "CAN_DECODE"

PACK_TEMPLATE = "out_data[{byte_index}] |= {func}({value}, {shift}, {mask});   // Packs bits {bits_comment} of byte {byte_index}"
UNPACK_TEMPLATE = "{var_name} |= {func}({value}, {shift}, {mask});   // Unpacks bits {bits_comment} of msg byte {byte_index}"


class AppCanUtilsModule(CModule):
    def __init__(self, db: CanDatabase, node: str):
        self._db = db
        self._node = node
        self._functions = self._public_functions()

    def _public_functions(self) -> List[CFunc]:
        funcs = []

        # Generate all packing functions for TX CAN msgs
        for msg in self._db.tx_msgs_for_node(self._node):
            func = CFunc(
                CFuncsCfg.UTILS_PACK.format(msg=msg.name),
                "void",
                args=[
                    CVar(
                        "in_msg",
                        f"const {CStructsCfg.MSG_STRUCT.format(msg=msg.name)}* const",
                    ),
                    CVar("out_data", "uint8_t* const"),
                ],
                comment=f"Pack signals into CAN payload for {msg.name}.",
            )
            func.body.add_comment(
                f"Pack {msg.bytes()}-byte payload for message {msg.name}."
            )
            func.body.add_comment(signal_placement_comment(msg))
            func.body.add_line()

            for signal in msg.signals:
                func.body.add_lines(pack_signal_code(signal, msg))
                func.body.add_line()

            funcs.append(func)

        # Generate all unpacking functions for RX CAN msgs
        for msg in self._db.rx_msgs_for_node(self._node):
            func = CFunc(
                CFuncsCfg.UTILS_UNPACK.format(msg=msg.name),
                "void",
                args=[
                    CVar("in_data", "const uint8_t* const"),
                    CVar(
                        "out_msg",
                        f"{CStructsCfg.MSG_STRUCT.format(msg=msg.name)}* const",
                    ),
                ],
                comment=f"Unpack signals from CAN payload for {msg.name}.",
            )
            func.body.add_comment(
                f"Unpack {msg.bytes()}-byte payload for message {msg.name}."
            )
            func.body.add_comment(signal_placement_comment(msg))
            func.body.add_line()

            for signal in msg.signals:
                func.body.add_lines(unpack_signal_code(signal, msg))
                func.body.add_line()

            funcs.append(func)

        return funcs

    def _macros_text(self) -> str:
        cw = CWriter()

        # Msg ID macros
        cw.add_comment("Msg IDs")
        for msg in self._db.msgs_for_node(self._node):
            cw.add_macro(
                CMacrosCfgs.ID.format(msg=pascal_to_screaming_snake_case(msg.name)),
                msg.id,
            )
        cw.add_line()

        # Tx Msg length macros
        cw.add_comment("Msg lengths (in bytes)")
        for msg in self._db.tx_msgs_for_node(self._node):
            cw.add_macro(
                CMacrosCfgs.BYTES.format(msg=pascal_to_screaming_snake_case(msg.name)),
                msg.bytes(),
            )
        cw.add_line()

        # Tx Msg cycle time macros
        cw.add_comment("Periodic msg cycle times (in MS)")
        for msg in self._db.tx_msgs_for_node(self._node):
            if msg.is_periodic():
                cw.add_macro(
                    CMacrosCfgs.CYCLE_TIME.format(
                        msg=pascal_to_screaming_snake_case(msg.name)
                    ),
                    msg.cycle_time,
                )
        cw.add_line()

        # Signal initial value macros
        cw.add_comment("Signal starting values")
        for msg in self._db.msgs_for_node(self._node):
            for signal in msg.signals:
                cw.add_macro(
                    CMacrosCfgs.START_VAL.format(
                        msg=pascal_to_screaming_snake_case(msg.name),
                        signal=pascal_to_screaming_snake_case(signal.name),
                    ),
                    str(CLiteral(signal.start_val)),
                    comment=signal.unit,
                )
        cw.add_line()

        # Tx scale + offset macros
        cw.add_comment("Scale/offset values for encoding/decoding signals")
        for msg in self._db.msgs_for_node(self._node):
            for signal in msg.signals:
                cw.add_macro(
                    CMacrosCfgs.SCALE.format(
                        msg=pascal_to_screaming_snake_case(msg.name),
                        signal=pascal_to_screaming_snake_case(signal.name),
                    ),
                    str(CLiteral(signal.scale)),
                )
                cw.add_macro(
                    CMacrosCfgs.OFFSET.format(
                        msg=pascal_to_screaming_snake_case(msg.name),
                        signal=pascal_to_screaming_snake_case(signal.name),
                    ),
                    str(CLiteral(signal.offset)),
                )
        cw.add_line()

        # Minimum/maximum value macros
        cw.add_comment("Min/max allowed values for signals")
        for msg in self._db.msgs_for_node(self._node):
            for signal in msg.signals:
                cw.add_macro(
                    CMacrosCfgs.MIN.format(
                        msg=pascal_to_screaming_snake_case(msg.name),
                        signal=pascal_to_screaming_snake_case(signal.name),
                    ),
                    str(CLiteral(signal.min_val)),
                    comment=signal.unit,
                )
                cw.add_macro(
                    CMacrosCfgs.MAX.format(
                        msg=pascal_to_screaming_snake_case(msg.name),
                        signal=pascal_to_screaming_snake_case(signal.name),
                    ),
                    str(CLiteral(signal.max_val)),
                    comment=signal.unit,
                )
        cw.add_line()

        return str(cw)

    def header(self):
        cw = CWriter()
        cw.add_preamble()
        cw.add_line()
        cw.add_line("#pragma once")

        # Add includes
        cw.add_line()
        cw.add_header_comment("Includes")
        cw.add_line()
        cw.add_include("<stdint.h>")
        cw.add_include("<stdbool.h>")

        # Add macros
        cw.add_line()
        cw.add_header_comment("Macros")
        cw.add_line()
        cw.add_lines(self._macros_text())

        # Find all enums for this node
        cw.add_line()
        cw.add_header_comment("Enums")
        cw.add_line()

        enums = []
        for msg in self._db.msgs_for_node(self._node):
            for signal in msg.signals:
                if signal.enum and signal.enum not in enums:
                    enums.append(signal.enum)

        # Add found enums
        for enum in enums:
            cenum = CEnum(enum.name)
            for item in enum.items:
                cenum.add_value(CVar(item.name, value=item.value))

            cw.add_enum(cenum)
            cw.add_line()

        # Add message structs
        cw.add_line()
        cw.add_header_comment("Structs")
        cw.add_line()

        for msg in self._db.msgs_for_node(self._node):
            struct = CStruct(
                CStructsCfg.MSG_STRUCT.format(msg=msg.name),
                comment=f"Signals in CAN msg {msg.name}.",
            )
            for signal in msg.signals:
                signal_comment = f"Range: {signal.min_val}{signal.unit} to {signal.max_val}{signal.unit}"
                struct.add_member(
                    CVar(
                        CVarsCfg.SIGNAL_VALUE.format(signal=signal.name),
                        signal.datatype(),
                        comment=signal_comment,
                    )
                )

            cw.add_struct(struct)
            cw.add_line()

        # Add packing/unpacking function prototypes
        cw.add_line()
        cw.add_header_comment("Function Prototypes")
        cw.add_line()

        for func in self._functions:
            cw.add_function_prototype(func)
            cw.add_line()

        return str(cw)

    def source(self):
        cw = CWriter()
        cw.add_preamble()
        cw.add_line()
        cw.add_include('"App_CanUtils.h"')

        # Add static packing/unpacking functions
        cw.add_line()
        cw.add_header_comment("Static Packing/Unpacking Functions")
        cw.add_line()

        pack_left = CFunc(
            PACK_SHIFT_LEFT_FUNC,
            "uint8_t",
            args=[
                CVar("input", "uint32_t"),
                CVar("shift", "uint8_t"),
                CVar("mask", "uint8_t"),
            ],
            comment="Shift input left and apply mask, for packing.",
            qualifier="static inline",
        )
        pack_left.body.add_code(
            "return (uint8_t)((uint8_t)(input << shift) & (uint8_t)mask);"
        )

        pack_right = CFunc(
            PACK_SHIFT_RIGHT_FUNC,
            "uint8_t",
            args=[
                CVar("input", "uint32_t"),
                CVar("shift", "uint8_t"),
                CVar("mask", "uint8_t"),
            ],
            comment="Shift input right and apply mask, for packing.",
            qualifier="static inline",
        )
        pack_right.body.add_code(
            "return (uint8_t)((uint8_t)(input >> shift) & (uint8_t)mask);"
        )

        unpack_left = CFunc(
            UNPACK_SHIFT_LEFT_FUNC,
            "uint32_t",
            args=[
                CVar("input", "uint8_t"),
                CVar("shift", "uint8_t"),
                CVar("mask", "uint8_t"),
            ],
            comment="Apply mask, then shift input left by shift bits, for unpacking.",
            qualifier="static inline",
        )
        unpack_left.body.add_code(
            "return (uint32_t)((uint32_t)(input & mask) << shift);"
        )

        unpack_right = CFunc(
            UNPACK_SHIFT_RIGHT_FUNC,
            "uint32_t",
            args=[
                CVar("input", "uint8_t"),
                CVar("shift", "uint8_t"),
                CVar("mask", "uint8_t"),
            ],
            comment="Apply mask, then shift input left by shift bits, for unpacking.",
            qualifier="static inline",
        )
        unpack_right.body.add_code(
            "return (uint32_t)((uint32_t)(input & mask) >> shift);"
        )

        cw.add_function_definition(pack_left, add_comment=True)
        cw.add_line()
        cw.add_function_definition(pack_right, add_comment=True)
        cw.add_line()
        cw.add_function_definition(unpack_left, add_comment=True)
        cw.add_line()
        cw.add_function_definition(unpack_right, add_comment=True)
        cw.add_line()

        # Add encoding/decoding macros
        cw.add_line()
        cw.add_header_comment("Encoding/Decoding Macros")
        cw.add_line()

        cw.add_macro(
            ENCODE_MACRO,
            "(uint32_t)((type)(input - offset) / (type)scale)",
            args=["input", "scale", "offset", "type"],
            comment="Encode real signal value to payload representation, w/ scale and offset.",
        )
        cw.add_line()
        cw.add_macro(
            DECODE_MACRO,
            "(type)((type)input * (type)scale + (type)offset)",
            args=["input", "scale", "offset", "type"],
            comment="Decode payload representation of signal to signal value, w/ scale and offset.",
        )
        cw.add_line()

        # Add packing/unpacking function definitions
        cw.add_line()
        cw.add_header_comment("Function Definitions")
        cw.add_line()

        for func in self._functions:
            cw.add_function_definition(func)
            cw.add_line()

        return str(cw)


def signal_placement_comment(msg: CanMessage):
    chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    signals = ["_"] * (msg.bytes() * 8)
    signals.extend(["x"] * ((8 - msg.bytes()) * 8))
    for signal_cnt, signal in enumerate(msg.signals):
        for i in range(signal.start_bit, signal.start_bit + signal.bits):
            signals[i] = chars[signal_cnt % len(chars)]

    signals = list(reversed(signals))
    return f'|{"|".join("".join(signals[i*8:(i+1)*8]) for i in range(0, 8))}|'


def pack_signal_code(signal: CanSignal, msg: CanMessage):
    """
    Generate code for packing a signal into raw msg payload.
    """
    starting_byte = signal.start_bit // BYTE_SIZE
    packed_bits = 0
    bit_start = signal.start_bit - (
        starting_byte * BYTE_SIZE
    )  # Bit position signal will begin on the first byte it occupies

    signal_val_var_name = f"{signal.name}_val"
    signal_raw_var_name = f"{signal.name}_raw"

    cw = CWriter()
    cw.add_comment(
        f"Pack {signal.bits}-bit signal {signal.name} into payload (at bit {signal.start_bit} to bit {signal.start_bit+signal.bits})."
    )
    cw.add_line(
        f"const {signal.datatype()} {signal_val_var_name} = in_msg->{signal.name}_value;"
    )

    # Encode signal value
    scale_macro = CMacrosCfgs.SCALE.format(msg=msg.name, signal=signal.name)
    offset_macro = CMacrosCfgs.OFFSET.format(msg=msg.name, signal=signal.name)
    cw.add_line(
        f"const uint32_t {signal_raw_var_name} = {ENCODE_MACRO}({signal_val_var_name}, {scale_macro}, {offset_macro}, {signal.representation()});"
    )

    while packed_bits < signal.bits:
        # Bits to pack this iteration is either how many bits can fit in current byte (8 - start)
        # or the remaining unpacked bits (length in bits - packed bits) (whichever is lower)
        bits_to_pack = min(BYTE_SIZE - bit_start, signal.bits - packed_bits)

        # Positive is shifting to right, negative is shifting to left
        # Shift right by packed_bits to remove what was already packed
        # Shift left by bit_start so LSB lies at bit_start
        shift = packed_bits - bit_start

        # Make mask: 1 at each digit we're packing, 0 everywhere else
        mask = max_uint_for_bits(bits_to_pack) << bit_start
        mask_text = hex(mask)

        # Make comment
        comment_data = ["_"] * BYTE_SIZE
        for i in range(bit_start, bit_start + bits_to_pack):
            comment_data[i] = "#"

        # Format and add shift function
        cw.add_line(
            PACK_TEMPLATE.format(
                byte_index=starting_byte,
                func=PACK_SHIFT_RIGHT_FUNC if shift >= 0 else PACK_SHIFT_LEFT_FUNC,
                value=signal_raw_var_name,
                shift=abs(shift),
                mask=mask_text,
                bits_comment="".join(reversed(comment_data)),
            )
        )

        bit_start = 0  # After first iteration, further packings all start at bit 0
        packed_bits += bits_to_pack
        starting_byte += 1

    return str(cw)


def unpack_signal_code(signal: CanSignal, msg: CanMessage):
    """
    Generate code for unpacking a signal from raw msg payload.
    """
    starting_byte = signal.start_bit // BYTE_SIZE
    unpacked_bits = 0
    bit_start = (
        signal.start_bit - starting_byte * BYTE_SIZE
    )  # Bit position signal will begin on the first byte it occupies

    signal_val_var_name = f"{signal.name}_val"
    signal_raw_var_name = f"{signal.name}_raw"

    cw = CWriter()
    cw.add_comment(
        f"Unpack {signal.bits}-bit signal {signal.name} from payload (at bit {signal.start_bit} to bit {signal.start_bit + signal.bits})."
    )
    cw.add_line(f"uint32_t {signal_raw_var_name} = 0;")

    while unpacked_bits < signal.bits:
        # Bits to unpack this iteration is either how many bits can get from the current byte (8 - start)
        # or the remaining packed bits (length in bits - unpacked bits) (whichever is lower)
        bits_to_unpack = min(BYTE_SIZE - bit_start, signal.bits - unpacked_bits)

        # Positive is shifting to right, negative is shifting to left
        # Shift right by bit_start so LSB of signal lies at LSB of signal uint variable
        # Shift left by unpacked_bits to add new data after previously unpacked bits
        shift = bit_start - unpacked_bits

        # Make mask: 1 at each digit we're unpacking, 0 everywhere else
        mask = (
            max_uint_for_bits(bits_to_unpack) << bit_start
        )  # TODO: Confirm this works in Python like C
        mask_text = hex(mask)

        # Make comment
        comment_data = ["_"] * BYTE_SIZE
        for i in range(bit_start, bit_start + bits_to_unpack):
            comment_data[i] = "#"

        # Format shift function and append
        cw.add_line(
            UNPACK_TEMPLATE.format(
                byte_index=starting_byte,
                var_name=signal_raw_var_name,
                func=UNPACK_SHIFT_RIGHT_FUNC if shift >= 0 else UNPACK_SHIFT_LEFT_FUNC,
                value=f"in_data[{starting_byte}]",
                shift=abs(shift),
                mask=mask_text,
                bits_comment="".join(reversed(comment_data)),
            )
        )

        bit_start = 0  # After first iteration, further packings all start at bit 0
        unpacked_bits += bits_to_unpack
        starting_byte += 1

    # Decode raw payload bits
    scale_macro = CMacrosCfgs.SCALE.format(msg=msg.name, signal=signal.name)
    offset_macro = CMacrosCfgs.OFFSET.format(msg=msg.name, signal=signal.name)
    cw.add_line(
        f"const {signal.datatype()} {signal_val_var_name} = {DECODE_MACRO}({signal_raw_var_name}, {scale_macro}, {offset_macro}, {signal.representation()});"
    )

    # Assign variable in output ptr
    cw.add_line(f"out_msg->{signal.name}_value = {signal_val_var_name};")
    return str(cw)
