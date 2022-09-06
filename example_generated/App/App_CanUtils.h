/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* --------------------------------- Includes ----------------------------------- */

#include <stdint.h>
#include <stdbool.h>

/* ---------------------------------- Macros ------------------------------------ */

// Message IDs
#define CANMSG_JSONCANTest_VITALS_ID (0x259)
#define CANMSG_JSONCANTest_NON_CRITICAL_ERRORS_ID (0x25a)
#define CANMSG_JSONCANTest_AIR_SHUTDOWN_ERRORS_ID (0x25b)
#define CANMSG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_ID (0x25c)
#define CANMSG_JSONCANTest_STATUS_ID (0x25d)
#define CANMSG_FSM_APPS_ID (0x97)
#define CANMSG_FSM_NON_CRITICAL_ERRORS_ID (0x12c)

// Message lengths in bytes
#define CANMSG_JSONCANTest_VITALS_LENGTH (5)
#define CANMSG_JSONCANTest_NON_CRITICAL_ERRORS_LENGTH (1)
#define CANMSG_JSONCANTest_AIR_SHUTDOWN_ERRORS_LENGTH (1)
#define CANMSG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_LENGTH (1)
#define CANMSG_JSONCANTest_STATUS_LENGTH (4)

// Message cycle times in ms
#define CANMSG_JSONCANTest_VITALS_CYCLE_TIME_MS (1000)
#define CANMSG_JSONCANTest_NON_CRITICAL_ERRORS_CYCLE_TIME_MS (1000)
#define CANMSG_JSONCANTest_AIR_SHUTDOWN_ERRORS_CYCLE_TIME_MS (1000)
#define CANMSG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_CYCLE_TIME_MS (1000)
#define CANMSG_JSONCANTest_STATUS_CYCLE_TIME_MS (1000)

// Signal default starting values
#define CANSIG_JSONCANTest_VITALS_HEARTBEAT_START_VAL (0)
#define CANSIG_JSONCANTest_VITALS_TIMESTAMP_START_VAL (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_START_VAL (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_START_VAL (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_START_VAL (0)
#define CANSIG_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_START_VAL (0)
#define CANSIG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_START_VAL (0)
#define CANSIG_JSONCANTest_STATUS_CONTACTORS_CLOSED_START_VAL (0)
#define CANSIG_JSONCANTest_STATUS_CURRENT_START_VAL (50) // A 
#define CANSIG_JSONCANTest_STATUS_VOLTAGE_START_VAL (0) // V 
#define CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_START_VAL (0) // % 
#define CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_START_VAL (0) // % 
#define CANSIG_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_START_VAL (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_START_VAL (0)

// Scale values for encoding/decoding signals
#define CANSIG_JSONCANTest_VITALS_HEARTBEAT_SCALE (1)
#define CANSIG_JSONCANTest_VITALS_TIMESTAMP_SCALE (1)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_SCALE (1)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_SCALE (1)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_SCALE (1)
#define CANSIG_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_SCALE (1)
#define CANSIG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_SCALE (1)
#define CANSIG_JSONCANTest_STATUS_CONTACTORS_CLOSED_SCALE (1)
#define CANSIG_JSONCANTest_STATUS_CURRENT_SCALE (0.02442002442002442f)
#define CANSIG_JSONCANTest_STATUS_VOLTAGE_SCALE (0.1221001221001221f)
#define CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_SCALE (2.3283064370807974e-08f)
#define CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_SCALE (2.3283064370807974e-08f)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_SCALE (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_SCALE (1)

// Offset values for encoding/decoding signals
#define CANSIG_JSONCANTest_VITALS_HEARTBEAT_OFFSET (0)
#define CANSIG_JSONCANTest_VITALS_TIMESTAMP_OFFSET (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_OFFSET (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_OFFSET (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_OFFSET (0)
#define CANSIG_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_OFFSET (0)
#define CANSIG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_OFFSET (0)
#define CANSIG_JSONCANTest_STATUS_CONTACTORS_CLOSED_OFFSET (0)
#define CANSIG_JSONCANTest_STATUS_CURRENT_OFFSET (0.0f)
#define CANSIG_JSONCANTest_STATUS_VOLTAGE_OFFSET (0.0f)
#define CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_OFFSET (0.0f)
#define CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_OFFSET (0.0f)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_OFFSET (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_OFFSET (0)

// Minimum allowed values for signals
#define CANSIG_JSONCANTest_VITALS_HEARTBEAT_MIN (0)
#define CANSIG_JSONCANTest_VITALS_TIMESTAMP_MIN (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_MIN (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_MIN (0)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_MIN (0)
#define CANSIG_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_MIN (0)
#define CANSIG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_MIN (0)
#define CANSIG_JSONCANTest_STATUS_CONTACTORS_CLOSED_MIN (0)
#define CANSIG_JSONCANTest_STATUS_CURRENT_MIN (0.0f)
#define CANSIG_JSONCANTest_STATUS_VOLTAGE_MIN (0.0f)
#define CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_MIN (0.0f)
#define CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_MIN (0.0f)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_MIN (0)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_MIN (0)

// Maximum allowed values for signals
#define CANSIG_JSONCANTest_VITALS_HEARTBEAT_MAX (1)
#define CANSIG_JSONCANTest_VITALS_TIMESTAMP_MAX (4294967295)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_MAX (1)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_MAX (1)
#define CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_MAX (1)
#define CANSIG_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_MAX (1)
#define CANSIG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_MAX (1)
#define CANSIG_JSONCANTest_STATUS_CONTACTORS_CLOSED_MAX (1)
#define CANSIG_JSONCANTest_STATUS_CURRENT_MAX (100.0f)
#define CANSIG_JSONCANTest_STATUS_VOLTAGE_MAX (500.0f)
#define CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_MAX (100.0f)
#define CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_MAX (100.0f)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_MAX (1)
#define CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_MAX (1)


/* ----------------------------------- Enums ------------------------------------ */

typedef enum
{
    AIR_OPEN = 0,
    AIR_CLOSED = 1,
} AIR_STATE;

/* ---------------------------------- Structs ----------------------------------- */

/**
 * Signals in CAN message JSONCANTest_VITALS.
 */
typedef struct
{
    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool HEARTBEAT_value;

    /*
    * Description: N/A
    * Range: 0 to 4294967295
    * Unit: No units
    */
    uint32_t TIMESTAMP_value;

} JSONCANTest_VITALS_Signals;

/**
 * Signals in CAN message JSONCANTest_NON_CRITICAL_ERRORS.
 */
typedef struct
{
    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool WATCHDOG_TIMEOUT_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool BOARD_OVERTEMP_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool BOARD_OVERVOLTAGE_value;

} JSONCANTest_NON_CRITICAL_ERRORS_Signals;

/**
 * Signals in CAN message JSONCANTest_AIR_SHUTDOWN_ERRORS.
 */
typedef struct
{
    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool DUMMY_AIR_SHUTDOWN_value;

} JSONCANTest_AIR_SHUTDOWN_ERRORS_Signals;

/**
 * Signals in CAN message JSONCANTest_MOTOR_SHUTDOWN_ERRORS.
 */
typedef struct
{
    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool DUMMY_MOTOR_SHUTDOWN_value;

} JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Signals;

/**
 * Signals in CAN message JSONCANTest_STATUS.
 */
typedef struct
{
    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    AIR_STATE CONTACTORS_CLOSED_value;

    /*
    * Description: N/A
    * Range: 0A to 100A
    * Unit: A
    */
    float CURRENT_value;

    /*
    * Description: N/A
    * Range: 0V to 500V
    * Unit: V
    */
    float VOLTAGE_value;

} JSONCANTest_STATUS_Signals;

/**
 * Signals in CAN message FSM_APPS.
 */
typedef struct
{
    /*
    * Description: N/A
    * Range: 0% to 100%
    * Unit: %
    */
    float Papps_Mapped_Pedal_Percentage_value;

    /*
    * Description: N/A
    * Range: 0% to 100%
    * Unit: %
    */
    float Sapps_Mapped_Pedal_Percentage_value;

} FSM_APPS_Signals;

/**
 * Signals in CAN message FSM_NON_CRITICAL_ERRORS.
 */
typedef struct
{
    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool papps_out_of_range_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool sapps_out_of_range_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool WATCHDOG_TIMEOUT_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool BSPD_FAULT_value;

    /*
    * Description: N/A
    * Range: 0 to 3
    * Unit: No units
    */
    uint32_t LEFT_WHEEL_SPEED_OUT_OF_RANGE_value;

    /*
    * Description: N/A
    * Range: 0 to 3
    * Unit: No units
    */
    uint32_t RIGHT_WHEEL_SPEED_OUT_OF_RANGE_value;

    /*
    * Description: N/A
    * Range: 0 to 3
    * Unit: No units
    */
    uint32_t FLOW_RATE_OUT_OF_RANGE_value;

    /*
    * Description: N/A
    * Range: 0 to 3
    * Unit: No units
    */
    uint32_t STEERING_ANGLE_OUT_OF_RANGE_value;

    /*
    * Description: N/A
    * Range: 0 to 3
    * Unit: No units
    */
    uint32_t BRAKE_PRESSURE_OUT_OF_RANGE_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool BRAKE_PRESSURE_OPEN_SC_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool BRAKE_PRESSURE_OPEN_OC_value;

    /*
    * Description: N/A
    * Range: 0 to 1
    * Unit: No units
    */
    bool STEERING_WHEEL_BROKE_value;

} FSM_NON_CRITICAL_ERRORS_Signals;

/* --------------------------- Function declarations ---------------------------- */

/**
 * @brief Pack signal data for CAN message JSONCANTest_VITALS.
 */ 
void App_CanMsgs_JSONCANTest_VITALS_Pack(const JSONCANTest_VITALS_Signals* const in_msg, uint8_t* const out_data);

/**
 * @brief Pack signal data for CAN message JSONCANTest_NON_CRITICAL_ERRORS.
 */ 
void App_CanMsgs_JSONCANTest_NON_CRITICAL_ERRORS_Pack(const JSONCANTest_NON_CRITICAL_ERRORS_Signals* const in_msg, uint8_t* const out_data);

/**
 * @brief Pack signal data for CAN message JSONCANTest_AIR_SHUTDOWN_ERRORS.
 */ 
void App_CanMsgs_JSONCANTest_AIR_SHUTDOWN_ERRORS_Pack(const JSONCANTest_AIR_SHUTDOWN_ERRORS_Signals* const in_msg, uint8_t* const out_data);

/**
 * @brief Pack signal data for CAN message JSONCANTest_MOTOR_SHUTDOWN_ERRORS.
 */ 
void App_CanMsgs_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Pack(const JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Signals* const in_msg, uint8_t* const out_data);

/**
 * @brief Pack signal data for CAN message JSONCANTest_STATUS.
 */ 
void App_CanMsgs_JSONCANTest_STATUS_Pack(const JSONCANTest_STATUS_Signals* const in_msg, uint8_t* const out_data);

/**
 * @brief Unpack signal data for CAN message FSM_APPS.
 */ 
void App_CanMsgs_FSM_APPS_Unpack(const uint8_t* const in_data, FSM_APPS_Signals* const out_msg);

/**
 * @brief Unpack signal data for CAN message FSM_NON_CRITICAL_ERRORS.
 */ 
void App_CanMsgs_FSM_NON_CRITICAL_ERRORS_Unpack(const uint8_t* const in_data, FSM_NON_CRITICAL_ERRORS_Signals* const out_msg);
