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
#define CANMSG_JCT_vitals_ID (601)
#define CANMSG_JCT_noncriticalErrors_ID (602)
#define CANMSG_JCT_AIRShutdownErrors_ID (603)
#define CANMSG_JCT_motorShutdownErrors_ID (604)
#define CANMSG_JCT_status_ID (605)
#define CANMSG_FSM_apps_ID (151)
#define CANMSG_FSM_noncriticalErrors_ID (300)

// Msg lengths (in bytes)
#define CANMSG_JCT_vitals_DLC (5)
#define CANMSG_JCT_noncriticalErrors_DLC (1)
#define CANMSG_JCT_AIRShutdownErrors_DLC (1)
#define CANMSG_JCT_motorShutdownErrors_DLC (1)
#define CANMSG_JCT_status_DLC (4)

// Periodic msg cycle times (in MS)
#define CANMSG_JCT_vitals_CYCLE_TIME_MS (1000)
#define CANMSG_JCT_AIRShutdownErrors_CYCLE_TIME_MS (1000)
#define CANMSG_JCT_motorShutdownErrors_CYCLE_TIME_MS (1000)
#define CANMSG_JCT_status_CYCLE_TIME_MS (1000)

// Signal starting values
#define CANSIG_JCT_vitals_heartbeat_START_VAL (0)
#define CANSIG_JCT_vitals_timestamp_START_VAL (0)
#define CANSIG_JCT_noncriticalErrors_watchdogTimeout_START_VAL (0)
#define CANSIG_JCT_noncriticalErrors_boardOvertemp_START_VAL (0)
#define CANSIG_JCT_noncriticalErrors_boardOvervoltage_START_VAL (0)
#define CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_START_VAL (0)
#define CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_START_VAL (0)
#define CANSIG_JCT_status_contactorsClosed_START_VAL (0)
#define CANSIG_JCT_status_current_START_VAL (50) // A
#define CANSIG_JCT_status_voltage_START_VAL (0) // V
#define CANSIG_FSM_apps_pappsMappedPedalPercentage_START_VAL (0) // %
#define CANSIG_FSM_apps_sappsMappedPedalPercentage_START_VAL (0) // %
#define CANSIG_FSM_noncriticalErrors_pappsOutOfRange_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_sappsOutOfRange_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_watchdogFault_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_bspdFault_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureSc_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureOc_START_VAL (0)
#define CANSIG_FSM_noncriticalErrors_steeringWheelBroke_START_VAL (0)

// Scale/offset values for encoding/decoding signals
#define CANSIG_JCT_vitals_heartbeat_SCALE (1.0)
#define CANSIG_JCT_vitals_heartbeat_OFFSET (0)
#define CANSIG_JCT_vitals_timestamp_SCALE (1)
#define CANSIG_JCT_vitals_timestamp_OFFSET (0)
#define CANSIG_JCT_noncriticalErrors_watchdogTimeout_SCALE (1)
#define CANSIG_JCT_noncriticalErrors_watchdogTimeout_OFFSET (0)
#define CANSIG_JCT_noncriticalErrors_boardOvertemp_SCALE (1)
#define CANSIG_JCT_noncriticalErrors_boardOvertemp_OFFSET (0)
#define CANSIG_JCT_noncriticalErrors_boardOvervoltage_SCALE (1)
#define CANSIG_JCT_noncriticalErrors_boardOvervoltage_OFFSET (0)
#define CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_SCALE (1)
#define CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_OFFSET (0)
#define CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_SCALE (1)
#define CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_OFFSET (0)
#define CANSIG_JCT_status_contactorsClosed_SCALE (1)
#define CANSIG_JCT_status_contactorsClosed_OFFSET (0)
#define CANSIG_JCT_status_current_SCALE (0.02442002442002442)
#define CANSIG_JCT_status_current_OFFSET (0)
#define CANSIG_JCT_status_voltage_SCALE (0.1221001221001221)
#define CANSIG_JCT_status_voltage_OFFSET (0)
#define CANSIG_FSM_apps_pappsMappedPedalPercentage_SCALE (2.3283064370807974e-08)
#define CANSIG_FSM_apps_pappsMappedPedalPercentage_OFFSET (0)
#define CANSIG_FSM_apps_sappsMappedPedalPercentage_SCALE (2.3283064370807974e-08)
#define CANSIG_FSM_apps_sappsMappedPedalPercentage_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_pappsOutOfRange_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_pappsOutOfRange_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_sappsOutOfRange_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_sappsOutOfRange_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_watchdogFault_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_watchdogFault_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_bspdFault_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_bspdFault_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureSc_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_brakePressureSc_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureOc_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_brakePressureOc_OFFSET (0)
#define CANSIG_FSM_noncriticalErrors_steeringWheelBroke_SCALE (1)
#define CANSIG_FSM_noncriticalErrors_steeringWheelBroke_OFFSET (0)

// Min/max allowed values for signals
#define CANSIG_JCT_vitals_heartbeat_MIN (0)
#define CANSIG_JCT_vitals_heartbeat_MAX (1)
#define CANSIG_JCT_vitals_timestamp_MIN (0)
#define CANSIG_JCT_vitals_timestamp_MAX (4294967295)
#define CANSIG_JCT_noncriticalErrors_watchdogTimeout_MIN (0)
#define CANSIG_JCT_noncriticalErrors_watchdogTimeout_MAX (1)
#define CANSIG_JCT_noncriticalErrors_boardOvertemp_MIN (0)
#define CANSIG_JCT_noncriticalErrors_boardOvertemp_MAX (1)
#define CANSIG_JCT_noncriticalErrors_boardOvervoltage_MIN (0)
#define CANSIG_JCT_noncriticalErrors_boardOvervoltage_MAX (1)
#define CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_MIN (0)
#define CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_MAX (1)
#define CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_MIN (0)
#define CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_MAX (1)
#define CANSIG_JCT_status_contactorsClosed_MIN (0)
#define CANSIG_JCT_status_contactorsClosed_MAX (1)
#define CANSIG_JCT_status_current_MIN (0) // A
#define CANSIG_JCT_status_current_MAX (100) // A
#define CANSIG_JCT_status_voltage_MIN (0) // V
#define CANSIG_JCT_status_voltage_MAX (500) // V
#define CANSIG_FSM_apps_pappsMappedPedalPercentage_MIN (0) // %
#define CANSIG_FSM_apps_pappsMappedPedalPercentage_MAX (100) // %
#define CANSIG_FSM_apps_sappsMappedPedalPercentage_MIN (0) // %
#define CANSIG_FSM_apps_sappsMappedPedalPercentage_MAX (100) // %
#define CANSIG_FSM_noncriticalErrors_pappsOutOfRange_MIN (0)
#define CANSIG_FSM_noncriticalErrors_pappsOutOfRange_MAX (1)
#define CANSIG_FSM_noncriticalErrors_sappsOutOfRange_MIN (0)
#define CANSIG_FSM_noncriticalErrors_sappsOutOfRange_MAX (1)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_MIN (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_MAX (1)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_MIN (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_MAX (1)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_MIN (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_MAX (1)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_MIN (0)
#define CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_MAX (1)
#define CANSIG_FSM_noncriticalErrors_watchdogFault_MIN (0)
#define CANSIG_FSM_noncriticalErrors_watchdogFault_MAX (1)
#define CANSIG_FSM_noncriticalErrors_bspdFault_MIN (0)
#define CANSIG_FSM_noncriticalErrors_bspdFault_MAX (1)
#define CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_MIN (0)
#define CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_MAX (3)
#define CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_MIN (0)
#define CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_MAX (3)
#define CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_MIN (0)
#define CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_MAX (3)
#define CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_MIN (0)
#define CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_MAX (3)
#define CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_MIN (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_MAX (3)
#define CANSIG_FSM_noncriticalErrors_brakePressureSc_MIN (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureSc_MAX (1)
#define CANSIG_FSM_noncriticalErrors_brakePressureOc_MIN (0)
#define CANSIG_FSM_noncriticalErrors_brakePressureOc_MAX (1)
#define CANSIG_FSM_noncriticalErrors_steeringWheelBroke_MIN (0)
#define CANSIG_FSM_noncriticalErrors_steeringWheelBroke_MAX (1)


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

