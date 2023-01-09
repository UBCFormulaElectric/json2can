/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off

#pragma once

/* ------------------------------- Includes ------------------------------- */

#include "App_CanUtils.h"

/* ------------------------- Function Prototypes -------------------------- */

/**
 * Initialize RX signals to their starting values.
 */
void App_CanRx_Init(void);

/**
 * Update value stored in RX table of signal PappsMappedPedalPercentage in msg FsmApps.
 */
void App_CanRx_FsmApps_PappsMappedPedalPercentage_UpdateValue(float value);

/**
 * Update value stored in RX table of signal SappsMappedPedalPercentage in msg FsmApps.
 */
void App_CanRx_FsmApps_SappsMappedPedalPercentage_UpdateValue(float value);

/**
 * Update value stored in RX table of signal PappsOutOfRange in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_PappsOutOfRange_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal SappsOutOfRange in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_SappsOutOfRange_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal StackWatermarkAboveThresholdTask1Hz in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1Hz_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal StackWatermarkAboveThresholdTask1kHz in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1kHz_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal StackWatermarkAboveThresholdTaskCanRx in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanRx_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal StackWatermarkAboveThresholdTaskCanTx in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanTx_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal WatchdogFault in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_WatchdogFault_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal BspdFault in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_BspdFault_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal LeftWheelSpeedOutOfRange in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_LeftWheelSpeedOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal RightWheelSpeedOutOfRange in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_RightWheelSpeedOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal FlowRateOutOfRange in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_FlowRateOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal SteeringAngleOutOfRange in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_SteeringAngleOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal BrakePressureOutOfRange in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_BrakePressureOutOfRange_UpdateValue(uint32_t value);

/**
 * Update value stored in RX table of signal BrakePressureSc in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_BrakePressureSc_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal BrakePressureOc in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_BrakePressureOc_UpdateValue(bool value);

/**
 * Update value stored in RX table of signal SteeringWheelBroke in msg FsmWarnings.
 */
void App_CanRx_FsmWarnings_SteeringWheelBroke_UpdateValue(bool value);

/**
 * Return value from RX table of signal PappsMappedPedalPercentage in msg FsmApps.
 */
float App_CanRx_FsmApps_PappsMappedPedalPercentage_GetValue(void);

/**
 * Return value from RX table of signal SappsMappedPedalPercentage in msg FsmApps.
 */
float App_CanRx_FsmApps_SappsMappedPedalPercentage_GetValue(void);

/**
 * Return value from RX table of signal PappsOutOfRange in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_PappsOutOfRange_GetValue(void);

/**
 * Return value from RX table of signal SappsOutOfRange in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_SappsOutOfRange_GetValue(void);

/**
 * Return value from RX table of signal StackWatermarkAboveThresholdTask1Hz in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1Hz_GetValue(void);

/**
 * Return value from RX table of signal StackWatermarkAboveThresholdTask1kHz in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1kHz_GetValue(void);

/**
 * Return value from RX table of signal StackWatermarkAboveThresholdTaskCanRx in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanRx_GetValue(void);

/**
 * Return value from RX table of signal StackWatermarkAboveThresholdTaskCanTx in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanTx_GetValue(void);

/**
 * Return value from RX table of signal WatchdogFault in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_WatchdogFault_GetValue(void);

/**
 * Return value from RX table of signal BspdFault in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_BspdFault_GetValue(void);

/**
 * Return value from RX table of signal LeftWheelSpeedOutOfRange in msg FsmWarnings.
 */
uint32_t App_CanRx_FsmWarnings_LeftWheelSpeedOutOfRange_GetValue(void);

/**
 * Return value from RX table of signal RightWheelSpeedOutOfRange in msg FsmWarnings.
 */
uint32_t App_CanRx_FsmWarnings_RightWheelSpeedOutOfRange_GetValue(void);

/**
 * Return value from RX table of signal FlowRateOutOfRange in msg FsmWarnings.
 */
uint32_t App_CanRx_FsmWarnings_FlowRateOutOfRange_GetValue(void);

/**
 * Return value from RX table of signal SteeringAngleOutOfRange in msg FsmWarnings.
 */
uint32_t App_CanRx_FsmWarnings_SteeringAngleOutOfRange_GetValue(void);

/**
 * Return value from RX table of signal BrakePressureOutOfRange in msg FsmWarnings.
 */
uint32_t App_CanRx_FsmWarnings_BrakePressureOutOfRange_GetValue(void);

/**
 * Return value from RX table of signal BrakePressureSc in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_BrakePressureSc_GetValue(void);

/**
 * Return value from RX table of signal BrakePressureOc in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_BrakePressureOc_GetValue(void);

/**
 * Return value from RX table of signal SteeringWheelBroke in msg FsmWarnings.
 */
bool App_CanRx_FsmWarnings_SteeringWheelBroke_GetValue(void);

