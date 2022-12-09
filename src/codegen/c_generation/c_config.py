"""
Function and variable names for C coddegen.
"""
from enum import Enum
from ...utils import *


class CFuncsConfig(str, Enum):
    # Io Tx
    IO_TX_ENQUEUE_PERIODIC = "Io_CanTx_Enqueue{freq}Msgs"
    IO_TX_SEND = "App_CanTx_{msg}_Send{mode}"

    # App Tx
    APP_TX_INIT = "App_CanTx_Init"
    APP_TX_SET_SIGNAL = "App_CanTx_{msg}_{signal}_Set"
    APP_TX_GET_SIGNAL = "App_CanTx_{msg}_{signal}_Get"
    APP_TX_GET_MSG = "App_CanTx_{msg}_GetData"

    # Io Rx
    IO_RX_UPDATE_TABLE = "Io_CanRx_UpdateRxTableWithMessage"
    IO_RX_FILTER_ID = "Io_CanRx_FilterMessageId"

    # App Rx
    APP_RX_INIT = "App_CanRx_Init"
    APP_RX_SET_SIGNAL = "App_CanRx_{msg}_{signal}_UpdateValue"
    APP_RX_GET_SIGNAL = "App_CanRx_{msg}_{signal}_GetValue"

    # Utils
    UTILS_PACK = ("App_CanUtils_{msg}_Pack",)
    UTILS_UNPACK = ("App_CanUtils_{msg}_Unpack",)


class CVarsConfig(str, Enum):
    TX_TABLE = "tx_table"
    RX_TABLE = "rx_table"
    MSG_STRUCT = "{msg}_signals"
    SIGNAL_VALUE = "{signal}_value"


class CStructsConfig(str, Enum):
    TX_TABLE = "{node}_TxMsgs"
    RX_TABLE = "{node}_RxMsgs"
    MSG_STRUCT = "{msg}_Signals"


class CMacrosConfig(str, Enum):
    @classmethod
    def id(cls, msg):
        return f"CAN_MSG_{pascal_to_screaming_snake_case(msg)}_ID"

    @classmethod
    def cycle_time(cls, msg):
        return f"CAN_MSG_{pascal_to_screaming_snake_case(msg)}_CYCLE_TIME_MS"

    @classmethod
    def bytes(cls, msg):
        return f"CAN_MSG_{pascal_to_screaming_snake_case(msg)}_BYTES"

    @classmethod
    def start_val(cls, msg, signal):
        return f"CANSIG_{pascal_to_screaming_snake_case(msg)}_{pascal_to_screaming_snake_case(signal)}_START_VAL"

    @classmethod
    def scale(cls, msg, signal):
        return f"CANSIG_{pascal_to_screaming_snake_case(msg)}_{pascal_to_screaming_snake_case(signal)}_SCALE"

    @classmethod
    def offset(cls, msg, signal):
        return f"CANSIG_{pascal_to_screaming_snake_case(msg)}_{pascal_to_screaming_snake_case(signal)}_OFFSET"

    @classmethod
    def min(cls, msg, signal):
        return f"CANSIG_{pascal_to_screaming_snake_case(msg)}_{pascal_to_screaming_snake_case(signal)}_MIN"

    @classmethod
    def max(cls, msg, signal):
        return f"CANSIG_{pascal_to_screaming_snake_case(msg)}_{pascal_to_screaming_snake_case(signal)}_MAX"
