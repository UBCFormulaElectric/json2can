/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ---------------------------------- Includes ---------------------------------- */

#include <string.h>
#include "App_CanTx.h" 

/* ---------------------------- Struct declarations ----------------------------- */



/* --------------------------------- Variables ---------------------------------- */

JSONCANTest_TxMsgs tx_table;

/* ------------------------------ Static functions ------------------------------ */



/* ---------------------------- Function definitions ---------------------------- */

void App_CanTx_Init(void) 
{
    memset(&tx_table, 0, sizeof(JSONCANTest_TxMsgs));
    App_CanTx_JSONCANTest_VITALS_HEARTBEAT_SetSignal(CANSIG_JSONCANTest_VITALS_HEARTBEAT_START_VAL);
    App_CanTx_JSONCANTest_VITALS_TIMESTAMP_SetSignal(CANSIG_JSONCANTest_VITALS_TIMESTAMP_START_VAL);
    App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_SetSignal(CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_START_VAL);
    App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_SetSignal(CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_START_VAL);
    App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_SetSignal(CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_START_VAL);
    App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_SetSignal(CANSIG_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_START_VAL);
    App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_SetSignal(CANSIG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_START_VAL);
    App_CanTx_JSONCANTest_STATUS_CONTACTORS_CLOSED_SetSignal(CANSIG_JSONCANTest_STATUS_CONTACTORS_CLOSED_START_VAL);
    App_CanTx_JSONCANTest_STATUS_CURRENT_SetSignal(CANSIG_JSONCANTest_STATUS_CURRENT_START_VAL);
    App_CanTx_JSONCANTest_STATUS_VOLTAGE_SetSignal(CANSIG_JSONCANTest_STATUS_VOLTAGE_START_VAL);
}

void App_CanTx_JSONCANTest_VITALS_HEARTBEAT_SetSignal(bool value) 
{
    tx_table.JSONCANTest_VITALS_signals.HEARTBEAT_value = value;
}

void App_CanTx_JSONCANTest_VITALS_TIMESTAMP_SetSignal(uint32_t value) 
{
    tx_table.JSONCANTest_VITALS_signals.TIMESTAMP_value = App_CanMsgs_JSONCANTest_VITALS_TIMESTAMP_Clamp(value);
}

void App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_SetSignal(bool value) 
{
    tx_table.JSONCANTest_NON_CRITICAL_ERRORS_signals.WATCHDOG_TIMEOUT_value = value;
}

void App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_SetSignal(bool value) 
{
    tx_table.JSONCANTest_NON_CRITICAL_ERRORS_signals.BOARD_OVERTEMP_value = value;
}

void App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_SetSignal(bool value) 
{
    tx_table.JSONCANTest_NON_CRITICAL_ERRORS_signals.BOARD_OVERVOLTAGE_value = value;
}

void App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_SetSignal(bool value) 
{
    tx_table.JSONCANTest_AIR_SHUTDOWN_ERRORS_signals.DUMMY_AIR_SHUTDOWN_value = value;
}

void App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_SetSignal(bool value) 
{
    tx_table.JSONCANTest_MOTOR_SHUTDOWN_ERRORS_signals.DUMMY_MOTOR_SHUTDOWN_value = value;
}

void App_CanTx_JSONCANTest_STATUS_CONTACTORS_CLOSED_SetSignal(AIR_STATE value) 
{
    tx_table.JSONCANTest_STATUS_signals.CONTACTORS_CLOSED_value = App_CanMsgs_JSONCANTest_STATUS_CONTACTORS_CLOSED_Clamp(value);
}

void App_CanTx_JSONCANTest_STATUS_CURRENT_SetSignal(float value) 
{
    tx_table.JSONCANTest_STATUS_signals.CURRENT_value = App_CanMsgs_JSONCANTest_STATUS_CURRENT_Clamp(value);
}

void App_CanTx_JSONCANTest_STATUS_VOLTAGE_SetSignal(float value) 
{
    tx_table.JSONCANTest_STATUS_signals.VOLTAGE_value = App_CanMsgs_JSONCANTest_STATUS_VOLTAGE_Clamp(value);
}

bool App_CanTx_JSONCANTest_VITALS_HEARTBEAT_GetSignal(void) 
{
    return tx_table.JSONCANTest_VITALS_signals.HEARTBEAT_value;
}

uint32_t App_CanTx_JSONCANTest_VITALS_TIMESTAMP_GetSignal(void) 
{
    return tx_table.JSONCANTest_VITALS_signals.TIMESTAMP_value;
}

bool App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_GetSignal(void) 
{
    return tx_table.JSONCANTest_NON_CRITICAL_ERRORS_signals.WATCHDOG_TIMEOUT_value;
}

bool App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_GetSignal(void) 
{
    return tx_table.JSONCANTest_NON_CRITICAL_ERRORS_signals.BOARD_OVERTEMP_value;
}

bool App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_GetSignal(void) 
{
    return tx_table.JSONCANTest_NON_CRITICAL_ERRORS_signals.BOARD_OVERVOLTAGE_value;
}

bool App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_GetSignal(void) 
{
    return tx_table.JSONCANTest_AIR_SHUTDOWN_ERRORS_signals.DUMMY_AIR_SHUTDOWN_value;
}

bool App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_GetSignal(void) 
{
    return tx_table.JSONCANTest_MOTOR_SHUTDOWN_ERRORS_signals.DUMMY_MOTOR_SHUTDOWN_value;
}

AIR_STATE App_CanTx_JSONCANTest_STATUS_CONTACTORS_CLOSED_GetSignal(void) 
{
    return tx_table.JSONCANTest_STATUS_signals.CONTACTORS_CLOSED_value;
}

float App_CanTx_JSONCANTest_STATUS_CURRENT_GetSignal(void) 
{
    return tx_table.JSONCANTest_STATUS_signals.CURRENT_value;
}

float App_CanTx_JSONCANTest_STATUS_VOLTAGE_GetSignal(void) 
{
    return tx_table.JSONCANTest_STATUS_signals.VOLTAGE_value;
}

const JSONCANTest_VITALS_Signals* App_CanTx_JSONCANTest_VITALS_GetMessageSignals(void) 
{
    return &tx_table.JSONCANTest_VITALS_signals;
}

const JSONCANTest_NON_CRITICAL_ERRORS_Signals* App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_GetMessageSignals(void) 
{
    return &tx_table.JSONCANTest_NON_CRITICAL_ERRORS_signals;
}

const JSONCANTest_AIR_SHUTDOWN_ERRORS_Signals* App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_GetMessageSignals(void) 
{
    return &tx_table.JSONCANTest_AIR_SHUTDOWN_ERRORS_signals;
}

const JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Signals* App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_GetMessageSignals(void) 
{
    return &tx_table.JSONCANTest_MOTOR_SHUTDOWN_ERRORS_signals;
}

const JSONCANTest_STATUS_Signals* App_CanTx_JSONCANTest_STATUS_GetMessageSignals(void) 
{
    return &tx_table.JSONCANTest_STATUS_signals;
}
