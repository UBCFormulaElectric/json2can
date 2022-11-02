from ...can_database import *
from ...utils import *
from .c_config import *
from .c_writer import *


class AppCanTxModule(CModule):
    def __init__(self, db: CanDatabase, node: str):
        self._db = db
        self._node = node
        self._functions = self._public_functions()

    def _public_functions(self) -> List[CFunc]:
        funcs = []

        # Init function
        init_func = CFunc(
            CFuncsCfg.APP_TX_INIT,
            "void",
            args=[],
            comment="Initialize TX signals to their starting values.",
        )
        init_func.body.add_line(
            f"memset(&{CVarsCfg.TX_TABLE}, 0, sizeof({CStructsCfg.TX_TABLE.format(node=self._node)}));"
        )
        for msg in self._db.tx_msgs_for_node(self._node):
            for signal in msg.signals:
                init_func.body.add_line(
                    f"{CFuncsCfg.APP_TX_SET_SIGNAL.format(msg=msg.name, signal=signal.name)}({CMacrosCfgs.START_VAL.format(msg=msg.name, signal=signal.name)});"
                )
        funcs.append(init_func)

        # Generate all setting functions for TX signals
        for msg in self._db.tx_msgs_for_node(self._node):
            for signal in msg.signals:
                func = CFunc(
                    CFuncsCfg.APP_TX_SET_SIGNAL.format(
                        msg=msg.name, signal=signal.name
                    ),
                    "void",
                    args=[
                        CVar("value", signal.datatype()),
                    ],
                    comment=f"Update value stored in TX table of signal {signal.name} in msg {msg.name}.",
                )

                func.body.add_code(
                    clamp_signal_code(
                        signal,
                        msg,
                        f"{CVarsCfg.TX_TABLE}.{CVarsCfg.MSG_STRUCT.format(msg=msg.name)}.{CVarsCfg.SIGNAL_VALUE.format(signal=signal.name)}",
                        "value",
                    )
                )
                funcs.append(func)

        # Generate getting funcs for TX signals
        for msg in self._db.tx_msgs_for_node(self._node):
            for signal in msg.signals:
                func = CFunc(
                    CFuncsCfg.APP_TX_GET_SIGNAL.format(
                        msg=msg.name, signal=signal.name
                    ),
                    signal.datatype(),
                    args=[],
                    comment=f"Return value from TX table of signal {signal.name} in msg {msg.name}.",
                )

                func.body.add_line(
                    f"return {CVarsCfg.TX_TABLE}.{CVarsCfg.MSG_STRUCT.format(msg=msg.name)}.{CVarsCfg.SIGNAL_VALUE.format(signal=signal.name)};"
                )
                funcs.append(func)

        # Generate getting funcs for TX messages
        for msg in self._db.tx_msgs_for_node(self._node):
            func = CFunc(
                CFuncsCfg.APP_TX_GET_MSG.format(msg=msg.name),
                f"const {CStructsCfg.MSG_STRUCT.format(msg=msg.name)}*",
                args=[],
                comment=f"Returns pointer to the struct of msg {msg.name} signals in the TX table.",
            )

            func.body.add_line(
                f"return &{CVarsCfg.TX_TABLE}.{CVarsCfg.MSG_STRUCT.format(msg=msg.name)};"
            )
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
        cw.add_include("<string.h>")
        cw.add_include('"App_CanUtils.h"')

        # TX table struct
        cw.add_line()
        cw.add_header_comment("Structs")
        cw.add_line()

        tx_table_struct = CStruct(
            CStructsCfg.TX_TABLE.format(node=self._node),
            comment=f"Struct for holding all messages transmitted by {self._node} (i.e. the TX table).",
        )
        for msg in self._db.tx_msgs_for_node(self._node):
            tx_table_struct.add_member(
                CVar(
                    CVarsCfg.MSG_STRUCT.format(msg=msg.name),
                    CStructsCfg.MSG_STRUCT.format(msg=msg.name),
                )
            )

        cw.add_struct(tx_table_struct)
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
        cw.add_header_comment("Function Definitions")
        cw.add_line()

        cw.add_include('"App_CanTx.h"')
        cw.add_line()

        # Private vars (TX table)
        cw.add_header_comment("Private Variables")
        cw.add_line()
        cw.add_var_declaration(
            CVar(CVarsCfg.TX_TABLE, CStructsCfg.TX_TABLE.format(node=self._node)),
            qualifier="static",
        )

        # Add function definitions
        cw.add_line()
        cw.add_header_comment("Function Definitions")
        cw.add_line()

        for func in self._functions:
            cw.add_function_definition(func)
            cw.add_line()

        return str(cw)
