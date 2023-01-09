/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off

#pragma once

/* ------------------------------- Includes ------------------------------- */

#include <stdint.h>

/* ------------------------- Function Prototypes -------------------------- */

/**
 * Enqeue periodic CAN msgs of period 1000ms.
 */
void Io_CanTx_Enqueue1HzMsgs(void);

/**
 * Enqeue periodic CAN msgs of period 10ms.
 */
void Io_CanTx_Enqueue100HzMsgs(void);

/**
 * Enqueue periodic CAN messages whose cycle time does is not suitable for other periodic sending functions.
 */
void Io_CanTx_EnqueueOtherPeriodicMsgs(uint32_t time_ms);

/**
 * Pack and send the aperiodic TX msg JctWarnings.
 */
void App_CanTx_JctWarnings_SendAperiodic(void);

/**
 * Pack and send the aperiodic TX msg JCT_AlertSet.
 */
void App_CanTx_JCT_AlertSet_SendAperiodic(void);

/**
 * Pack and send the aperiodic TX msg JCT_AlertCleared.
 */
void App_CanTx_JCT_AlertCleared_SendAperiodic(void);

