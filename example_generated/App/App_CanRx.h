/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* ------------------------------- Includes ------------------------------- */

#include "App_CanUtils.h"

/* ------------------------------- Structs -------------------------------- */

/**
 * Struct for holding all messages received by JCT (i.e. the RX table).
 */
typedef struct
{
    FSM_apps_Signals FSM_apps_signals;
    FSM_noncriticalErrors_Signals FSM_noncriticalErrors_signals;
} JCT_RxMsgs;


/* ------------------------- Function Prototypes -------------------------- */

/**
 * Initialize RX signals to their starting values.
 */
void app_canRx_init();

/**
 * Update value stored in RX table of signal pappsMappedPedalPercentage in msg FSM_apps.
 */
void app_canRx_FSM_apps_pappsMappedPedalPercentage_updateValue(float value);

/**
 * Update value stored in RX table of signal sappsMappedPedalPercentage in msg FSM_apps.
 */
void app_canRx_FSM_apps_sappsMappedPedalPercentage_updateValue(float value);

/**
 * Update value stored in RX table of signal pappsOutOfRange in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_pappsOutOfRange_updateValue(bool value);

/**
 * Update value stored in RX table of signal sappsOutOfRange in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_sappsOutOfRange_updateValue(bool value);

/**
 * Update value stored in RX table of signal stackWatermarkAboveThresholdTask1Hz in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_updateValue(bool value);

/**
 * Update value stored in RX table of signal stackWatermarkAboveThresholdTask1kHz in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_updateValue(bool value);

/**
 * Update value stored in RX table of signal stackWatermarkAboveThresholdTaskCanRx in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_updateValue(bool value);

/**
 * Update value stored in RX table of signal stackWatermarkAboveThresholdTaskCanTx in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_updateValue(bool value);

/**
 * Update value stored in RX table of signal watchdogFault in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_watchdogFault_updateValue(bool value);

/**
 * Update value stored in RX table of signal bspdFault in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_bspdFault_updateValue(bool value);

/**
 * Update value stored in RX table of signal leftWheelSpeedOutOfRange in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_updateValue(uint32_t value);

/**
 * Update value stored in RX table of signal rightWheelSpeedOutOfRange in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_updateValue(uint32_t value);

/**
 * Update value stored in RX table of signal flowRateOutOfRange in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_flowRateOutOfRange_updateValue(uint32_t value);

/**
 * Update value stored in RX table of signal steeringAngleOutOfRange in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_steeringAngleOutOfRange_updateValue(uint32_t value);

/**
 * Update value stored in RX table of signal brakePressureOutOfRange in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_brakePressureOutOfRange_updateValue(uint32_t value);

/**
 * Update value stored in RX table of signal brakePressureSc in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_brakePressureSc_updateValue(bool value);

/**
 * Update value stored in RX table of signal brakePressureOc in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_brakePressureOc_updateValue(bool value);

/**
 * Update value stored in RX table of signal steeringWheelBroke in msg FSM_noncriticalErrors.
 */
void app_canRx_FSM_noncriticalErrors_steeringWheelBroke_updateValue(bool value);

/**
 * Return value from RX table of signal pappsMappedPedalPercentage in msg FSM_apps.
 */
float app_canRx_FSM_apps_pappsMappedPedalPercentage_getValue();

/**
 * Return value from RX table of signal sappsMappedPedalPercentage in msg FSM_apps.
 */
float app_canRx_FSM_apps_sappsMappedPedalPercentage_getValue();

/**
 * Return value from RX table of signal pappsOutOfRange in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_pappsOutOfRange_getValue();

/**
 * Return value from RX table of signal sappsOutOfRange in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_sappsOutOfRange_getValue();

/**
 * Return value from RX table of signal stackWatermarkAboveThresholdTask1Hz in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_getValue();

/**
 * Return value from RX table of signal stackWatermarkAboveThresholdTask1kHz in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_getValue();

/**
 * Return value from RX table of signal stackWatermarkAboveThresholdTaskCanRx in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_getValue();

/**
 * Return value from RX table of signal stackWatermarkAboveThresholdTaskCanTx in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_getValue();

/**
 * Return value from RX table of signal watchdogFault in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_watchdogFault_getValue();

/**
 * Return value from RX table of signal bspdFault in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_bspdFault_getValue();

/**
 * Return value from RX table of signal leftWheelSpeedOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t app_canRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_getValue();

/**
 * Return value from RX table of signal rightWheelSpeedOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t app_canRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_getValue();

/**
 * Return value from RX table of signal flowRateOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t app_canRx_FSM_noncriticalErrors_flowRateOutOfRange_getValue();

/**
 * Return value from RX table of signal steeringAngleOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t app_canRx_FSM_noncriticalErrors_steeringAngleOutOfRange_getValue();

/**
 * Return value from RX table of signal brakePressureOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t app_canRx_FSM_noncriticalErrors_brakePressureOutOfRange_getValue();

/**
 * Return value from RX table of signal brakePressureSc in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_brakePressureSc_getValue();

/**
 * Return value from RX table of signal brakePressureOc in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_brakePressureOc_getValue();

/**
 * Return value from RX table of signal steeringWheelBroke in msg FSM_noncriticalErrors.
 */
bool app_canRx_FSM_noncriticalErrors_steeringWheelBroke_getValue();

