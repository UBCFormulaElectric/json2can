/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* --------------------------------- Includes ----------------------------------- */

#include <stdint.h>

/* ---------------------------------- Macros ------------------------------------ */



/* ---------------------------------- Structs ----------------------------------- */



/* ----------------------------------- Enums ------------------------------------ */

/**
 * Struct for holding all message data received by JSONCANTest (i.e. the CAN table).
 */
typedef struct
{
    FSM_APPS_Signals FSM_APPS_signals;
    FSM_NON_CRITICAL_ERRORS_Signals FSM_NON_CRITICAL_ERRORS_signals;
} JSONCANTest_RxMsgs;

/* --------------------------- Function declarations ---------------------------- */

/**
 * @brief Initialize CAN Rx signals to their starting values.
 */ 
void App_CanRx_Init(void);

/**
 * @brief Update value store in the CAN Rx for signal Papps_Mapped_Pedal_Percentage in message FSM_APPS.
 */ 
void App_CanRx_FSM_APPS_Papps_Mapped_Pedal_Percentage_UpdateValue(float value);

/**
 * @brief Update value store in the CAN Rx for signal Sapps_Mapped_Pedal_Percentage in message FSM_APPS.
 */ 
void App_CanRx_FSM_APPS_Sapps_Mapped_Pedal_Percentage_UpdateValue(float value);

/**
 * @brief Update value store in the CAN Rx for signal papps_out_of_range in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal sapps_out_of_range in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal WATCHDOG_TIMEOUT in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal BSPD_FAULT in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal LEFT_WHEEL_SPEED_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_UpdateValue(uint32_t value);

/**
 * @brief Update value store in the CAN Rx for signal RIGHT_WHEEL_SPEED_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_UpdateValue(uint32_t value);

/**
 * @brief Update value store in the CAN Rx for signal FLOW_RATE_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_UpdateValue(uint32_t value);

/**
 * @brief Update value store in the CAN Rx for signal STEERING_ANGLE_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_UpdateValue(uint32_t value);

/**
 * @brief Update value store in the CAN Rx for signal BRAKE_PRESSURE_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_UpdateValue(uint32_t value);

/**
 * @brief Update value store in the CAN Rx for signal BRAKE_PRESSURE_OPEN_SC in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal BRAKE_PRESSURE_OPEN_OC in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_UpdateValue(bool value);

/**
 * @brief Update value store in the CAN Rx for signal STEERING_WHEEL_BROKE in message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_UpdateValue(bool value);

/**
 * @brief Return value store in the CAN Rx table for signal Papps_Mapped_Pedal_Percentage in message FSM_APPS.
 */ 
float App_CanRx_FSM_APPS_Papps_Mapped_Pedal_Percentage_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal Sapps_Mapped_Pedal_Percentage in message FSM_APPS.
 */ 
float App_CanRx_FSM_APPS_Sapps_Mapped_Pedal_Percentage_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal papps_out_of_range in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal sapps_out_of_range in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal WATCHDOG_TIMEOUT in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal BSPD_FAULT in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal LEFT_WHEEL_SPEED_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal RIGHT_WHEEL_SPEED_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal FLOW_RATE_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal STEERING_ANGLE_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal BRAKE_PRESSURE_OUT_OF_RANGE in message FSM_NON_CRITICAL_ERRORS.
 */ 
uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal BRAKE_PRESSURE_OPEN_SC in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal BRAKE_PRESSURE_OPEN_OC in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_GetValue(void);

/**
 * @brief Return value store in the CAN Rx table for signal STEERING_WHEEL_BROKE in message FSM_NON_CRITICAL_ERRORS.
 */ 
bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_GetValue(void);
