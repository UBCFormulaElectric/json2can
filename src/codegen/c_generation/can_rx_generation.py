'''
Codegen for .h and .c files for CAN RX app and IO layers.
'''


from ...can_database import *
from .shared_c_generation import *
from .c_config import *


IO_CANRX_UPDATE_TABLE_WITH_MSG_BODY = '''\
    switch (message->std_id)
    {{
{cases}
        default:
        {{
            break;
        }}
    }}'''

IO_CANRX_UPDATE_TABLE_WITH_MSG_BODY_UPDATE_TABLE = '''\
        case {msg_id}:
        {{
            {msg_struct} out_msg;
            {unpacking_function}(message->data, &out_msg);
            
{signal_setters}
            break;
        }}'''

IO_CANRX_FILTER_MSG_ID_BODY = '''\
    bool isFound = false;
    switch (std_id)
    {{
{cases}
        {{
            isFound = true;
            break;
        }}
        default:
        {{
            break;
        }}
    }}
    return isFound;'''

IO_CANRX_FILTER_MSG_ID_FILTER_MSG = '''\
        case {frame_id_macro}:'''


class IoCanRxFileGenerator(EmbeddedFileGenerator):
    '''
    Generates code shared by .h and .c for CAN RX IO layer.
    '''
    
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_functions()

    def _init_functions(self):
        # Dequeue CAN message function
        self._functions.append(
            CFunction(
                signature=f'void {RxFuncNames.UPDATE_RX_TABLE}(struct CanMsg* message)',
                body=IO_CANRX_UPDATE_TABLE_WITH_MSG_BODY.format(
                    cases='\n'.join(IO_CANRX_UPDATE_TABLE_WITH_MSG_BODY_UPDATE_TABLE.format(
                        msg_id=AttributeMacros.ID.format(msg=msg.name),
                        msg_struct=StructNames.MSG_STRUCT.format(msg=msg.name),
                        unpacking_function=UtilFuncNames.UNPACK.format(msg=msg.name),
                        signal_setters='\n'.join(f'''\
            {RxFuncNames.UPDATE_SIGNAL.format(msg=msg.name, signal=signal.name)}(out_msg.{VarNames.SIGNAL_VALUE.format(signal=signal.name)});''' for signal in msg.signals))
                    for msg in self._db.messages_received_by_node(self._node))
                ),
                comment='Unpack a received message and update the CAN RX table.'
            )
        )

        # Filter message ID: Does this node care about a certain message?
        self._functions.append(
            CFunction(
                signature=f'bool {RxFuncNames.FILTER_ID}(uint32_t std_id)',
                body=IO_CANRX_FILTER_MSG_ID_BODY.format(
                    cases='\n'.join(IO_CANRX_FILTER_MSG_ID_FILTER_MSG.format(
                            frame_id_macro = AttributeMacros.ID.format(msg=msg.name)
                        ) for msg in self._db.messages_received_by_node(self._node)
                    ),
                ),
                comment='Returns true if JSONCANTest listens to the given message ID.'
            )
        )


class IoCanRxHeaderGenerator(IoCanRxFileGenerator):
    '''
    Generates .h specific code for CAN RX IO layer.
    '''

    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()
    
    def _init_includes(self):
        header_names = [
            '<stdint.h>',
            '<stdbool.h>', 
            '"Io_SharedCanMsg.h"',
        ]
        self._includes = [CHeaderInclude(name) for name in header_names]


class IoCanRxSourceGenerator(IoCanRxFileGenerator):
    '''
    Generates .h specific code for CAN RX IO layer.
    '''

    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()

    def _init_includes(self):
        header_names = [
            '"Io_CanRx.h"',
            '"App_CanUtils.h"',
            '"App_CanRx.h"'
        ]
        self._includes = [CHeaderInclude(name) for name in header_names]


class AppCanRxFileGenerator(EmbeddedFileGenerator):
    '''
    Generates code shared by .h and .c for CAN RX app layer.
    '''

    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_functions()

    def _init_functions(self):
        # Init signal values
        signal_initializers = []
        for msg in self._db.messages_received_by_node(self._node):
            for signal in msg.signals:
                signal_initializers.append(f'''\
    {RxFuncNames.UPDATE_SIGNAL.format(msg=msg.name, signal=signal.name)}({AttributeMacros.START_VAL.format(msg=msg.name, signal=signal.name)});''')

        self._functions.append(CFunction(
            signature=f'void {RxFuncNames.APP_INIT}(void)',
            body=f'''\
    memset(&{VarNames.RX_TABLE}, 0, sizeof({StructNames.RX_TABLE.format(node=self._node)}));\n''' + '\n'.join(signal_initializers),
            comment='Initialize CAN Rx signals to their starting values.',
        ))

        # Updaters for received messages
        for msg in self._db.messages_received_by_node(self._node):
            for signal in msg.signals:
                self._functions.append(
                    CFunction(
                        signature=f'void {RxFuncNames.UPDATE_SIGNAL.format(msg=msg.name, signal=signal.name)}({signal.datatype()} value)',
                        body=signal_clamping_code(
                            signal=signal, 
                            msg=msg,
                            dest_name=f'{VarNames.RX_TABLE}.{VarNames.MSG_STRUCT.format(msg=msg.name)}.{VarNames.SIGNAL_VALUE.format(signal=signal.name)}',
                            src_name='value'
                        ),
                        comment=f'Update value store in the CAN RX table for signal {signal.name} in message {msg.name}.'
                    )
                )

        # Getters for received messages
        for msg in self._db.messages_received_by_node(self._node):
            for signal in msg.signals:
                self._functions.append(
                    CFunction(
                        signature=f'{signal.datatype()} {RxFuncNames.GET_SIGNAL.format(msg=msg.name, signal=signal.name)}(void)',
                        body=f'''\
    return {VarNames.RX_TABLE}.{VarNames.MSG_STRUCT.format(msg=msg.name)}.{VarNames.SIGNAL_VALUE.format(signal=signal.name)};''',
                        comment=f'Return value store in the CAN Rx table for signal {signal.name} in message {msg.name}.'
                    )
                )


class AppCanRxHeaderGenerator(AppCanRxFileGenerator):
    '''
    Generates .h specific code for CAN RX app layer.
    '''

    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()
        self._init_structs()

    def _init_includes(self):
        header_names = ['<stdint.h>']
        self._includes = [CHeaderInclude(name) for name in header_names]

    def _init_structs(self):
        can_rx_data_struct_members = []
        for msg in self._db.messages_received_by_node(self._node):
            can_rx_data_struct_members.extend([CVarDeclaration(
                type=StructNames.MSG_STRUCT.format(msg=msg.name),
                name=VarNames.MSG_STRUCT.format(msg=msg.name),
            )])

        self._structs.append(CStruct(
            name=StructNames.RX_TABLE.format(node=self._node),
            members=can_rx_data_struct_members,
            comment=f'Struct for holding all messages received by {self._node} (i.e. the CAN RX table).'
        ))


class AppCanRxSourceGenerator(AppCanRxFileGenerator):
    '''
    Generates .c specific code for CAN RX app layer.
    '''

    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()
        self._init_variables()

    def _init_includes(self):
        header_names = [
            '<string.h>', 
            '"Io_CanRx.h"',
            '"App_CanUtils.h"',
            '"App_CanRx.h"'
        ]
        self._includes = [CHeaderInclude(name) for name in header_names]

    def _init_variables(self):
        self._variables = [
            CVarDeclaration(
                type=StructNames.RX_TABLE.format(node=self._node),
                name=VarNames.RX_TABLE,
            )
        ]
