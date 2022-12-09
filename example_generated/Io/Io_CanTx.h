/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off

#pragma once

/* ------------------------------- Includes ------------------------------- */

#include <stdint.h>

/* ------------------------- Function Prototypes -------------------------- */

/**
 * Enqeue periodic CAN msgs of period 10ms.
 */
void Io_CanTx_Enqueue100HzMsgs();

/**
 * Enqeue periodic CAN msgs of period 100ms.
 */
void Io_CanTx_Enqueue10HzMsgs();

/**
 * Enqeue periodic CAN msgs of period 1000ms.
 */
void Io_CanTx_Enqueue1HzMsgs();

/**
 * Pack and send the aperiodic TX msg JctWarnings.
 */
void App_CanTx_JctWarnings_SendAperiodic();

/**
 * Pack and send the aperiodic TX msg JCT_AlertSet.
 */
void App_CanTx_JCT_AlertSet_SendAperiodic();

/**
 * Pack and send the aperiodic TX msg JCT_AlertCleared.
 */
void App_CanTx_JCT_AlertCleared_SendAperiodic();

