from ...can_database import *
from .shared_c_generation import *
from .c_config import *


task_cycle_times = [
    (1, '1kHz'),
    (10, '100Hz'),
    (100, '10Hz'),
    (1000, '1Hz'),
]

enqueue_periodic_msg_body = '''\
    // Prepare CAN message header for message {msg_name}
    struct CanMsg tx_msg;
    tx_msg.std_id = {msg_id};
    tx_msg.dlc = {length};

    // Prepare CAN message payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    {packing_function}({get_msg_signals_function}(), tx_msg.data);
    vPortExitCritical();

    // Send to back of TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);'''


class IoCanTxFileGenerator(EmbeddedFileGenerator):
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)

        self._init_functions()

    def _init_functions(self):          
        for cycle_time, cycle_freq in task_cycle_times:
            msg_senders = []
            for msg in self._db.messages_transmitted_by_node(self._node):
                if msg.is_periodic and msg.cycle_time == cycle_time:
                    msg_senders.append(f'''\
    {TxFuncNames.SEND.format(msg=msg.name)}();''')

            self._functions.append(
                CFunction(
                    signature=f'void {TxFuncNames.ENQUEUE_PERIODIC_MSGS.format(freq=cycle_freq)}(const uint32_t current_ms)',
                    body='\n'.join(msg_senders),
                    comment=f'Enqueue periodic CAN TX messages of rate {cycle_freq} (cycle time = {cycle_time}ms).',
                )
            )

        for msg in self._db.messages_transmitted_by_node(self._node):
            self._functions.append(
                CFunction(
                    signature=f'void {TxFuncNames.SEND.format(msg=msg.name)}(void)',
                    body=enqueue_periodic_msg_body.format(
                        msg_id=AttributeMacros.ID.format(msg=msg.name),
                        msg_name=msg.name,
                        length=AttributeMacros.BYTES.format(msg=msg.name),
                        packing_function=UtilFuncNames.PACK.format(msg=msg.name),
                        get_msg_signals_function=TxFuncNames.GET_MSG_SIGNALS.format(msg=msg.name)
                    ),
                    comment='Pack and send the TX message {name}.'
                )
            )


class IoCanTxHeaderGenerator(IoCanTxFileGenerator):
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()

    def _init_includes(self):
        header_names = ['<stdint.h>']
        self._includes= [CHeaderInclude(name) for name in header_names]


class IoCanTxSourceGenerator(IoCanTxFileGenerator):
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()

    def _init_includes(self):
        header_names = [
            '<string.h>', 
            '<FreeRTOS.h>',
            '<portmacro.h>',
            '"Io_CanTx.h"', 
            '"Io_SharedCanMsg.h"',
            '"Io_SharedCan.h"',
            '"App_CanUtils.h"', 
            '"App_CanTx.h"'
        ]
        self._includes = [CHeaderInclude(name) for name in header_names]


class AppCanTxFileGenerator(EmbeddedFileGenerator):
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_functions()

    def _init_functions(self):
        # Init signal values
        signal_initializers = []
        for msg in self._db.messages_transmitted_by_node(self._node):
            for signal in msg.signals:
                signal_initializers.append(f'''\
    {TxFuncNames.SET_SIGNAL.format(msg=msg.name, signal=signal.name)}({AttributeMacros.START_VAL.format(msg=msg.name, signal=signal.name)});''')

        self._functions.append(CFunction(
            signature=f'void {TxFuncNames.APP_INIT}(void)',
            body=f'''\
    memset(&{VarNames.TX_TABLE}, 0, sizeof({StructNames.TX_TABLE.format(node=self._node)}));\n''' + '\n'.join(signal_initializers),
            comment='Initialize CAN Tx signals to their starting values.',
        ))

        # Functions for setting signal values
        for msg in self._db.messages_transmitted_by_node(self._node):
            for signal in msg.signals:
                set_body = ''
                if signal.datatype() == CanSignalDatatype.BOOL:
                    set_body = '''\
    {tx_data_var}.{msg_signals_var}.{signal_value_var} = value;'''
                else:
                    set_body = '''\
    {tx_data_var}.{msg_signals_var}.{signal_value_var} = {clamp_func_name}(value);'''

                self._functions.append(
                    CFunction(
                        signature=f'void {TxFuncNames.SET_SIGNAL.format(msg=msg.name, signal=signal.name)}({signal.datatype()} value)',
                        body=set_body.format(
                            tx_data_var=VarNames.TX_TABLE,
                            msg_signals_var=VarNames.MSG_STRUCT.format(msg=msg.name),
                            signal_value_var=VarNames.SIGNAL_VALUE.format(signal=signal.name),
                            clamp_func_name=UtilFuncNames.CLAMP.format(msg=msg.name, signal=signal.name),
                        ),
                        comment=f'Update value store in the CAN Rx for signal {signal.name} in message {msg.name}.'
                    )
                )

        # Functions for getting signal values
        for msg in self._db.messages_transmitted_by_node(self._node):
            for signal in msg.signals:
                self._functions.append(CFunction(
                    signature=f'{signal.datatype()} {TxFuncNames.GET_SIGNAL.format(msg=msg.name, signal=signal.name)}(void)',
                    body=f'''\
    return {VarNames.TX_TABLE}.{VarNames.MSG_STRUCT.format(msg=msg.name)}.{VarNames.SIGNAL_VALUE.format(signal=signal.name)};''',
                    comment=f'Return signal value for signal {signal.name} in message {msg.name}.'
                ))

        # Functions for getting pointers to structs holding message signal data
        for msg in self._db.messages_transmitted_by_node(self._node):
            self._functions.append(CFunction(
                signature=f'const {StructNames.MSG_STRUCT.format(msg=msg.name)}* {TxFuncNames.GET_MSG_SIGNALS.format(msg=msg.name)}(void)',
                body=f'''\
    return &{VarNames.TX_TABLE}.{VarNames.MSG_STRUCT.format(msg=msg.name)};''',
                comment='Return pointer to struct of signal values for message {msg.name}.'
            ))


class AppCanTxHeaderGenerator(AppCanTxFileGenerator):
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)          
        self._init_includes()
        self._init_structs()

    def _init_includes(self):
        header_names = ['"App_CanUtils.h"']
        self._includes= [CHeaderInclude(name) for name in header_names]

    def _init_structs(self):
        can_tx_data_struct_members = []
        for msg in self._db.messages_transmitted_by_node(self._node):
            can_tx_data_struct_members.append(CVarDeclaration(
                type=StructNames.MSG_STRUCT.format(msg=msg.name),
                name=VarNames.MSG_STRUCT.format(msg=msg.name),
            ))

        self._structs.append(CStruct(
            name=StructNames.TX_TABLE.format(node=self._node),
            members=can_tx_data_struct_members,
            comment=f'Struct for holding all message data transmitted by {self._node}.'
        ))


class AppCanTxSourceGenerator(AppCanTxFileGenerator):
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(db=db, node=node, output_dir=output_dir)
        self._init_includes()
        self._init_variables()

    def _init_includes(self):
        header_names = ['<string.h>','"App_CanTx.h"']
        self._includes= [CHeaderInclude(name) for name in header_names]

    def _init_variables(self):
        self._variables.append(
            CVarDeclaration(
                type=StructNames.TX_TABLE.format(node=self._node),
                name=VarNames.TX_TABLE,
            )
        )