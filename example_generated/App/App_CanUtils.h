/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* ------------------------------- Includes ------------------------------- */

#include <stdint.h>
#include <stdbool.h>

/* -------------------------------- Macros -------------------------------- */

// Msg IDs
#define CANMSG_JCT_VITALS_ID (601)
#define CANMSG_JCT_NONCRITICAL_ERRORS_ID (602)
#define CANMSG_JCT_AIR_SHUTDOWN_ERRORS_ID (603)
#define CANMSG_JCT_MOTOR_SHUTDOWN_ERRORS_ID (604)
#define CANMSG_JCT_STATUS_ID (608)
#define CANMSG_FSM_APPS_ID (151)
#define CANMSG_FSM_NONCRITICAL_ERRORS_ID (300)

// Msg lengths (in bytes)
#define CANMSG_JCT_VITALS_DLC (5)
#define CANMSG_JCT_NONCRITICAL_ERRORS_DLC (1)
#define CANMSG_JCT_AIR_SHUTDOWN_ERRORS_DLC (1)
#define CANMSG_JCT_MOTOR_SHUTDOWN_ERRORS_DLC (1)
#define CANMSG_JCT_STATUS_DLC (5)

// Periodic msg cycle times (in MS)
#define CANMSG_JCT_VITALS_CYCLE_TIME_MS (1000)
#define CANMSG_JCT_AIR_SHUTDOWN_ERRORS_CYCLE_TIME_MS (1000)
#define CANMSG_JCT_MOTOR_SHUTDOWN_ERRORS_CYCLE_TIME_MS (1000)
#define CANMSG_JCT_STATUS_CYCLE_TIME_MS (1000)

// Signal starting values
#define CANSIG_JCT_VITALS_HEARTBEAT_START_VAL (0)
#define CANSIG_JCT_VITALS_TIMESTAMP_START_VAL (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_WATCHDOG_TIMEOUT_START_VAL (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERTEMP_START_VAL (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERVOLTAGE_START_VAL (0)
#define CANSIG_JCT_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_START_VAL (0)
#define CANSIG_JCT_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_START_VAL (0)
#define CANSIG_JCT_STATUS_CONTACTORS_CLOSED_START_VAL (0)
#define CANSIG_JCT_STATUS_CURRENT_START_VAL (50) // A
#define CANSIG_JCT_STATUS_VOLTAGE_START_VAL (0) // V
#define CANSIG_JCT_STATUS_UNSIGNED_TESTER_START_VAL (0) // V
#define CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_START_VAL (0) // %
#define CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_START_VAL (0) // %
#define CANSIG_FSM_NONCRITICAL_ERRORS_PAPPS_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_SAPPS_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1_HZ_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1K_HZ_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_RX_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_TX_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_WATCHDOG_FAULT_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BSPD_FAULT_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_SC_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OC_START_VAL (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_WHEEL_BROKE_START_VAL (0)

// Scale/offset values for encoding/decoding signals
#define CANSIG_JCT_VITALS_HEARTBEAT_SCALE (1.0)
#define CANSIG_JCT_VITALS_HEARTBEAT_OFFSET (0)
#define CANSIG_JCT_VITALS_TIMESTAMP_SCALE (1)
#define CANSIG_JCT_VITALS_TIMESTAMP_OFFSET (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_WATCHDOG_TIMEOUT_SCALE (1)
#define CANSIG_JCT_NONCRITICAL_ERRORS_WATCHDOG_TIMEOUT_OFFSET (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERTEMP_SCALE (1)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERTEMP_OFFSET (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERVOLTAGE_SCALE (1)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERVOLTAGE_OFFSET (0)
#define CANSIG_JCT_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_SCALE (1)
#define CANSIG_JCT_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_OFFSET (0)
#define CANSIG_JCT_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_SCALE (1)
#define CANSIG_JCT_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_OFFSET (0)
#define CANSIG_JCT_STATUS_CONTACTORS_CLOSED_SCALE (1)
#define CANSIG_JCT_STATUS_CONTACTORS_CLOSED_OFFSET (0)
#define CANSIG_JCT_STATUS_CURRENT_SCALE (0.02442002442002442)
#define CANSIG_JCT_STATUS_CURRENT_OFFSET (0)
#define CANSIG_JCT_STATUS_VOLTAGE_SCALE (0.1221001221001221)
#define CANSIG_JCT_STATUS_VOLTAGE_OFFSET (0)
#define CANSIG_JCT_STATUS_UNSIGNED_TESTER_SCALE (1)
#define CANSIG_JCT_STATUS_UNSIGNED_TESTER_OFFSET (0)
#define CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_SCALE (2.3283064370807974e-08)
#define CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_OFFSET (0)
#define CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_SCALE (2.3283064370807974e-08)
#define CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_PAPPS_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_PAPPS_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_SAPPS_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_SAPPS_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1_HZ_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1_HZ_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1K_HZ_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1K_HZ_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_RX_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_RX_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_TX_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_TX_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_WATCHDOG_FAULT_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_WATCHDOG_FAULT_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BSPD_FAULT_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BSPD_FAULT_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_SC_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_SC_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OC_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OC_OFFSET (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_WHEEL_BROKE_SCALE (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_WHEEL_BROKE_OFFSET (0)

// Min/max allowed values for signals
#define CANSIG_JCT_VITALS_HEARTBEAT_MIN (0)
#define CANSIG_JCT_VITALS_HEARTBEAT_MAX (1)
#define CANSIG_JCT_VITALS_TIMESTAMP_MIN (0)
#define CANSIG_JCT_VITALS_TIMESTAMP_MAX (4294967295)
#define CANSIG_JCT_NONCRITICAL_ERRORS_WATCHDOG_TIMEOUT_MIN (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_WATCHDOG_TIMEOUT_MAX (1)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERTEMP_MIN (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERTEMP_MAX (1)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERVOLTAGE_MIN (0)
#define CANSIG_JCT_NONCRITICAL_ERRORS_BOARD_OVERVOLTAGE_MAX (1)
#define CANSIG_JCT_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_MIN (0)
#define CANSIG_JCT_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_MAX (1)
#define CANSIG_JCT_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_MIN (0)
#define CANSIG_JCT_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_MAX (1)
#define CANSIG_JCT_STATUS_CONTACTORS_CLOSED_MIN (0)
#define CANSIG_JCT_STATUS_CONTACTORS_CLOSED_MAX (1)
#define CANSIG_JCT_STATUS_CURRENT_MIN (0) // A
#define CANSIG_JCT_STATUS_CURRENT_MAX (100) // A
#define CANSIG_JCT_STATUS_VOLTAGE_MIN (0) // V
#define CANSIG_JCT_STATUS_VOLTAGE_MAX (500) // V
#define CANSIG_JCT_STATUS_UNSIGNED_TESTER_MIN (-2047) // V
#define CANSIG_JCT_STATUS_UNSIGNED_TESTER_MAX (2046) // V
#define CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_MIN (0) // %
#define CANSIG_FSM_APPS_PAPPS_MAPPED_PEDAL_PERCENTAGE_MAX (100) // %
#define CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_MIN (0) // %
#define CANSIG_FSM_APPS_SAPPS_MAPPED_PEDAL_PERCENTAGE_MAX (100) // %
#define CANSIG_FSM_NONCRITICAL_ERRORS_PAPPS_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_PAPPS_OUT_OF_RANGE_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_SAPPS_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_SAPPS_OUT_OF_RANGE_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1_HZ_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1_HZ_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1K_HZ_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1K_HZ_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_RX_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_RX_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_TX_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK_CAN_TX_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_WATCHDOG_FAULT_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_WATCHDOG_FAULT_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BSPD_FAULT_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BSPD_FAULT_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NONCRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NONCRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_MAX (3)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_SC_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_SC_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OC_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_BRAKE_PRESSURE_OC_MAX (1)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_WHEEL_BROKE_MIN (0)
#define CANSIG_FSM_NONCRITICAL_ERRORS_STEERING_WHEEL_BROKE_MAX (1)


/* -------------------------------- Enums --------------------------------- */

typedef enum
{
    AIR_OPEN = 0,
    AIR_CLOSED = 1,
} AirState;


/* ------------------------------- Structs -------------------------------- */

/**
 * Signals in CAN msg JCT_vitals.
 */
typedef struct
{
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool heartbeat_value;
    /**
     * Description: N/A
     * Range: 0 to 4294967295
     */
    uint32_t timestamp_value;
} JCT_vitals_Signals;

/**
 * Signals in CAN msg JCT_noncriticalErrors.
 */
typedef struct
{
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool watchdogTimeout_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool boardOvertemp_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool boardOvervoltage_value;
} JCT_noncriticalErrors_Signals;

/**
 * Signals in CAN msg JCT_AIRShutdownErrors.
 */
typedef struct
{
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool dummyAirShutdown_value;
} JCT_AIRShutdownErrors_Signals;

/**
 * Signals in CAN msg JCT_motorShutdownErrors.
 */
typedef struct
{
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool dummyMotorShutdown_value;
} JCT_motorShutdownErrors_Signals;

/**
 * Signals in CAN msg JCT_status.
 */
typedef struct
{
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    AirState contactorsClosed_value;
    /**
     * Description: N/A
     * Range: 0A to 100A
     */
    float current_value;
    /**
     * Description: N/A
     * Range: 0V to 500V
     */
    float voltage_value;
    /**
     * Description: N/A
     * Range: -2047V to 2046V
     */
    int unsigned_tester_value;
} JCT_status_Signals;

/**
 * Signals in CAN msg FSM_apps.
 */
typedef struct
{
    /**
     * Description: N/A
     * Range: 0% to 100%
     */
    float pappsMappedPedalPercentage_value;
    /**
     * Description: N/A
     * Range: 0% to 100%
     */
    float sappsMappedPedalPercentage_value;
} FSM_apps_Signals;

/**
 * Signals in CAN msg FSM_noncriticalErrors.
 */
typedef struct
{
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool pappsOutOfRange_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool sappsOutOfRange_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool stackWatermarkAboveThresholdTask1Hz_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool stackWatermarkAboveThresholdTask1kHz_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool stackWatermarkAboveThresholdTaskCanRx_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool stackWatermarkAboveThresholdTaskCanTx_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool watchdogFault_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool bspdFault_value;
    /**
     * Description: N/A
     * Range: 0 to 3
     */
    uint32_t leftWheelSpeedOutOfRange_value;
    /**
     * Description: N/A
     * Range: 0 to 3
     */
    uint32_t rightWheelSpeedOutOfRange_value;
    /**
     * Description: N/A
     * Range: 0 to 3
     */
    uint32_t flowRateOutOfRange_value;
    /**
     * Description: N/A
     * Range: 0 to 3
     */
    uint32_t steeringAngleOutOfRange_value;
    /**
     * Description: N/A
     * Range: 0 to 3
     */
    uint32_t brakePressureOutOfRange_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool brakePressureSc_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool brakePressureOc_value;
    /**
     * Description: N/A
     * Range: 0 to 1
     */
    bool steeringWheelBroke_value;
} FSM_noncriticalErrors_Signals;


/* ------------------------- Function Prototypes -------------------------- */

/**
 * Pack signals into CAN payload for JCT_vitals.
 */
void app_canUtils_JCT_vitals_pack(const JCT_vitals_Signals* const in_msg, uint8_t* const out_data);

/**
 * Pack signals into CAN payload for JCT_noncriticalErrors.
 */
void app_canUtils_JCT_noncriticalErrors_pack(const JCT_noncriticalErrors_Signals* const in_msg, uint8_t* const out_data);

/**
 * Pack signals into CAN payload for JCT_AIRShutdownErrors.
 */
void app_canUtils_JCT_AIRShutdownErrors_pack(const JCT_AIRShutdownErrors_Signals* const in_msg, uint8_t* const out_data);

/**
 * Pack signals into CAN payload for JCT_motorShutdownErrors.
 */
void app_canUtils_JCT_motorShutdownErrors_pack(const JCT_motorShutdownErrors_Signals* const in_msg, uint8_t* const out_data);

/**
 * Pack signals into CAN payload for JCT_status.
 */
void app_canUtils_JCT_status_pack(const JCT_status_Signals* const in_msg, uint8_t* const out_data);

/**
 * Unpack signals from CAN payload for FSM_apps.
 */
void app_canUtils_FSM_apps_unpack(const uint8_t* const in_data, FSM_apps_Signals* const out_msg);

/**
 * Unpack signals from CAN payload for FSM_noncriticalErrors.
 */
void app_canUtils_FSM_noncriticalErrors_unpack(const uint8_t* const in_data, FSM_noncriticalErrors_Signals* const out_msg);

