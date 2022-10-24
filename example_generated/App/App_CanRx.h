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
void App_CanRx_Init();

/**
 * Update value stored in RX table of signal pappsMappedPedalPercentage in msg FSM_apps.
 */
void App_CanRx_FSM_apps_pappsMappedPedalPercentage_UpdateValue(float value);

/**
 * Update value stored in RX table of signal sappsMappedPedalPercentage in msg FSM_apps.
 */
void App_CanRx_FSM_apps_sappsMappedPedalPercentage_UpdateValue(float value);

/**
 * Update value stored in RX table of signal pappsOutOfRange in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_pappsOutOfRange_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal sappsOutOfRange in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_sappsOutOfRange_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal stackWatermarkAboveThresholdTask1Hz in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal stackWatermarkAboveThresholdTask1kHz in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal stackWatermarkAboveThresholdTaskCanRx in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal stackWatermarkAboveThresholdTaskCanTx in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal watchdogFault in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_watchdogFault_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal bspdFault in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_bspdFault_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal leftWheelSpeedOutOfRange in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal rightWheelSpeedOutOfRange in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal flowRateOutOfRange in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_flowRateOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal steeringAngleOutOfRange in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_steeringAngleOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal brakePressureOutOfRange in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_brakePressureOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal brakePressureSc in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_brakePressureSc_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal brakePressureOc in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_brakePressureOc_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal steeringWheelBroke in msg FSM_noncriticalErrors.
 */
void App_CanRx_FSM_noncriticalErrors_steeringWheelBroke_UpdateValue(bool value);

/**
 * Return value from RX table of signal pappsMappedPedalPercentage in msg FSM_apps.
 */
float App_CanRx_FSM_apps_pappsMappedPedalPercentage_GetValue();

/**
 * Return value from RX table of signal sappsMappedPedalPercentage in msg FSM_apps.
 */
float App_CanRx_FSM_apps_sappsMappedPedalPercentage_GetValue();

/**
 * Return value from RX table of signal pappsOutOfRange in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_pappsOutOfRange_GetValue();

/**
 * Return value from RX table of signal sappsOutOfRange in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_sappsOutOfRange_GetValue();

/**
 * Return value from RX table of signal stackWatermarkAboveThresholdTask1Hz in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_GetValue();

/**
 * Return value from RX table of signal stackWatermarkAboveThresholdTask1kHz in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_GetValue();

/**
 * Return value from RX table of signal stackWatermarkAboveThresholdTaskCanRx in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_GetValue();

/**
 * Return value from RX table of signal stackWatermarkAboveThresholdTaskCanTx in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_GetValue();

/**
 * Return value from RX table of signal watchdogFault in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_watchdogFault_GetValue();

/**
 * Return value from RX table of signal bspdFault in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_bspdFault_GetValue();

/**
 * Return value from RX table of signal leftWheelSpeedOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t App_CanRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_GetValue();

/**
 * Return value from RX table of signal rightWheelSpeedOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t App_CanRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_GetValue();

/**
 * Return value from RX table of signal flowRateOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t App_CanRx_FSM_noncriticalErrors_flowRateOutOfRange_GetValue();

/**
 * Return value from RX table of signal steeringAngleOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t App_CanRx_FSM_noncriticalErrors_steeringAngleOutOfRange_GetValue();

/**
 * Return value from RX table of signal brakePressureOutOfRange in msg FSM_noncriticalErrors.
 */
uint32_t App_CanRx_FSM_noncriticalErrors_brakePressureOutOfRange_GetValue();

/**
 * Return value from RX table of signal brakePressureSc in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_brakePressureSc_GetValue();

/**
 * Return value from RX table of signal brakePressureOc in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_brakePressureOc_GetValue();

/**
 * Return value from RX table of signal steeringWheelBroke in msg FSM_noncriticalErrors.
 */
bool App_CanRx_FSM_noncriticalErrors_steeringWheelBroke_GetValue();

