/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off


/* ------------------------------- Includes ------------------------------- */

#include <math.h>
#include <string.h>
#include "App_CanRx.h"

/* -------------------------- Private Variables --------------------------- */

static JCT_RxMsgs rx_table;

/* ------------------------- Function Definitions ------------------------- */

void App_CanRx_Init()
{
    memset(&rx_table, 0, sizeof(JCT_RxMsgs));
    App_CanRx_FsmApps_PappsMappedPedalPercentage_UpdateValue(CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_START_VAL);
    App_CanRx_FsmApps_SappsMappedPedalPercentage_UpdateValue(CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_START_VAL);
    App_CanRx_FsmWarnings_PappsOutOfRange_UpdateValue(CANSIG_FSM_WARNINGS_PAPPS_OUT_OF_RANGE_START_VAL);
    App_CanRx_FsmWarnings_SappsOutOfRange_UpdateValue(CANSIG_FSM_WARNINGS_SAPPS_OUT_OF_RANGE_START_VAL);
    App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1Hz_UpdateValue(CANSIG_FSM_WARNINGS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1_HZ_START_VAL);
    App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1kHz_UpdateValue(CANSIG_FSM_WARNINGS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1K_HZ_START_VAL);
    App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanRx_UpdateValue(CANSIG_FSM_WARNINGS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_RX_START_VAL);
    App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanTx_UpdateValue(CANSIG_FSM_WARNINGS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_TX_START_VAL);
    App_CanRx_FsmWarnings_WatchdogFault_UpdateValue(CANSIG_FSM_WARNINGS_WATCHDOG_FAULT_START_VAL);
    App_CanRx_FsmWarnings_BspdFault_UpdateValue(CANSIG_FSM_WARNINGS_BSPD_FAULT_START_VAL);
    App_CanRx_FsmWarnings_LeftWheelSpeedOutOfRange_UpdateValue(CANSIG_FSM_WARNINGS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_START_VAL);
    App_CanRx_FsmWarnings_RightWheelSpeedOutOfRange_UpdateValue(CANSIG_FSM_WARNINGS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_START_VAL);
    App_CanRx_FsmWarnings_FlowRateOutOfRange_UpdateValue(CANSIG_FSM_WARNINGS_FLOW_RATE_OUT_OF_RANGE_START_VAL);
    App_CanRx_FsmWarnings_SteeringAngleOutOfRange_UpdateValue(CANSIG_FSM_WARNINGS_STEERING_ANGLE_OUT_OF_RANGE_START_VAL);
    App_CanRx_FsmWarnings_BrakePressureOutOfRange_UpdateValue(CANSIG_FSM_WARNINGS_BRAKE_PRESSURE_OUT_OF_RANGE_START_VAL);
    App_CanRx_FsmWarnings_BrakePressureSc_UpdateValue(CANSIG_FSM_WARNINGS_BRAKE_PRESSURE_SC_START_VAL);
    App_CanRx_FsmWarnings_BrakePressureOc_UpdateValue(CANSIG_FSM_WARNINGS_BRAKE_PRESSURE_OC_START_VAL);
    App_CanRx_FsmWarnings_SteeringWheelBroke_UpdateValue(CANSIG_FSM_WARNINGS_STEERING_WHEEL_BROKE_START_VAL);
}

void App_CanRx_FsmApps_PappsMappedPedalPercentage_UpdateValue(float value)
{
    if (value == NAN)
    {
        return;
    }
    
    const float tmp = value < CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_MIN ? CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_MIN : value;
    rx_table.FsmApps_signals.PappsMappedPedalPercentage_value = tmp > CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_MAX ? CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_MAX : tmp;
}

void App_CanRx_FsmApps_SappsMappedPedalPercentage_UpdateValue(float value)
{
    if (value == NAN)
    {
        return;
    }
    
    const float tmp = value < CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_MIN ? CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_MIN : value;
    rx_table.FsmApps_signals.SappsMappedPedalPercentage_value = tmp > CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_MAX ? CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_MAX : tmp;
}

void App_CanRx_FsmWarnings_PappsOutOfRange_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.PappsOutOfRange_value = value;
}

void App_CanRx_FsmWarnings_SappsOutOfRange_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.SappsOutOfRange_value = value;
}

void App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1Hz_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.StackWatermarkAboveThresholdTask1Hz_value = value;
}

void App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1kHz_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.StackWatermarkAboveThresholdTask1kHz_value = value;
}

void App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanRx_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.StackWatermarkAboveThresholdTaskCanRx_value = value;
}

void App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanTx_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.StackWatermarkAboveThresholdTaskCanTx_value = value;
}

void App_CanRx_FsmWarnings_WatchdogFault_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.WatchdogFault_value = value;
}

void App_CanRx_FsmWarnings_BspdFault_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.BspdFault_value = value;
}

void App_CanRx_FsmWarnings_LeftWheelSpeedOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FsmWarnings_signals.LeftWheelSpeedOutOfRange_value = (value > CANSIG_FSM_WARNINGS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_MAX) ? CANSIG_FSM_WARNINGS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FsmWarnings_RightWheelSpeedOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FsmWarnings_signals.RightWheelSpeedOutOfRange_value = (value > CANSIG_FSM_WARNINGS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_MAX) ? CANSIG_FSM_WARNINGS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FsmWarnings_FlowRateOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FsmWarnings_signals.FlowRateOutOfRange_value = (value > CANSIG_FSM_WARNINGS_FLOW_RATE_OUT_OF_RANGE_MAX) ? CANSIG_FSM_WARNINGS_FLOW_RATE_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FsmWarnings_SteeringAngleOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FsmWarnings_signals.SteeringAngleOutOfRange_value = (value > CANSIG_FSM_WARNINGS_STEERING_ANGLE_OUT_OF_RANGE_MAX) ? CANSIG_FSM_WARNINGS_STEERING_ANGLE_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FsmWarnings_BrakePressureOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FsmWarnings_signals.BrakePressureOutOfRange_value = (value > CANSIG_FSM_WARNINGS_BRAKE_PRESSURE_OUT_OF_RANGE_MAX) ? CANSIG_FSM_WARNINGS_BRAKE_PRESSURE_OUT_OF_RANGE_MAX : value;
}

void App_CanRx_FsmWarnings_BrakePressureSc_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.BrakePressureSc_value = value;
}

void App_CanRx_FsmWarnings_BrakePressureOc_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.BrakePressureOc_value = value;
}

void App_CanRx_FsmWarnings_SteeringWheelBroke_UpdateValue(bool value)
{
    rx_table.FsmWarnings_signals.SteeringWheelBroke_value = value;
}

float App_CanRx_FsmApps_PappsMappedPedalPercentage_GetValue()
{
    return rx_table.FsmApps_signals.PappsMappedPedalPercentage_value;
}

float App_CanRx_FsmApps_SappsMappedPedalPercentage_GetValue()
{
    return rx_table.FsmApps_signals.SappsMappedPedalPercentage_value;
}

bool App_CanRx_FsmWarnings_PappsOutOfRange_GetValue()
{
    return rx_table.FsmWarnings_signals.PappsOutOfRange_value;
}

bool App_CanRx_FsmWarnings_SappsOutOfRange_GetValue()
{
    return rx_table.FsmWarnings_signals.SappsOutOfRange_value;
}

bool App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1Hz_GetValue()
{
    return rx_table.FsmWarnings_signals.StackWatermarkAboveThresholdTask1Hz_value;
}

bool App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1kHz_GetValue()
{
    return rx_table.FsmWarnings_signals.StackWatermarkAboveThresholdTask1kHz_value;
}

bool App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanRx_GetValue()
{
    return rx_table.FsmWarnings_signals.StackWatermarkAboveThresholdTaskCanRx_value;
}

bool App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanTx_GetValue()
{
    return rx_table.FsmWarnings_signals.StackWatermarkAboveThresholdTaskCanTx_value;
}

bool App_CanRx_FsmWarnings_WatchdogFault_GetValue()
{
    return rx_table.FsmWarnings_signals.WatchdogFault_value;
}

bool App_CanRx_FsmWarnings_BspdFault_GetValue()
{
    return rx_table.FsmWarnings_signals.BspdFault_value;
}

uint32_t App_CanRx_FsmWarnings_LeftWheelSpeedOutOfRange_GetValue()
{
    return rx_table.FsmWarnings_signals.LeftWheelSpeedOutOfRange_value;
}

uint32_t App_CanRx_FsmWarnings_RightWheelSpeedOutOfRange_GetValue()
{
    return rx_table.FsmWarnings_signals.RightWheelSpeedOutOfRange_value;
}

uint32_t App_CanRx_FsmWarnings_FlowRateOutOfRange_GetValue()
{
    return rx_table.FsmWarnings_signals.FlowRateOutOfRange_value;
}

uint32_t App_CanRx_FsmWarnings_SteeringAngleOutOfRange_GetValue()
{
    return rx_table.FsmWarnings_signals.SteeringAngleOutOfRange_value;
}

uint32_t App_CanRx_FsmWarnings_BrakePressureOutOfRange_GetValue()
{
    return rx_table.FsmWarnings_signals.BrakePressureOutOfRange_value;
}

bool App_CanRx_FsmWarnings_BrakePressureSc_GetValue()
{
    return rx_table.FsmWarnings_signals.BrakePressureSc_value;
}

bool App_CanRx_FsmWarnings_BrakePressureOc_GetValue()
{
    return rx_table.FsmWarnings_signals.BrakePressureOc_value;
}

bool App_CanRx_FsmWarnings_SteeringWheelBroke_GetValue()
{
    return rx_table.FsmWarnings_signals.SteeringWheelBroke_value;
}

