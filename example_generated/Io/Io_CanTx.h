/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* ------------------------------- Includes ------------------------------- */

#include <stdint.h>

/* ------------------------- Function Prototypes -------------------------- */

/**
 * Enqeue periodic CAN msgs of period 10ms.
 */
void io_canTx_enqueue100HzMsgs();

/**
 * Enqeue periodic CAN msgs of period 100ms.
 */
void io_canTx_enqueue10HzMsgs();

/**
 * Enqeue periodic CAN msgs of period 1000ms.
 */
void io_canTx_enqueue1HzMsgs();

/**
 * Pack and send the aperiodic TX msg JCT_noncriticalErrors.
 */
void app_canTx_JCT_noncriticalErrors_sendAperiodic();

