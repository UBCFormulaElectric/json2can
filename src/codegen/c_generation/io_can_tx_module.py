from lzma import is_check_supported
from statistics import mode
from ...can_database import *
from ...utils import *
from .c_config import *
from .c_writer import *

MSG_CYCLE_TIME_2_FREQ = {
    10: "100Hz",
    100: "10Hz",
    1000: "1Hz",
}


class IoCanTxModule(CModule):
    def __init__(self, db: CanDatabase, node: str):
        self._db = db
        self._node = node
        self._public_functions, self._static_functions = self._functions()

    def _functions(self) -> List[CFunc]:
        public_funcs = []
        static_funcs = []

        # Generate periodic message sending functions
        for cycle_time, freq in MSG_CYCLE_TIME_2_FREQ.items():
            func = CFunc(
                CFuncsCfg.IO_TX_ENQUEUE_PERIODIC.format(freq=freq),
                "void",
                args=[],
                comment=f"Enqeue periodic CAN msgs of period {cycle_time}ms.",
            )

            for msg in self._db.tx_msgs_for_node(self._node):
                if msg.is_periodic() and msg.cycle_time == cycle_time:
                    func.body.add_line(
                        f"{CFuncsCfg.IO_TX_SEND.format(msg=msg.name, mode=freq)}();"
                    )

            public_funcs.append(func)

        # Generate msg sending functions
        for msg in self._db.tx_msgs_for_node(self._node):
            mode = (
                MSG_CYCLE_TIME_2_FREQ[msg.cycle_time]
                if msg.is_periodic()
                else "Aperiodic"
            )
            func = CFunc(
                CFuncsCfg.IO_TX_SEND.format(msg=msg.name, mode=mode),
                "void",
                args=[],
                comment=f'Pack and send the {"aperiodic" if not msg.is_periodic() else ""} TX msg {msg.name}.',
            )

            # Prepare header
            func.body.add_comment("Prepare msg header")
            func.body.add_var_declaration(CVar("tx_msg", "struct CanMsg"))
            func.body.add_line(
                f"tx_msg.std_id = {CMacrosCfgs.ID.format(msg=msg.name)};"
            )
            func.body.add_line(
                f"tx_msg.dlc = {CMacrosCfgs.BYTES.format(msg=msg.name)};"
            )
            func.body.add_line()

            # Pack payload
            func.body.add_comment(
                "Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)"
            )
            func.body.add_line("vPortEnterCritical();")
            func.body.add_line(
                f"{CFuncsCfg.UTILS_PACK.format(msg=msg.name)}({CFuncsCfg.APP_TX_GET_MSG.format(msg=msg.name)}(), tx_msg.data);"
            )
            func.body.add_line("vPortExitCritical();")
            func.body.add_line()

            # Push to TX FIFO
            func.body.add_comment("Enqueue msg in TX FIFO")
            func.body.add_line("Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);")

            # If aperiodic, make function public. Otherwise it can be static.
            if not msg.is_periodic():
                public_funcs.append(func)
            else:
                func.qualifier = "static"
                static_funcs.append(func)

        return public_funcs, static_funcs

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

        # Add public function prototypes
        cw.add_line()
        cw.add_header_comment("Function Prototypes")
        cw.add_line()

        for func in self._public_functions:
            cw.add_function_prototype(func)
            cw.add_line()

        return str(cw)

    def source(self):
        cw = CWriter()
        cw.add_preamble()
        cw.add_line()

        # Add includes
        cw.add_header_comment("Includes")
        cw.add_line()
        cw.add_include('"Io_CanTx.h"')
        cw.add_include("<string.h>")
        cw.add_include("<FreeRTOS.h>")
        cw.add_include("<portmacro.h>")
        cw.add_include('"Io_SharedCanMsg.h"')
        cw.add_include('"Io_SharedCan.h"')
        cw.add_include('"App_CanTx.h"')
        cw.add_include('"App_CanUtils.h"')

        # Add static function prototypes
        cw.add_line()
        cw.add_header_comment("Static Function Prototypes")
        cw.add_line()

        for func in self._static_functions:
            cw.add_function_prototype(func)
            cw.add_line()

        # Add public function definitions
        cw.add_header_comment("Public Function Definitions")
        cw.add_line()

        for func in self._public_functions:
            cw.add_function_definition(func)
            cw.add_line()

        # Add static function definitions
        cw.add_header_comment("Static Function Definitions")
        cw.add_line()

        for func in self._static_functions:
            cw.add_function_definition(func)
            cw.add_line()

        return str(cw)
