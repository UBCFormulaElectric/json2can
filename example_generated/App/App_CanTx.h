/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* --------------------------------- Includes ----------------------------------- */

#include "App_CanUtils.h"

/* ---------------------------------- Macros ------------------------------------ */



/* ---------------------------------- Structs ----------------------------------- */



/* ----------------------------------- Enums ------------------------------------ */

/**
 * Struct for holding all message data transmitted by JSONCANTest.
 */
typedef struct
{
    JSONCANTest_VITALS_Signals JSONCANTest_VITALS_signals;
    JSONCANTest_NON_CRITICAL_ERRORS_Signals JSONCANTest_NON_CRITICAL_ERRORS_signals;
    JSONCANTest_AIR_SHUTDOWN_ERRORS_Signals JSONCANTest_AIR_SHUTDOWN_ERRORS_signals;
    JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Signals JSONCANTest_MOTOR_SHUTDOWN_ERRORS_signals;
    JSONCANTest_STATUS_Signals JSONCANTest_STATUS_signals;
} JSONCANTest_TxMsgs;

/* --------------------------- Function declarations ---------------------------- */

/**
 * @brief Initialize CAN Tx signals to their starting values.
 */ 
void App_CanTx_Init(void);

/**
 * @brief Update value store in the CAN Rx for signal HEARTBEAT in message JSONCANTest_VITALS.
 */ 
void App_CanTx_JSONCANTest_VITALS_HEARTBEAT_SetSignal(bool value);

/**
 * @brief Update value store in the CAN Rx for signal TIMESTAMP in message JSONCANTest_VITALS.
 */ 
void App_CanTx_JSONCANTest_VITALS_TIMESTAMP_SetSignal(uint32_t value);

/**
 * @brief Update value store in the CAN Rx for signal WATCHDOG_TIMEOUT in message JSONCANTest_NON_CRITICAL_ERRORS.
 */ 
void App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_SetSignal(bool value);

/**
 * @brief Update value store in the CAN Rx for signal BOARD_OVERTEMP in message JSONCANTest_NON_CRITICAL_ERRORS.
 */ 
void App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_SetSignal(bool value);

/**
 * @brief Update value store in the CAN Rx for signal BOARD_OVERVOLTAGE in message JSONCANTest_NON_CRITICAL_ERRORS.
 */ 
void App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_SetSignal(bool value);

/**
 * @brief Update value store in the CAN Rx for signal DUMMY_AIR_SHUTDOWN in message JSONCANTest_AIR_SHUTDOWN_ERRORS.
 */ 
void App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_SetSignal(bool value);

/**
 * @brief Update value store in the CAN Rx for signal DUMMY_MOTOR_SHUTDOWN in message JSONCANTest_MOTOR_SHUTDOWN_ERRORS.
 */ 
void App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_SetSignal(bool value);

/**
 * @brief Update value store in the CAN Rx for signal CONTACTORS_CLOSED in message JSONCANTest_STATUS.
 */ 
void App_CanTx_JSONCANTest_STATUS_CONTACTORS_CLOSED_SetSignal(AIR_STATE value);

/**
 * @brief Update value store in the CAN Rx for signal CURRENT in message JSONCANTest_STATUS.
 */ 
void App_CanTx_JSONCANTest_STATUS_CURRENT_SetSignal(float value);

/**
 * @brief Update value store in the CAN Rx for signal VOLTAGE in message JSONCANTest_STATUS.
 */ 
void App_CanTx_JSONCANTest_STATUS_VOLTAGE_SetSignal(float value);

/**
 * @brief Return signal value for signal HEARTBEAT in message JSONCANTest_VITALS.
 */ 
bool App_CanTx_JSONCANTest_VITALS_HEARTBEAT_GetSignal(void);

/**
 * @brief Return signal value for signal TIMESTAMP in message JSONCANTest_VITALS.
 */ 
uint32_t App_CanTx_JSONCANTest_VITALS_TIMESTAMP_GetSignal(void);

/**
 * @brief Return signal value for signal WATCHDOG_TIMEOUT in message JSONCANTest_NON_CRITICAL_ERRORS.
 */ 
bool App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_GetSignal(void);

/**
 * @brief Return signal value for signal BOARD_OVERTEMP in message JSONCANTest_NON_CRITICAL_ERRORS.
 */ 
bool App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_GetSignal(void);

/**
 * @brief Return signal value for signal BOARD_OVERVOLTAGE in message JSONCANTest_NON_CRITICAL_ERRORS.
 */ 
bool App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_GetSignal(void);

/**
 * @brief Return signal value for signal DUMMY_AIR_SHUTDOWN in message JSONCANTest_AIR_SHUTDOWN_ERRORS.
 */ 
bool App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_GetSignal(void);

/**
 * @brief Return signal value for signal DUMMY_MOTOR_SHUTDOWN in message JSONCANTest_MOTOR_SHUTDOWN_ERRORS.
 */ 
bool App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_GetSignal(void);

/**
 * @brief Return signal value for signal CONTACTORS_CLOSED in message JSONCANTest_STATUS.
 */ 
AIR_STATE App_CanTx_JSONCANTest_STATUS_CONTACTORS_CLOSED_GetSignal(void);

/**
 * @brief Return signal value for signal CURRENT in message JSONCANTest_STATUS.
 */ 
float App_CanTx_JSONCANTest_STATUS_CURRENT_GetSignal(void);

/**
 * @brief Return signal value for signal VOLTAGE in message JSONCANTest_STATUS.
 */ 
float App_CanTx_JSONCANTest_STATUS_VOLTAGE_GetSignal(void);

/**
 * @brief Return pointer to struct of signal values for message {msg.name}.
 */ 
const JSONCANTest_VITALS_Signals* App_CanTx_JSONCANTest_VITALS_GetMessageSignals(void);

/**
 * @brief Return pointer to struct of signal values for message {msg.name}.
 */ 
const JSONCANTest_NON_CRITICAL_ERRORS_Signals* App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_GetMessageSignals(void);

/**
 * @brief Return pointer to struct of signal values for message {msg.name}.
 */ 
const JSONCANTest_AIR_SHUTDOWN_ERRORS_Signals* App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_GetMessageSignals(void);

/**
 * @brief Return pointer to struct of signal values for message {msg.name}.
 */ 
const JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Signals* App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_GetMessageSignals(void);

/**
 * @brief Return pointer to struct of signal values for message {msg.name}.
 */ 
const JSONCANTest_STATUS_Signals* App_CanTx_JSONCANTest_STATUS_GetMessageSignals(void);
