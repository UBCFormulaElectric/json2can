'''
Function and variable names for C coddegen.
'''
from enum import Enum


class CFuncsCfg(str, Enum):
    # Io Tx
    IO_TX_ENQUEUE_PERIODIC = 'io_canTx_enqueue{freq}Msgs'
    IO_TX_SEND = 'app_canTx_{msg}_send{mode}'

    # App Tx
    APP_TX_INIT = 'app_canTx_init'
    APP_TX_SET_SIGNAL = 'app_canTx_{msg}_{signal}_set'
    APP_TX_GET_SIGNAL = 'app_canTx_{msg}_{signal}_get'
    APP_TX_GET_MSG = 'app_canTx_{msg}_getData'

    # Io Rx
    IO_RX_UPDATE_TABLE = 'Io_CanRx_UpdateRxTableWithMessage'
    IO_RX_FILTER_ID = 'Io_CanRx_FilterMessageId'

    # App Rx
    APP_RX_INIT = 'app_canRx_init'
    APP_RX_SET_SIGNAL = 'app_canRx_{msg}_{signal}_updateValue'
    APP_RX_GET_SIGNAL =  'app_canRx_{msg}_{signal}_getValue'

    # Utils
    UTILS_PACK = 'app_canUtils_{msg}_pack',
    UTILS_UNPACK = 'app_canUtils_{msg}_unpack',


class CVarsCfg(str, Enum): 
    TX_TABLE = 'tx_table'
    RX_TABLE = 'rx_table'
    MSG_STRUCT = '{msg}_signals'
    SIGNAL_VALUE = '{signal}_value'


class CStructsCfg(str, Enum):
    TX_TABLE = '{node}_TxMsgs'
    RX_TABLE = '{node}_RxMsgs'
    MSG_STRUCT = '{msg}_Signals'


class CMacrosCfgs(str, Enum):
    ID = 'CANMSG_{msg}_ID',
    CYCLE_TIME = 'CANMSG_{msg}_CYCLE_TIME_MS',
    BYTES = 'CANMSG_{msg}_DLC',
    START_VAL = 'CANSIG_{msg}_{signal}_START_VAL',
    SCALE = 'CANSIG_{msg}_{signal}_SCALE',
    OFFSET = 'CANSIG_{msg}_{signal}_OFFSET',
    MIN = 'CANSIG_{msg}_{signal}_MIN',
    MAX = 'CANSIG_{msg}_{signal}_MAX',
