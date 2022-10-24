/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ------------------------- Function Definitions ------------------------- */

#include "App_CanTx.h"

/* -------------------------- Private Variables --------------------------- */

static JCT_TxMsgs tx_table;

/* ------------------------- Function Definitions ------------------------- */

void App_CanRx_Init()
{
    memset(&tx_table, 0, sizeof(JCT_TxMsgs));
    app_canTx_JCT_vitals_heartbeat_set(CANSIG_JCT_vitals_heartbeat_START_VAL);
    app_canTx_JCT_vitals_timestamp_set(CANSIG_JCT_vitals_timestamp_START_VAL);
    app_canTx_JCT_noncriticalErrors_watchdogTimeout_set(CANSIG_JCT_noncriticalErrors_watchdogTimeout_START_VAL);
    app_canTx_JCT_noncriticalErrors_boardOvertemp_set(CANSIG_JCT_noncriticalErrors_boardOvertemp_START_VAL);
    app_canTx_JCT_noncriticalErrors_boardOvervoltage_set(CANSIG_JCT_noncriticalErrors_boardOvervoltage_START_VAL);
    app_canTx_JCT_AIRShutdownErrors_dummyAirShutdown_set(CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_START_VAL);
    app_canTx_JCT_motorShutdownErrors_dummyMotorShutdown_set(CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_START_VAL);
    app_canTx_JCT_status_contactorsClosed_set(CANSIG_JCT_status_contactorsClosed_START_VAL);
    app_canTx_JCT_status_current_set(CANSIG_JCT_status_current_START_VAL);
    app_canTx_JCT_status_voltage_set(CANSIG_JCT_status_voltage_START_VAL);
}

void app_canTx_JCT_vitals_heartbeat_set(bool value)
{
    tx_table.JCT_vitals_signals.heartbeat_value = value;
}

void app_canTx_JCT_vitals_timestamp_set(uint32_t value)
{
    tx_table.JCT_vitals_signals.timestamp_value = value;
}

void app_canTx_JCT_noncriticalErrors_watchdogTimeout_set(bool value)
{
    tx_table.JCT_noncriticalErrors_signals.watchdogTimeout_value = value;
}

void app_canTx_JCT_noncriticalErrors_boardOvertemp_set(bool value)
{
    tx_table.JCT_noncriticalErrors_signals.boardOvertemp_value = value;
}

void app_canTx_JCT_noncriticalErrors_boardOvervoltage_set(bool value)
{
    tx_table.JCT_noncriticalErrors_signals.boardOvervoltage_value = value;
}

void app_canTx_JCT_AIRShutdownErrors_dummyAirShutdown_set(bool value)
{
    tx_table.JCT_AIRShutdownErrors_signals.dummyAirShutdown_value = value;
}

void app_canTx_JCT_motorShutdownErrors_dummyMotorShutdown_set(bool value)
{
    tx_table.JCT_motorShutdownErrors_signals.dummyMotorShutdown_value = value;
}

void app_canTx_JCT_status_contactorsClosed_set(AirState value)
{
    tx_table.JCT_status_signals.contactorsClosed_value = (value > CANSIG_JCT_status_contactorsClosed_MAX) ? CANSIG_JCT_status_contactorsClosed_MAX : value;
}

void app_canTx_JCT_status_current_set(float value)
{
    const float tmp = value < CANSIG_JCT_status_current_MIN ? CANSIG_JCT_status_current_MIN : value;
    tx_table.JCT_status_signals.current_value = tmp > CANSIG_JCT_status_current_MAX ? CANSIG_JCT_status_current_MAX : tmp;
}

void app_canTx_JCT_status_voltage_set(float value)
{
    const float tmp = value < CANSIG_JCT_status_voltage_MIN ? CANSIG_JCT_status_voltage_MIN : value;
    tx_table.JCT_status_signals.voltage_value = tmp > CANSIG_JCT_status_voltage_MAX ? CANSIG_JCT_status_voltage_MAX : tmp;
}

bool App_CanRx_JCT_vitals_heartbeat_GetValue()
{
    return tx_table.JCT_vitals_signals.heartbeat_value;
}

uint32_t App_CanRx_JCT_vitals_timestamp_GetValue()
{
    return tx_table.JCT_vitals_signals.timestamp_value;
}

bool App_CanRx_JCT_noncriticalErrors_watchdogTimeout_GetValue()
{
    return tx_table.JCT_noncriticalErrors_signals.watchdogTimeout_value;
}

bool App_CanRx_JCT_noncriticalErrors_boardOvertemp_GetValue()
{
    return tx_table.JCT_noncriticalErrors_signals.boardOvertemp_value;
}

bool App_CanRx_JCT_noncriticalErrors_boardOvervoltage_GetValue()
{
    return tx_table.JCT_noncriticalErrors_signals.boardOvervoltage_value;
}

bool App_CanRx_JCT_AIRShutdownErrors_dummyAirShutdown_GetValue()
{
    return tx_table.JCT_AIRShutdownErrors_signals.dummyAirShutdown_value;
}

bool App_CanRx_JCT_motorShutdownErrors_dummyMotorShutdown_GetValue()
{
    return tx_table.JCT_motorShutdownErrors_signals.dummyMotorShutdown_value;
}

AirState App_CanRx_JCT_status_contactorsClosed_GetValue()
{
    return tx_table.JCT_status_signals.contactorsClosed_value;
}

float App_CanRx_JCT_status_current_GetValue()
{
    return tx_table.JCT_status_signals.current_value;
}

float App_CanRx_JCT_status_voltage_GetValue()
{
    return tx_table.JCT_status_signals.voltage_value;
}

const JCT_vitals_Signals* app_canTx_JCT_vitals_getData()
{
    return &tx_table.JCT_vitals_signals;
}

const JCT_vitals_Signals* app_canTx_JCT_vitals_getData()
{
    return &tx_table.JCT_vitals_signals;
}

const JCT_noncriticalErrors_Signals* app_canTx_JCT_noncriticalErrors_getData()
{
    return &tx_table.JCT_noncriticalErrors_signals;
}

const JCT_noncriticalErrors_Signals* app_canTx_JCT_noncriticalErrors_getData()
{
    return &tx_table.JCT_noncriticalErrors_signals;
}

const JCT_noncriticalErrors_Signals* app_canTx_JCT_noncriticalErrors_getData()
{
    return &tx_table.JCT_noncriticalErrors_signals;
}

const JCT_AIRShutdownErrors_Signals* app_canTx_JCT_AIRShutdownErrors_getData()
{
    return &tx_table.JCT_AIRShutdownErrors_signals;
}

const JCT_motorShutdownErrors_Signals* app_canTx_JCT_motorShutdownErrors_getData()
{
    return &tx_table.JCT_motorShutdownErrors_signals;
}

const JCT_status_Signals* app_canTx_JCT_status_getData()
{
    return &tx_table.JCT_status_signals;
}

const JCT_status_Signals* app_canTx_JCT_status_getData()
{
    return &tx_table.JCT_status_signals;
}

const JCT_status_Signals* app_canTx_JCT_status_getData()
{
    return &tx_table.JCT_status_signals;
}

