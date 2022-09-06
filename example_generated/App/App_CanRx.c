/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ---------------------------------- Includes ---------------------------------- */

#include <string.h>
#include "Io_CanRx.h"
#include "App_CanUtils.h"
#include "App_CanRx.h" 

/* ---------------------------- Struct declarations ----------------------------- */



/* --------------------------------- Variables ---------------------------------- */

JSONCANTest_RxMsgs rx_table;

/* ------------------------------ Static functions ------------------------------ */



/* ---------------------------- Function definitions ---------------------------- */

void App_CanRx_Init(void) 
{
    memset(&rx_table, 0, sizeof(JSONCANTest_RxMsgs));
    App_CanRx_FSM_APPS_Papps_Mapped_Pedal_Percentage_UpdateValue(CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_START_VAL);
    App_CanRx_FSM_APPS_Sapps_Mapped_Pedal_Percentage_UpdateValue(CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_START_VAL);
    App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_UpdateValue(CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_START_VAL);
}

void App_CanRx_FSM_APPS_Papps_Mapped_Pedal_Percentage_UpdateValue(float value) 
{
    const float tmp = value < CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_MIN ? CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_MIN : value;
    rx_table.FSM_APPS_signals.Papps_Mapped_Pedal_Percentage_value = tmp > CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_MAX ? CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_MAX : tmp;
}

void App_CanRx_FSM_APPS_Sapps_Mapped_Pedal_Percentage_UpdateValue(float value) 
{
    const float tmp = value < CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_MIN ? CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_MIN : value;
    rx_table.FSM_APPS_signals.Sapps_Mapped_Pedal_Percentage_value = tmp > CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_MAX ? CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_MAX : tmp;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.papps_out_of_range_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.sapps_out_of_range_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.WATCHDOG_TIMEOUT_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.BSPD_FAULT_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_UpdateValue(uint32_t value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.LEFT_WHEEL_SPEED_OUT_OF_RANGE_value = value > CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_MAX ? CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_UpdateValue(uint32_t value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.RIGHT_WHEEL_SPEED_OUT_OF_RANGE_value = value > CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_MAX ? CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_UpdateValue(uint32_t value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.FLOW_RATE_OUT_OF_RANGE_value = value > CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_MAX ? CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_UpdateValue(uint32_t value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.STEERING_ANGLE_OUT_OF_RANGE_value = value > CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_MAX ? CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_UpdateValue(uint32_t value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.BRAKE_PRESSURE_OUT_OF_RANGE_value = value > CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_MAX ? CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.BRAKE_PRESSURE_OPEN_SC_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.BRAKE_PRESSURE_OPEN_OC_value = value;
}

void App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_UpdateValue(bool value) 
{
    rx_table.FSM_NON_CRITICAL_ERRORS_signals.STEERING_WHEEL_BROKE_value = value;
}

float App_CanRx_FSM_APPS_Papps_Mapped_Pedal_Percentage_GetValue(void) 
{
    return rx_table.FSM_APPS_signals.Papps_Mapped_Pedal_Percentage_value;
}

float App_CanRx_FSM_APPS_Sapps_Mapped_Pedal_Percentage_GetValue(void) 
{
    return rx_table.FSM_APPS_signals.Sapps_Mapped_Pedal_Percentage_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.papps_out_of_range_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.sapps_out_of_range_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.WATCHDOG_TIMEOUT_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.BSPD_FAULT_value;
}

uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.LEFT_WHEEL_SPEED_OUT_OF_RANGE_value;
}

uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.RIGHT_WHEEL_SPEED_OUT_OF_RANGE_value;
}

uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.FLOW_RATE_OUT_OF_RANGE_value;
}

uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.STEERING_ANGLE_OUT_OF_RANGE_value;
}

uint32_t App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.BRAKE_PRESSURE_OUT_OF_RANGE_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.BRAKE_PRESSURE_OPEN_SC_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.BRAKE_PRESSURE_OPEN_OC_value;
}

bool App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_GetValue(void) 
{
    return rx_table.FSM_NON_CRITICAL_ERRORS_signals.STEERING_WHEEL_BROKE_value;
}
