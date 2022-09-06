'''
Function and variable names for C coddegen.
'''


from enum import Enum


class TxFuncNames(str, Enum):
    ENQUEUE_PERIODIC_MSGS = 'Io_CanTx_Enqueue{freq}Messages'
    SEND = 'App_CanTx_{msg}_Send'
    SET_SIGNAL = 'App_CanTx_{msg}_{signal}_SetSignal'
    GET_SIGNAL = 'App_CanTx_{msg}_{signal}_GetSignal'
    APP_INIT = 'App_CanTx_Init'
    GET_MSG_SIGNALS = 'App_CanTx_{msg}_GetMessageSignals'


class RxFuncNames(str, Enum):
    UPDATE_RX_TABLE = 'Io_CanRx_UpdateRxTableWithMessage'
    FILTER_ID = 'Io_CanRx_FilterMessageId'
    UPDATE_SIGNAL = 'App_CanRx_{msg}_{signal}_UpdateValue'
    GET_SIGNAL =  'App_CanRx_{msg}_{signal}_GetValue'
    APP_INIT = 'App_CanRx_Init'


class UtilFuncNames(str, Enum):
    PACK = 'App_CanMsgs_{msg}_Pack',
    UNPACK = 'App_CanMsgs_{msg}_Unpack',
    PACK_LEFT = 'PackShiftLeft'
    PACK_RIGHT = 'PackShiftRight'
    UNPACK_LEFT = 'UnpackShiftLeft'
    UNPACK_RIGHT = 'UnpackShiftRight'
    ENCODE_UINT = 'Encode_Uint',
    ENCODE_INT = 'Encode_Int',
    ENCODE_FLOAT = 'Encode_Float',
    DECODE_UINT = 'Decode_Uint',
    DECODE_INT = 'Decode_Int',
    DECODE_FLOAT = 'Decode_Float',


class VarNames(str, Enum): 
    TX_TABLE = 'tx_table'
    RX_TABLE = 'rx_table'
    MSG_STRUCT = '{msg}_signals'
    SIGNAL_VALUE = '{signal}_value'


class StructNames(str, Enum):
    TX_TABLE = '{node}_TxMsgs'
    RX_TABLE = '{node}_RxMsgs'
    MSG_STRUCT = '{msg}_Signals'


class AttributeMacros(str, Enum):
    ID = 'CANMSG_{msg}_ID',
    CYCLE_TIME = 'CANMSG_{msg}_CYCLE_TIME_MS',
    BYTES = 'CANMSG_{msg}_LENGTH',
    START_VAL = 'CANSIG_{msg}_{signal}_START_VAL',
    SCALE = 'CANSIG_{msg}_{signal}_SCALE',
    OFFSET = 'CANSIG_{msg}_{signal}_OFFSET',
    MIN = 'CANSIG_{msg}_{signal}_MIN',
    MAX = 'CANSIG_{msg}_{signal}_MAX',
