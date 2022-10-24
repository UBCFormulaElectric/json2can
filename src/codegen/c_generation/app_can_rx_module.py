from ...can_database import *
from ...utils import *
from .c_config import *
from .c_writer import *

class AppCanRxModule(CModule):
    def __init__(self, db: CanDatabase, node: str):
        self._db = db
        self._node = node
        self._functions = self._public_functions()

    def _public_functions(self) -> List[CFunc]:
        funcs = []

        # Init function
        init_func = CFunc(CFuncsCfg.APP_RX_INIT, "void", args=[], comment='Initialize RX signals to their starting values.')
        init_func.body.add_line(f"memset(&{CVarsCfg.RX_TABLE}, 0, sizeof({CStructsCfg.RX_TABLE.format(node=self._node)}));")
        for msg in self._db.rx_msgs_for_node(self._node):
            for signal in msg.signals:
                init_func.body.add_line(f"{CFuncsCfg.APP_RX_SET_SIGNAL.format(msg=msg.name, signal=signal.name)}({CMacrosCfgs.START_VAL.format(msg=msg.name, signal=signal.name)});")
        funcs.append(init_func)

        # Generate functions for updating RX signals
        for msg in self._db.rx_msgs_for_node(self._node):
            for signal in msg.signals:
                func = CFunc(CFuncsCfg.APP_RX_SET_SIGNAL.format(msg=msg.name, signal=signal.name), "void", args=[
                    CVar("value", signal.datatype_c()),
                ], comment=f'Update value stored in RX table of signal {signal.name} in msg {msg.name}.')

                func.body.add_code(clamp_signal_code(
                    signal, 
                    msg, 
                    f'{CVarsCfg.RX_TABLE}.{CVarsCfg.MSG_STRUCT.format(msg=msg.name)}.{CVarsCfg.SIGNAL_VALUE.format(signal=signal.name)}', 
                    "value"
                ))
                funcs.append(func)

        # Generate functions for getting RX signals
        for msg in self._db.rx_msgs_for_node(self._node):
            for signal in msg.signals:
                func = CFunc(CFuncsCfg.APP_RX_GET_SIGNAL.format(msg=msg.name, signal=signal.name), signal.datatype_c(), 
                    args=[], comment=f'Return value from RX table of signal {signal.name} in msg {msg.name}.')

                func.body.add_line(f"return {CVarsCfg.RX_TABLE}.{CVarsCfg.MSG_STRUCT.format(msg=msg.name)}.{CVarsCfg.SIGNAL_VALUE.format(signal=signal.name)};")
                funcs.append(func)

        return funcs
    
    def header(self):
        cw = CWriter()
        cw.add_preamble()
        cw.add_line()
        cw.add_line("#pragma once")

        # Add includes
        cw.add_line()
        cw.add_header_comment("Includes")
        cw.add_line()
        cw.add_include('"App_CanUtils.h"')

        # RX table struct
        cw.add_line()
        cw.add_header_comment("Structs")
        cw.add_line()

        rx_table_struct = CStruct(
            CStructsCfg.RX_TABLE.format(node=self._node), 
            comment=f'Struct for holding all messages received by {self._node} (i.e. the RX table).'
        )
        for msg in self._db.rx_msgs_for_node(self._node):
            rx_table_struct.add_member(CVar(CVarsCfg.MSG_STRUCT.format(msg=msg.name), CStructsCfg.MSG_STRUCT.format(msg=msg.name)))

        cw.add_struct(rx_table_struct)
        cw.add_line()

        # Add function prototypes
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

        # Add includes
        cw.add_line()
        cw.add_header_comment("Includes")
        cw.add_line()
        cw.add_include('<string.h>')
        cw.add_include('"App_CanRx.h"')

        # Private vars (RX table)
        cw.add_line()
        cw.add_header_comment("Private Variables")
        cw.add_line()
        cw.add_var_declaration(CVar(CVarsCfg.RX_TABLE, CStructsCfg.RX_TABLE.format(node=self._node)), qualifier="static")

        # Add function definitions
        cw.add_line()
        cw.add_header_comment("Function Definitions")
        cw.add_line()

        for func in self._functions:
            cw.add_function_definition(func)
            cw.add_line()

        return str(cw)
