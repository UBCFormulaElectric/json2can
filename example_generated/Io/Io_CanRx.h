/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* --------------------------------- Includes ----------------------------------- */

#include <stdint.h>
#include <stdbool.h>
#include "Io_SharedCanMsg.h"

/* ---------------------------------- Macros ------------------------------------ */



/* ---------------------------------- Structs ----------------------------------- */



/* ----------------------------------- Enums ------------------------------------ */



/* --------------------------- Function declarations ---------------------------- */

/**
 * @brief Unpack a received message and update the CAN Rx table.
 */ 
void Io_CanRx_UpdateRxTableWithMessage(struct CanMsg* message);

/**
 * @brief Returns true if JSONCANTest listens to the given message ID.
 */ 
bool Io_CanRx_FilterMessageId(uint32_t std_id);
