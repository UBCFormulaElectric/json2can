/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* --------------------------------- Includes ----------------------------------- */

#include <stdint.h>

/* ---------------------------------- Macros ------------------------------------ */



/* ---------------------------------- Structs ----------------------------------- */



/* ----------------------------------- Enums ------------------------------------ */



/* --------------------------- Function declarations ---------------------------- */

/**
 * @brief Enqueue periodic CAN TX messages of rate 1kHz (cycle time = 1ms).
 */ 
void Io_CanTx_Enqueue1kHzMessages(const uint32_t current_ms);

/**
 * @brief Enqueue periodic CAN TX messages of rate 100Hz (cycle time = 10ms).
 */ 
void Io_CanTx_Enqueue100HzMessages(const uint32_t current_ms);

/**
 * @brief Enqueue periodic CAN TX messages of rate 10Hz (cycle time = 100ms).
 */ 
void Io_CanTx_Enqueue10HzMessages(const uint32_t current_ms);

/**
 * @brief Enqueue periodic CAN TX messages of rate 1Hz (cycle time = 1000ms).
 */ 
void Io_CanTx_Enqueue1HzMessages(const uint32_t current_ms);

/**
 * @brief Pack and send the TX message {name}.
 */ 
void App_CanTx_JSONCANTest_VITALS_Send(void);

/**
 * @brief Pack and send the TX message {name}.
 */ 
void App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_Send(void);

/**
 * @brief Pack and send the TX message {name}.
 */ 
void App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_Send(void);

/**
 * @brief Pack and send the TX message {name}.
 */ 
void App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Send(void);

/**
 * @brief Pack and send the TX message {name}.
 */ 
void App_CanTx_JSONCANTest_STATUS_Send(void);
