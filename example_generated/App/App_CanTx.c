/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off

/* ------------------------- Function Definitions ------------------------- */

#include "App_CanTx.h"

/* -------------------------- Private Variables --------------------------- */

static JCT_TxMsgs tx_table;

/* ------------------------- Function Definitions ------------------------- */

void App_CanTx_Init()
{
    memset(&tx_table, 0, sizeof(JCT_TxMsgs));
    App_CanTx_JCT_vitals_heartbeat_Set(CANSIG_JCT_vitals_heartbeat_START_VAL);
    App_CanTx_JCT_vitals_timestamp_Set(CANSIG_JCT_vitals_timestamp_START_VAL);
    App_CanTx_JCT_noncriticalErrors_watchdogTimeout_Set(CANSIG_JCT_noncriticalErrors_watchdogTimeout_START_VAL);
    App_CanTx_JCT_noncriticalErrors_boardOvertemp_Set(CANSIG_JCT_noncriticalErrors_boardOvertemp_START_VAL);
    App_CanTx_JCT_noncriticalErrors_boardOvervoltage_Set(CANSIG_JCT_noncriticalErrors_boardOvervoltage_START_VAL);
    App_CanTx_JCT_AIRShutdownErrors_dummyAirShutdown_Set(CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_START_VAL);
    App_CanTx_JCT_motorShutdownErrors_dummyMotorShutdown_Set(CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_START_VAL);
    App_CanTx_JCT_status_contactorsClosed_Set(CANSIG_JCT_status_contactorsClosed_START_VAL);
    App_CanTx_JCT_status_current_Set(CANSIG_JCT_status_current_START_VAL);
    App_CanTx_JCT_status_voltage_Set(CANSIG_JCT_status_voltage_START_VAL);
    App_CanTx_JCT_status_unsigned_tester_Set(CANSIG_JCT_status_unsigned_tester_START_VAL);
    App_CanTx_JCT_AlertSet_JCT_AlertSet_Set(CANSIG_JCT_AlertSet_JCT_AlertSet_START_VAL);
    App_CanTx_JCT_AlertCleared_JCT_AlertCleared_Set(CANSIG_JCT_AlertCleared_JCT_AlertCleared_START_VAL);
}

void App_CanTx_JCT_vitals_heartbeat_Set(bool value)
{
    tx_table.JCT_vitals_signals.heartbeat_value = value;
}

void App_CanTx_JCT_vitals_timestamp_Set(uint32_t value)
{
    tx_table.JCT_vitals_signals.timestamp_value = value;
}

void App_CanTx_JCT_noncriticalErrors_watchdogTimeout_Set(bool value)
{
    tx_table.JCT_noncriticalErrors_signals.watchdogTimeout_value = value;
}

void App_CanTx_JCT_noncriticalErrors_boardOvertemp_Set(bool value)
{
    tx_table.JCT_noncriticalErrors_signals.boardOvertemp_value = value;
}

void App_CanTx_JCT_noncriticalErrors_boardOvervoltage_Set(bool value)
{
    tx_table.JCT_noncriticalErrors_signals.boardOvervoltage_value = value;
}

void App_CanTx_JCT_AIRShutdownErrors_dummyAirShutdown_Set(bool value)
{
    tx_table.JCT_AIRShutdownErrors_signals.dummyAirShutdown_value = value;
}

void App_CanTx_JCT_motorShutdownErrors_dummyMotorShutdown_Set(bool value)
{
    tx_table.JCT_motorShutdownErrors_signals.dummyMotorShutdown_value = value;
}

void App_CanTx_JCT_status_contactorsClosed_Set(AirState value)
{
    tx_table.JCT_status_signals.contactorsClosed_value = (value > CANSIG_JCT_status_contactorsClosed_MAX) ? CANSIG_JCT_status_contactorsClosed_MAX : value;
}

void App_CanTx_JCT_status_current_Set(float value)
{
    const float tmp = value < CANSIG_JCT_status_current_MIN ? CANSIG_JCT_status_current_MIN : value;
    tx_table.JCT_status_signals.current_value = tmp > CANSIG_JCT_status_current_MAX ? CANSIG_JCT_status_current_MAX : tmp;
}

void App_CanTx_JCT_status_voltage_Set(float value)
{
    const float tmp = value < CANSIG_JCT_status_voltage_MIN ? CANSIG_JCT_status_voltage_MIN : value;
    tx_table.JCT_status_signals.voltage_value = tmp > CANSIG_JCT_status_voltage_MAX ? CANSIG_JCT_status_voltage_MAX : tmp;
}

void App_CanTx_JCT_status_unsigned_tester_Set(int value)
{
    const int tmp = value < CANSIG_JCT_status_unsigned_tester_MIN ? CANSIG_JCT_status_unsigned_tester_MIN : value;
    tx_table.JCT_status_signals.unsigned_tester_value = tmp > CANSIG_JCT_status_unsigned_tester_MAX ? CANSIG_JCT_status_unsigned_tester_MAX : tmp;
}

void App_CanTx_JCT_AlertSet_JCT_AlertSet_Set(JCT_Alert value)
{
    tx_table.JCT_AlertSet_signals.JCT_AlertSet_value = (value > CANSIG_JCT_AlertSet_JCT_AlertSet_MAX) ? CANSIG_JCT_AlertSet_JCT_AlertSet_MAX : value;
}

void App_CanTx_JCT_AlertCleared_JCT_AlertCleared_Set(JCT_Alert value)
{
    tx_table.JCT_AlertCleared_signals.JCT_AlertCleared_value = (value > CANSIG_JCT_AlertCleared_JCT_AlertCleared_MAX) ? CANSIG_JCT_AlertCleared_JCT_AlertCleared_MAX : value;
}

bool App_CanTx_JCT_vitals_heartbeat_Get()
{
    return tx_table.JCT_vitals_signals.heartbeat_value;
}

uint32_t App_CanTx_JCT_vitals_timestamp_Get()
{
    return tx_table.JCT_vitals_signals.timestamp_value;
}

bool App_CanTx_JCT_noncriticalErrors_watchdogTimeout_Get()
{
    return tx_table.JCT_noncriticalErrors_signals.watchdogTimeout_value;
}

bool App_CanTx_JCT_noncriticalErrors_boardOvertemp_Get()
{
    return tx_table.JCT_noncriticalErrors_signals.boardOvertemp_value;
}

bool App_CanTx_JCT_noncriticalErrors_boardOvervoltage_Get()
{
    return tx_table.JCT_noncriticalErrors_signals.boardOvervoltage_value;
}

bool App_CanTx_JCT_AIRShutdownErrors_dummyAirShutdown_Get()
{
    return tx_table.JCT_AIRShutdownErrors_signals.dummyAirShutdown_value;
}

bool App_CanTx_JCT_motorShutdownErrors_dummyMotorShutdown_Get()
{
    return tx_table.JCT_motorShutdownErrors_signals.dummyMotorShutdown_value;
}

AirState App_CanTx_JCT_status_contactorsClosed_Get()
{
    return tx_table.JCT_status_signals.contactorsClosed_value;
}

float App_CanTx_JCT_status_current_Get()
{
    return tx_table.JCT_status_signals.current_value;
}

float App_CanTx_JCT_status_voltage_Get()
{
    return tx_table.JCT_status_signals.voltage_value;
}

int App_CanTx_JCT_status_unsigned_tester_Get()
{
    return tx_table.JCT_status_signals.unsigned_tester_value;
}

JCT_Alert App_CanTx_JCT_AlertSet_JCT_AlertSet_Get()
{
    return tx_table.JCT_AlertSet_signals.JCT_AlertSet_value;
}

JCT_Alert App_CanTx_JCT_AlertCleared_JCT_AlertCleared_Get()
{
    return tx_table.JCT_AlertCleared_signals.JCT_AlertCleared_value;
}

const JCT_vitals_Signals* App_CanTx_JCT_vitals_GetData()
{
    return &tx_table.JCT_vitals_signals;
}

const JCT_noncriticalErrors_Signals* App_CanTx_JCT_noncriticalErrors_GetData()
{
    return &tx_table.JCT_noncriticalErrors_signals;
}

const JCT_AIRShutdownErrors_Signals* App_CanTx_JCT_AIRShutdownErrors_GetData()
{
    return &tx_table.JCT_AIRShutdownErrors_signals;
}

const JCT_motorShutdownErrors_Signals* App_CanTx_JCT_motorShutdownErrors_GetData()
{
    return &tx_table.JCT_motorShutdownErrors_signals;
}

const JCT_status_Signals* App_CanTx_JCT_status_GetData()
{
    return &tx_table.JCT_status_signals;
}

const JCT_AlertSet_Signals* App_CanTx_JCT_AlertSet_GetData()
{
    return &tx_table.JCT_AlertSet_signals;
}

const JCT_AlertCleared_Signals* App_CanTx_JCT_AlertCleared_GetData()
{
    return &tx_table.JCT_AlertCleared_signals;
}

