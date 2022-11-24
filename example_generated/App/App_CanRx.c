/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off


/* ------------------------------- Includes ------------------------------- */

#include <string.h>
#include "App_CanRx.h"

/* -------------------------- Private Variables --------------------------- */

static JCT_RxMsgs rx_table;

/* ------------------------- Function Definitions ------------------------- */

void App_CanRx_Init()
{
    memset(&rx_table, 0, sizeof(JCT_RxMsgs));
    App_CanRx_FSM_apps_pappsMappedPedalPercentage_UpdateValue(CANSIG_FSM_apps_pappsMappedPedalPercentage_START_VAL);
    App_CanRx_FSM_apps_sappsMappedPedalPercentage_UpdateValue(CANSIG_FSM_apps_sappsMappedPedalPercentage_START_VAL);
    App_CanRx_FSM_noncriticalErrors_pappsOutOfRange_UpdateValue(CANSIG_FSM_noncriticalErrors_pappsOutOfRange_START_VAL);
    App_CanRx_FSM_noncriticalErrors_sappsOutOfRange_UpdateValue(CANSIG_FSM_noncriticalErrors_sappsOutOfRange_START_VAL);
    App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_UpdateValue(CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_START_VAL);
    App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_UpdateValue(CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_START_VAL);
    App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_UpdateValue(CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_START_VAL);
    App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_UpdateValue(CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_START_VAL);
    App_CanRx_FSM_noncriticalErrors_watchdogFault_UpdateValue(CANSIG_FSM_noncriticalErrors_watchdogFault_START_VAL);
    App_CanRx_FSM_noncriticalErrors_bspdFault_UpdateValue(CANSIG_FSM_noncriticalErrors_bspdFault_START_VAL);
    App_CanRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_UpdateValue(CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_START_VAL);
    App_CanRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_UpdateValue(CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_START_VAL);
    App_CanRx_FSM_noncriticalErrors_flowRateOutOfRange_UpdateValue(CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_START_VAL);
    App_CanRx_FSM_noncriticalErrors_steeringAngleOutOfRange_UpdateValue(CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_START_VAL);
    App_CanRx_FSM_noncriticalErrors_brakePressureOutOfRange_UpdateValue(CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_START_VAL);
    App_CanRx_FSM_noncriticalErrors_brakePressureSc_UpdateValue(CANSIG_FSM_noncriticalErrors_brakePressureSc_START_VAL);
    App_CanRx_FSM_noncriticalErrors_brakePressureOc_UpdateValue(CANSIG_FSM_noncriticalErrors_brakePressureOc_START_VAL);
    App_CanRx_FSM_noncriticalErrors_steeringWheelBroke_UpdateValue(CANSIG_FSM_noncriticalErrors_steeringWheelBroke_START_VAL);
}

void App_CanRx_FSM_apps_pappsMappedPedalPercentage_UpdateValue(float value)
{
    const float tmp = value < CANSIG_FSM_apps_pappsMappedPedalPercentage_MIN ? CANSIG_FSM_apps_pappsMappedPedalPercentage_MIN : value;
    rx_table.FSM_apps_signals.pappsMappedPedalPercentage_value = tmp > CANSIG_FSM_apps_pappsMappedPedalPercentage_MAX ? CANSIG_FSM_apps_pappsMappedPedalPercentage_MAX : tmp;
}

void App_CanRx_FSM_apps_sappsMappedPedalPercentage_UpdateValue(float value)
{
    const float tmp = value < CANSIG_FSM_apps_sappsMappedPedalPercentage_MIN ? CANSIG_FSM_apps_sappsMappedPedalPercentage_MIN : value;
    rx_table.FSM_apps_signals.sappsMappedPedalPercentage_value = tmp > CANSIG_FSM_apps_sappsMappedPedalPercentage_MAX ? CANSIG_FSM_apps_sappsMappedPedalPercentage_MAX : tmp;
}

void App_CanRx_FSM_noncriticalErrors_pappsOutOfRange_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.pappsOutOfRange_value = value;
}

void App_CanRx_FSM_noncriticalErrors_sappsOutOfRange_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.sappsOutOfRange_value = value;
}

void App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTask1Hz_value = value;
}

void App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTask1kHz_value = value;
}

void App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTaskCanRx_value = value;
}

void App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTaskCanTx_value = value;
}

void App_CanRx_FSM_noncriticalErrors_watchdogFault_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.watchdogFault_value = value;
}

void App_CanRx_FSM_noncriticalErrors_bspdFault_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.bspdFault_value = value;
}

void App_CanRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.leftWheelSpeedOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_MAX : value;
}

void App_CanRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.rightWheelSpeedOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_MAX : value;
}

void App_CanRx_FSM_noncriticalErrors_flowRateOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.flowRateOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_MAX : value;
}

void App_CanRx_FSM_noncriticalErrors_steeringAngleOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.steeringAngleOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_MAX : value;
}

void App_CanRx_FSM_noncriticalErrors_brakePressureOutOfRange_UpdateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.brakePressureOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_MAX : value;
}

void App_CanRx_FSM_noncriticalErrors_brakePressureSc_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.brakePressureSc_value = value;
}

void App_CanRx_FSM_noncriticalErrors_brakePressureOc_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.brakePressureOc_value = value;
}

void App_CanRx_FSM_noncriticalErrors_steeringWheelBroke_UpdateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.steeringWheelBroke_value = value;
}

float App_CanRx_FSM_apps_pappsMappedPedalPercentage_GetValue()
{
    return rx_table.FSM_apps_signals.pappsMappedPedalPercentage_value;
}

float App_CanRx_FSM_apps_sappsMappedPedalPercentage_GetValue()
{
    return rx_table.FSM_apps_signals.sappsMappedPedalPercentage_value;
}

bool App_CanRx_FSM_noncriticalErrors_pappsOutOfRange_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.pappsOutOfRange_value;
}

bool App_CanRx_FSM_noncriticalErrors_sappsOutOfRange_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.sappsOutOfRange_value;
}

bool App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTask1Hz_value;
}

bool App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTask1kHz_value;
}

bool App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTaskCanRx_value;
}

bool App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTaskCanTx_value;
}

bool App_CanRx_FSM_noncriticalErrors_watchdogFault_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.watchdogFault_value;
}

bool App_CanRx_FSM_noncriticalErrors_bspdFault_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.bspdFault_value;
}

uint32_t App_CanRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.leftWheelSpeedOutOfRange_value;
}

uint32_t App_CanRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.rightWheelSpeedOutOfRange_value;
}

uint32_t App_CanRx_FSM_noncriticalErrors_flowRateOutOfRange_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.flowRateOutOfRange_value;
}

uint32_t App_CanRx_FSM_noncriticalErrors_steeringAngleOutOfRange_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.steeringAngleOutOfRange_value;
}

uint32_t App_CanRx_FSM_noncriticalErrors_brakePressureOutOfRange_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.brakePressureOutOfRange_value;
}

bool App_CanRx_FSM_noncriticalErrors_brakePressureSc_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.brakePressureSc_value;
}

bool App_CanRx_FSM_noncriticalErrors_brakePressureOc_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.brakePressureOc_value;
}

bool App_CanRx_FSM_noncriticalErrors_steeringWheelBroke_GetValue()
{
    return rx_table.FSM_noncriticalErrors_signals.steeringWheelBroke_value;
}

