/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off


/* ------------------------------- Includes ------------------------------- */

#include <string.h>
#include "App_CanRx.h"

/* -------------------------- Private Variables --------------------------- */

static JCT_RxMsgs rx_table;

/* ------------------------- Function Definitions ------------------------- */

void app_canRx_init()
{
    memset(&rx_table, 0, sizeof(JCT_RxMsgs));
    app_canRx_FSM_apps_pappsMappedPedalPercentage_updateValue(CANSIG_FSM_apps_pappsMappedPedalPercentage_START_VAL);
    app_canRx_FSM_apps_sappsMappedPedalPercentage_updateValue(CANSIG_FSM_apps_sappsMappedPedalPercentage_START_VAL);
    app_canRx_FSM_noncriticalErrors_pappsOutOfRange_updateValue(CANSIG_FSM_noncriticalErrors_pappsOutOfRange_START_VAL);
    app_canRx_FSM_noncriticalErrors_sappsOutOfRange_updateValue(CANSIG_FSM_noncriticalErrors_sappsOutOfRange_START_VAL);
    app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_updateValue(CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_START_VAL);
    app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_updateValue(CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_START_VAL);
    app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_updateValue(CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_START_VAL);
    app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_updateValue(CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_START_VAL);
    app_canRx_FSM_noncriticalErrors_watchdogFault_updateValue(CANSIG_FSM_noncriticalErrors_watchdogFault_START_VAL);
    app_canRx_FSM_noncriticalErrors_bspdFault_updateValue(CANSIG_FSM_noncriticalErrors_bspdFault_START_VAL);
    app_canRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_updateValue(CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_START_VAL);
    app_canRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_updateValue(CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_START_VAL);
    app_canRx_FSM_noncriticalErrors_flowRateOutOfRange_updateValue(CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_START_VAL);
    app_canRx_FSM_noncriticalErrors_steeringAngleOutOfRange_updateValue(CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_START_VAL);
    app_canRx_FSM_noncriticalErrors_brakePressureOutOfRange_updateValue(CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_START_VAL);
    app_canRx_FSM_noncriticalErrors_brakePressureSc_updateValue(CANSIG_FSM_noncriticalErrors_brakePressureSc_START_VAL);
    app_canRx_FSM_noncriticalErrors_brakePressureOc_updateValue(CANSIG_FSM_noncriticalErrors_brakePressureOc_START_VAL);
    app_canRx_FSM_noncriticalErrors_steeringWheelBroke_updateValue(CANSIG_FSM_noncriticalErrors_steeringWheelBroke_START_VAL);
}

void app_canRx_FSM_apps_pappsMappedPedalPercentage_updateValue(float value)
{
    const float tmp = value < CANSIG_FSM_apps_pappsMappedPedalPercentage_MIN ? CANSIG_FSM_apps_pappsMappedPedalPercentage_MIN : value;
    rx_table.FSM_apps_signals.pappsMappedPedalPercentage_value = tmp > CANSIG_FSM_apps_pappsMappedPedalPercentage_MAX ? CANSIG_FSM_apps_pappsMappedPedalPercentage_MAX : tmp;
}

void app_canRx_FSM_apps_sappsMappedPedalPercentage_updateValue(float value)
{
    const float tmp = value < CANSIG_FSM_apps_sappsMappedPedalPercentage_MIN ? CANSIG_FSM_apps_sappsMappedPedalPercentage_MIN : value;
    rx_table.FSM_apps_signals.sappsMappedPedalPercentage_value = tmp > CANSIG_FSM_apps_sappsMappedPedalPercentage_MAX ? CANSIG_FSM_apps_sappsMappedPedalPercentage_MAX : tmp;
}

void app_canRx_FSM_noncriticalErrors_pappsOutOfRange_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.pappsOutOfRange_value = value;
}

void app_canRx_FSM_noncriticalErrors_sappsOutOfRange_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.sappsOutOfRange_value = value;
}

void app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTask1Hz_value = value;
}

void app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTask1kHz_value = value;
}

void app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTaskCanRx_value = value;
}

void app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTaskCanTx_value = value;
}

void app_canRx_FSM_noncriticalErrors_watchdogFault_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.watchdogFault_value = value;
}

void app_canRx_FSM_noncriticalErrors_bspdFault_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.bspdFault_value = value;
}

void app_canRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_updateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.leftWheelSpeedOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_MAX : value;
}

void app_canRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_updateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.rightWheelSpeedOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_MAX : value;
}

void app_canRx_FSM_noncriticalErrors_flowRateOutOfRange_updateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.flowRateOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_MAX : value;
}

void app_canRx_FSM_noncriticalErrors_steeringAngleOutOfRange_updateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.steeringAngleOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_MAX : value;
}

void app_canRx_FSM_noncriticalErrors_brakePressureOutOfRange_updateValue(uint32_t value)
{
    rx_table.FSM_noncriticalErrors_signals.brakePressureOutOfRange_value = (value > CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_MAX) ? CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_MAX : value;
}

void app_canRx_FSM_noncriticalErrors_brakePressureSc_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.brakePressureSc_value = value;
}

void app_canRx_FSM_noncriticalErrors_brakePressureOc_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.brakePressureOc_value = value;
}

void app_canRx_FSM_noncriticalErrors_steeringWheelBroke_updateValue(bool value)
{
    rx_table.FSM_noncriticalErrors_signals.steeringWheelBroke_value = value;
}

float app_canRx_FSM_apps_pappsMappedPedalPercentage_getValue()
{
    return rx_table.FSM_apps_signals.pappsMappedPedalPercentage_value;
}

float app_canRx_FSM_apps_sappsMappedPedalPercentage_getValue()
{
    return rx_table.FSM_apps_signals.sappsMappedPedalPercentage_value;
}

bool app_canRx_FSM_noncriticalErrors_pappsOutOfRange_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.pappsOutOfRange_value;
}

bool app_canRx_FSM_noncriticalErrors_sappsOutOfRange_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.sappsOutOfRange_value;
}

bool app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTask1Hz_value;
}

bool app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTask1kHz_value;
}

bool app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTaskCanRx_value;
}

bool app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.stackWatermarkAboveThresholdTaskCanTx_value;
}

bool app_canRx_FSM_noncriticalErrors_watchdogFault_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.watchdogFault_value;
}

bool app_canRx_FSM_noncriticalErrors_bspdFault_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.bspdFault_value;
}

uint32_t app_canRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.leftWheelSpeedOutOfRange_value;
}

uint32_t app_canRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.rightWheelSpeedOutOfRange_value;
}

uint32_t app_canRx_FSM_noncriticalErrors_flowRateOutOfRange_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.flowRateOutOfRange_value;
}

uint32_t app_canRx_FSM_noncriticalErrors_steeringAngleOutOfRange_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.steeringAngleOutOfRange_value;
}

uint32_t app_canRx_FSM_noncriticalErrors_brakePressureOutOfRange_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.brakePressureOutOfRange_value;
}

bool app_canRx_FSM_noncriticalErrors_brakePressureSc_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.brakePressureSc_value;
}

bool app_canRx_FSM_noncriticalErrors_brakePressureOc_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.brakePressureOc_value;
}

bool app_canRx_FSM_noncriticalErrors_steeringWheelBroke_getValue()
{
    return rx_table.FSM_noncriticalErrors_signals.steeringWheelBroke_value;
}

