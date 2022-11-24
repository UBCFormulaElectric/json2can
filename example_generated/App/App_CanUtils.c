/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off

#include "App_CanUtils.h"

/* ------------------ Static Packing/Unpacking Functions ------------------ */

/**
 * Shift input left and apply mask, for packing.
 */
static uint8_t packShiftLeft(uint32_t input, uint8_t shift, uint8_t mask)
{
    return (uint8_t)((uint8_t)(input << shift) & (uint8_t)mask);
}

/**
 * Shift input right and apply mask, for packing.
 */
static uint8_t packShiftRight(uint32_t input, uint8_t shift, uint8_t mask)
{
    return (uint8_t)((uint8_t)(input >> shift) & (uint8_t)mask);
}

/**
 * Apply mask, then shift input left by shift bits, for unpacking.
 */
static uint32_t unpackShiftLeft(uint8_t input, uint8_t shift, uint8_t mask)
{
    return (uint32_t)((uint32_t)(input & mask) << shift);
}

/**
 * Apply mask, then shift input left by shift bits, for unpacking.
 */
static uint32_t unpackShiftRight(uint8_t input, uint8_t shift, uint8_t mask)
{
    return (uint32_t)((uint32_t)(input & mask) >> shift);
}


/* ----------------------- Encoding/Decoding Macros ----------------------- */

/**
 * Encode real signal value to payload representation, w/ scale and offset.
 */
#define ENCODE_SIGNAL(input, scale, offset, type) ((uint32_t)((type)(input - offset) / (type)scale))

/**
 * Decode payload representation of signal to signal value, w/ scale and offset.
 */
#define DECODE_SIGNAL(input, scale, offset, type) ((type)((type)input * (type)scale + (type)offset))


/* ------------------------- Function Definitions ------------------------- */

void App_CanUtils_JCT_vitals_Pack(const JCT_vitals_Signals* const in_msg, uint8_t* const out_data)
{
    // Pack 5-byte payload for message JCT_vitals.
    // |xxxxxxxx|xxxxxxxx|xxxxxxxx|_______B|BBBBBBBB|BBBBBBBB|BBBBBBBB|BBBBBBBA|
    
    // Pack 1-bit signal heartbeat into payload (at bit 0 to bit 1).
    const bool heartbeat_val = in_msg->heartbeat_value;
    const uint32_t heartbeat_raw = ENCODE_SIGNAL(heartbeat_val, CANSIG_JCT_vitals_heartbeat_SCALE, CANSIG_JCT_vitals_heartbeat_OFFSET, uint32_t);
    out_data[0] |= packShiftRight(heartbeat_raw, 0, 0x1);   // Packs bits _______# of byte 0
    
    // Pack 32-bit signal timestamp into payload (at bit 1 to bit 33).
    const uint32_t timestamp_val = in_msg->timestamp_value;
    const uint32_t timestamp_raw = ENCODE_SIGNAL(timestamp_val, CANSIG_JCT_vitals_timestamp_SCALE, CANSIG_JCT_vitals_timestamp_OFFSET, uint32_t);
    out_data[0] |= packShiftLeft(timestamp_raw, 1, 0xfe);   // Packs bits #######_ of byte 0
    out_data[1] |= packShiftRight(timestamp_raw, 7, 0xff);   // Packs bits ######## of byte 1
    out_data[2] |= packShiftRight(timestamp_raw, 15, 0xff);   // Packs bits ######## of byte 2
    out_data[3] |= packShiftRight(timestamp_raw, 23, 0xff);   // Packs bits ######## of byte 3
    out_data[4] |= packShiftRight(timestamp_raw, 31, 0x1);   // Packs bits _______# of byte 4
    
}

void App_CanUtils_JCT_noncriticalErrors_Pack(const JCT_noncriticalErrors_Signals* const in_msg, uint8_t* const out_data)
{
    // Pack 1-byte payload for message JCT_noncriticalErrors.
    // |xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|_____CBA|
    
    // Pack 1-bit signal watchdogTimeout into payload (at bit 0 to bit 1).
    const bool watchdogTimeout_val = in_msg->watchdogTimeout_value;
    const uint32_t watchdogTimeout_raw = ENCODE_SIGNAL(watchdogTimeout_val, CANSIG_JCT_noncriticalErrors_watchdogTimeout_SCALE, CANSIG_JCT_noncriticalErrors_watchdogTimeout_OFFSET, uint32_t);
    out_data[0] |= packShiftRight(watchdogTimeout_raw, 0, 0x1);   // Packs bits _______# of byte 0
    
    // Pack 1-bit signal boardOvertemp into payload (at bit 1 to bit 2).
    const bool boardOvertemp_val = in_msg->boardOvertemp_value;
    const uint32_t boardOvertemp_raw = ENCODE_SIGNAL(boardOvertemp_val, CANSIG_JCT_noncriticalErrors_boardOvertemp_SCALE, CANSIG_JCT_noncriticalErrors_boardOvertemp_OFFSET, uint32_t);
    out_data[0] |= packShiftLeft(boardOvertemp_raw, 1, 0x2);   // Packs bits ______#_ of byte 0
    
    // Pack 1-bit signal boardOvervoltage into payload (at bit 2 to bit 3).
    const bool boardOvervoltage_val = in_msg->boardOvervoltage_value;
    const uint32_t boardOvervoltage_raw = ENCODE_SIGNAL(boardOvervoltage_val, CANSIG_JCT_noncriticalErrors_boardOvervoltage_SCALE, CANSIG_JCT_noncriticalErrors_boardOvervoltage_OFFSET, uint32_t);
    out_data[0] |= packShiftLeft(boardOvervoltage_raw, 2, 0x4);   // Packs bits _____#__ of byte 0
    
}

void App_CanUtils_JCT_AIRShutdownErrors_Pack(const JCT_AIRShutdownErrors_Signals* const in_msg, uint8_t* const out_data)
{
    // Pack 1-byte payload for message JCT_AIRShutdownErrors.
    // |xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|_______A|
    
    // Pack 1-bit signal dummyAirShutdown into payload (at bit 0 to bit 1).
    const bool dummyAirShutdown_val = in_msg->dummyAirShutdown_value;
    const uint32_t dummyAirShutdown_raw = ENCODE_SIGNAL(dummyAirShutdown_val, CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_SCALE, CANSIG_JCT_AIRShutdownErrors_dummyAirShutdown_OFFSET, uint32_t);
    out_data[0] |= packShiftRight(dummyAirShutdown_raw, 0, 0x1);   // Packs bits _______# of byte 0
    
}

void App_CanUtils_JCT_motorShutdownErrors_Pack(const JCT_motorShutdownErrors_Signals* const in_msg, uint8_t* const out_data)
{
    // Pack 1-byte payload for message JCT_motorShutdownErrors.
    // |xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|_______A|
    
    // Pack 1-bit signal dummyMotorShutdown into payload (at bit 0 to bit 1).
    const bool dummyMotorShutdown_val = in_msg->dummyMotorShutdown_value;
    const uint32_t dummyMotorShutdown_raw = ENCODE_SIGNAL(dummyMotorShutdown_val, CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_SCALE, CANSIG_JCT_motorShutdownErrors_dummyMotorShutdown_OFFSET, uint32_t);
    out_data[0] |= packShiftRight(dummyMotorShutdown_raw, 0, 0x1);   // Packs bits _______# of byte 0
    
}

void App_CanUtils_JCT_status_Pack(const JCT_status_Signals* const in_msg, uint8_t* const out_data)
{
    // Pack 5-byte payload for message JCT_status.
    // |xxxxxxxx|xxxxxxxx|xxxxxxxx|__DDDDDD|DDDDDDCC|CCCCCCCC|CCBBBBBB|BBBBBBAA|
    
    // Pack 2-bit signal contactorsClosed into payload (at bit 0 to bit 2).
    const AirState contactorsClosed_val = in_msg->contactorsClosed_value;
    const uint32_t contactorsClosed_raw = ENCODE_SIGNAL(contactorsClosed_val, CANSIG_JCT_status_contactorsClosed_SCALE, CANSIG_JCT_status_contactorsClosed_OFFSET, uint32_t);
    out_data[0] |= packShiftRight(contactorsClosed_raw, 0, 0x3);   // Packs bits ______## of byte 0
    
    // Pack 12-bit signal current into payload (at bit 2 to bit 14).
    const float current_val = in_msg->current_value;
    const uint32_t current_raw = ENCODE_SIGNAL(current_val, CANSIG_JCT_status_current_SCALE, CANSIG_JCT_status_current_OFFSET, float);
    out_data[0] |= packShiftLeft(current_raw, 2, 0xfc);   // Packs bits ######__ of byte 0
    out_data[1] |= packShiftRight(current_raw, 6, 0x3f);   // Packs bits __###### of byte 1
    
    // Pack 12-bit signal voltage into payload (at bit 14 to bit 26).
    const float voltage_val = in_msg->voltage_value;
    const uint32_t voltage_raw = ENCODE_SIGNAL(voltage_val, CANSIG_JCT_status_voltage_SCALE, CANSIG_JCT_status_voltage_OFFSET, float);
    out_data[1] |= packShiftLeft(voltage_raw, 6, 0xc0);   // Packs bits ##______ of byte 1
    out_data[2] |= packShiftRight(voltage_raw, 2, 0xff);   // Packs bits ######## of byte 2
    out_data[3] |= packShiftRight(voltage_raw, 10, 0x3);   // Packs bits ______## of byte 3
    
    // Pack 12-bit signal unsigned_tester into payload (at bit 26 to bit 38).
    const int unsigned_tester_val = in_msg->unsigned_tester_value;
    const uint32_t unsigned_tester_raw = ENCODE_SIGNAL(unsigned_tester_val, CANSIG_JCT_status_unsigned_tester_SCALE, CANSIG_JCT_status_unsigned_tester_OFFSET, int);
    out_data[3] |= packShiftLeft(unsigned_tester_raw, 2, 0xfc);   // Packs bits ######__ of byte 3
    out_data[4] |= packShiftRight(unsigned_tester_raw, 6, 0x3f);   // Packs bits __###### of byte 4
    
}

void App_CanUtils_JCT_AlertSet_Pack(const JCT_AlertSet_Signals* const in_msg, uint8_t* const out_data)
{
    // Pack 1-byte payload for message JCT_AlertSet.
    // |xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|_____AAA|
    
    // Pack 3-bit signal JCT_AlertSet into payload (at bit 0 to bit 3).
    const JCT_Alert JCT_AlertSet_val = in_msg->JCT_AlertSet_value;
    const uint32_t JCT_AlertSet_raw = ENCODE_SIGNAL(JCT_AlertSet_val, CANSIG_JCT_AlertSet_JCT_AlertSet_SCALE, CANSIG_JCT_AlertSet_JCT_AlertSet_OFFSET, uint32_t);
    out_data[0] |= packShiftRight(JCT_AlertSet_raw, 0, 0x7);   // Packs bits _____### of byte 0
    
}

void App_CanUtils_JCT_AlertCleared_Pack(const JCT_AlertCleared_Signals* const in_msg, uint8_t* const out_data)
{
    // Pack 1-byte payload for message JCT_AlertCleared.
    // |xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|_____AAA|
    
    // Pack 3-bit signal JCT_AlertCleared into payload (at bit 0 to bit 3).
    const JCT_Alert JCT_AlertCleared_val = in_msg->JCT_AlertCleared_value;
    const uint32_t JCT_AlertCleared_raw = ENCODE_SIGNAL(JCT_AlertCleared_val, CANSIG_JCT_AlertCleared_JCT_AlertCleared_SCALE, CANSIG_JCT_AlertCleared_JCT_AlertCleared_OFFSET, uint32_t);
    out_data[0] |= packShiftRight(JCT_AlertCleared_raw, 0, 0x7);   // Packs bits _____### of byte 0
    
}

void App_CanUtils_FSM_apps_Unpack(const uint8_t* const in_data, FSM_apps_Signals* const out_msg)
{
    // Unpack 8-byte payload for message FSM_apps.
    // |BBBBBBBB|BBBBBBBB|BBBBBBBB|BBBBBBBB|AAAAAAAA|AAAAAAAA|AAAAAAAA|AAAAAAAA|
    
    // Unpack 32-bit signal pappsMappedPedalPercentage from payload (at bit 0 to bit 32).
    uint32_t pappsMappedPedalPercentage_raw = 0;
    pappsMappedPedalPercentage_raw |= unpackShiftRight(in_data[0], 0, 0xff);   // Unpacks bits ######## of msg byte 0
    pappsMappedPedalPercentage_raw |= unpackShiftLeft(in_data[1], 8, 0xff);   // Unpacks bits ######## of msg byte 1
    pappsMappedPedalPercentage_raw |= unpackShiftLeft(in_data[2], 16, 0xff);   // Unpacks bits ######## of msg byte 2
    pappsMappedPedalPercentage_raw |= unpackShiftLeft(in_data[3], 24, 0xff);   // Unpacks bits ######## of msg byte 3
    const float pappsMappedPedalPercentage_val = DECODE_SIGNAL(pappsMappedPedalPercentage_raw, CANSIG_FSM_apps_pappsMappedPedalPercentage_SCALE, CANSIG_FSM_apps_pappsMappedPedalPercentage_OFFSET, float);
    out_msg->pappsMappedPedalPercentage_value = pappsMappedPedalPercentage_val;
    
    // Unpack 32-bit signal sappsMappedPedalPercentage from payload (at bit 32 to bit 64).
    uint32_t sappsMappedPedalPercentage_raw = 0;
    sappsMappedPedalPercentage_raw |= unpackShiftRight(in_data[4], 0, 0xff);   // Unpacks bits ######## of msg byte 4
    sappsMappedPedalPercentage_raw |= unpackShiftLeft(in_data[5], 8, 0xff);   // Unpacks bits ######## of msg byte 5
    sappsMappedPedalPercentage_raw |= unpackShiftLeft(in_data[6], 16, 0xff);   // Unpacks bits ######## of msg byte 6
    sappsMappedPedalPercentage_raw |= unpackShiftLeft(in_data[7], 24, 0xff);   // Unpacks bits ######## of msg byte 7
    const float sappsMappedPedalPercentage_val = DECODE_SIGNAL(sappsMappedPedalPercentage_raw, CANSIG_FSM_apps_sappsMappedPedalPercentage_SCALE, CANSIG_FSM_apps_sappsMappedPedalPercentage_OFFSET, float);
    out_msg->sappsMappedPedalPercentage_value = sappsMappedPedalPercentage_val;
    
}

void App_CanUtils_FSM_noncriticalErrors_Unpack(const uint8_t* const in_data, FSM_noncriticalErrors_Signals* const out_msg)
{
    // Unpack 3-byte payload for message FSM_noncriticalErrors.
    // |xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|xxxxxxxx|___PONMM|LLKKJJII|HGFEDCBA|
    
    // Unpack 1-bit signal pappsOutOfRange from payload (at bit 0 to bit 1).
    uint32_t pappsOutOfRange_raw = 0;
    pappsOutOfRange_raw |= unpackShiftRight(in_data[0], 0, 0x1);   // Unpacks bits _______# of msg byte 0
    const bool pappsOutOfRange_val = DECODE_SIGNAL(pappsOutOfRange_raw, CANSIG_FSM_noncriticalErrors_pappsOutOfRange_SCALE, CANSIG_FSM_noncriticalErrors_pappsOutOfRange_OFFSET, uint32_t);
    out_msg->pappsOutOfRange_value = pappsOutOfRange_val;
    
    // Unpack 1-bit signal sappsOutOfRange from payload (at bit 1 to bit 2).
    uint32_t sappsOutOfRange_raw = 0;
    sappsOutOfRange_raw |= unpackShiftRight(in_data[0], 1, 0x2);   // Unpacks bits ______#_ of msg byte 0
    const bool sappsOutOfRange_val = DECODE_SIGNAL(sappsOutOfRange_raw, CANSIG_FSM_noncriticalErrors_sappsOutOfRange_SCALE, CANSIG_FSM_noncriticalErrors_sappsOutOfRange_OFFSET, uint32_t);
    out_msg->sappsOutOfRange_value = sappsOutOfRange_val;
    
    // Unpack 1-bit signal stackWatermarkAboveThresholdTask1Hz from payload (at bit 2 to bit 3).
    uint32_t stackWatermarkAboveThresholdTask1Hz_raw = 0;
    stackWatermarkAboveThresholdTask1Hz_raw |= unpackShiftRight(in_data[0], 2, 0x4);   // Unpacks bits _____#__ of msg byte 0
    const bool stackWatermarkAboveThresholdTask1Hz_val = DECODE_SIGNAL(stackWatermarkAboveThresholdTask1Hz_raw, CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_SCALE, CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_OFFSET, uint32_t);
    out_msg->stackWatermarkAboveThresholdTask1Hz_value = stackWatermarkAboveThresholdTask1Hz_val;
    
    // Unpack 1-bit signal stackWatermarkAboveThresholdTask1kHz from payload (at bit 3 to bit 4).
    uint32_t stackWatermarkAboveThresholdTask1kHz_raw = 0;
    stackWatermarkAboveThresholdTask1kHz_raw |= unpackShiftRight(in_data[0], 3, 0x8);   // Unpacks bits ____#___ of msg byte 0
    const bool stackWatermarkAboveThresholdTask1kHz_val = DECODE_SIGNAL(stackWatermarkAboveThresholdTask1kHz_raw, CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_SCALE, CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_OFFSET, uint32_t);
    out_msg->stackWatermarkAboveThresholdTask1kHz_value = stackWatermarkAboveThresholdTask1kHz_val;
    
    // Unpack 1-bit signal stackWatermarkAboveThresholdTaskCanRx from payload (at bit 4 to bit 5).
    uint32_t stackWatermarkAboveThresholdTaskCanRx_raw = 0;
    stackWatermarkAboveThresholdTaskCanRx_raw |= unpackShiftRight(in_data[0], 4, 0x10);   // Unpacks bits ___#____ of msg byte 0
    const bool stackWatermarkAboveThresholdTaskCanRx_val = DECODE_SIGNAL(stackWatermarkAboveThresholdTaskCanRx_raw, CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_SCALE, CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_OFFSET, uint32_t);
    out_msg->stackWatermarkAboveThresholdTaskCanRx_value = stackWatermarkAboveThresholdTaskCanRx_val;
    
    // Unpack 1-bit signal stackWatermarkAboveThresholdTaskCanTx from payload (at bit 5 to bit 6).
    uint32_t stackWatermarkAboveThresholdTaskCanTx_raw = 0;
    stackWatermarkAboveThresholdTaskCanTx_raw |= unpackShiftRight(in_data[0], 5, 0x20);   // Unpacks bits __#_____ of msg byte 0
    const bool stackWatermarkAboveThresholdTaskCanTx_val = DECODE_SIGNAL(stackWatermarkAboveThresholdTaskCanTx_raw, CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_SCALE, CANSIG_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_OFFSET, uint32_t);
    out_msg->stackWatermarkAboveThresholdTaskCanTx_value = stackWatermarkAboveThresholdTaskCanTx_val;
    
    // Unpack 1-bit signal watchdogFault from payload (at bit 6 to bit 7).
    uint32_t watchdogFault_raw = 0;
    watchdogFault_raw |= unpackShiftRight(in_data[0], 6, 0x40);   // Unpacks bits _#______ of msg byte 0
    const bool watchdogFault_val = DECODE_SIGNAL(watchdogFault_raw, CANSIG_FSM_noncriticalErrors_watchdogFault_SCALE, CANSIG_FSM_noncriticalErrors_watchdogFault_OFFSET, uint32_t);
    out_msg->watchdogFault_value = watchdogFault_val;
    
    // Unpack 1-bit signal bspdFault from payload (at bit 7 to bit 8).
    uint32_t bspdFault_raw = 0;
    bspdFault_raw |= unpackShiftRight(in_data[0], 7, 0x80);   // Unpacks bits #_______ of msg byte 0
    const bool bspdFault_val = DECODE_SIGNAL(bspdFault_raw, CANSIG_FSM_noncriticalErrors_bspdFault_SCALE, CANSIG_FSM_noncriticalErrors_bspdFault_OFFSET, uint32_t);
    out_msg->bspdFault_value = bspdFault_val;
    
    // Unpack 2-bit signal leftWheelSpeedOutOfRange from payload (at bit 8 to bit 10).
    uint32_t leftWheelSpeedOutOfRange_raw = 0;
    leftWheelSpeedOutOfRange_raw |= unpackShiftRight(in_data[1], 0, 0x3);   // Unpacks bits ______## of msg byte 1
    const uint32_t leftWheelSpeedOutOfRange_val = DECODE_SIGNAL(leftWheelSpeedOutOfRange_raw, CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_SCALE, CANSIG_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_OFFSET, uint32_t);
    out_msg->leftWheelSpeedOutOfRange_value = leftWheelSpeedOutOfRange_val;
    
    // Unpack 2-bit signal rightWheelSpeedOutOfRange from payload (at bit 10 to bit 12).
    uint32_t rightWheelSpeedOutOfRange_raw = 0;
    rightWheelSpeedOutOfRange_raw |= unpackShiftRight(in_data[1], 2, 0xc);   // Unpacks bits ____##__ of msg byte 1
    const uint32_t rightWheelSpeedOutOfRange_val = DECODE_SIGNAL(rightWheelSpeedOutOfRange_raw, CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_SCALE, CANSIG_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_OFFSET, uint32_t);
    out_msg->rightWheelSpeedOutOfRange_value = rightWheelSpeedOutOfRange_val;
    
    // Unpack 2-bit signal flowRateOutOfRange from payload (at bit 12 to bit 14).
    uint32_t flowRateOutOfRange_raw = 0;
    flowRateOutOfRange_raw |= unpackShiftRight(in_data[1], 4, 0x30);   // Unpacks bits __##____ of msg byte 1
    const uint32_t flowRateOutOfRange_val = DECODE_SIGNAL(flowRateOutOfRange_raw, CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_SCALE, CANSIG_FSM_noncriticalErrors_flowRateOutOfRange_OFFSET, uint32_t);
    out_msg->flowRateOutOfRange_value = flowRateOutOfRange_val;
    
    // Unpack 2-bit signal steeringAngleOutOfRange from payload (at bit 14 to bit 16).
    uint32_t steeringAngleOutOfRange_raw = 0;
    steeringAngleOutOfRange_raw |= unpackShiftRight(in_data[1], 6, 0xc0);   // Unpacks bits ##______ of msg byte 1
    const uint32_t steeringAngleOutOfRange_val = DECODE_SIGNAL(steeringAngleOutOfRange_raw, CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_SCALE, CANSIG_FSM_noncriticalErrors_steeringAngleOutOfRange_OFFSET, uint32_t);
    out_msg->steeringAngleOutOfRange_value = steeringAngleOutOfRange_val;
    
    // Unpack 2-bit signal brakePressureOutOfRange from payload (at bit 16 to bit 18).
    uint32_t brakePressureOutOfRange_raw = 0;
    brakePressureOutOfRange_raw |= unpackShiftRight(in_data[2], 0, 0x3);   // Unpacks bits ______## of msg byte 2
    const uint32_t brakePressureOutOfRange_val = DECODE_SIGNAL(brakePressureOutOfRange_raw, CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_SCALE, CANSIG_FSM_noncriticalErrors_brakePressureOutOfRange_OFFSET, uint32_t);
    out_msg->brakePressureOutOfRange_value = brakePressureOutOfRange_val;
    
    // Unpack 1-bit signal brakePressureSc from payload (at bit 18 to bit 19).
    uint32_t brakePressureSc_raw = 0;
    brakePressureSc_raw |= unpackShiftRight(in_data[2], 2, 0x4);   // Unpacks bits _____#__ of msg byte 2
    const bool brakePressureSc_val = DECODE_SIGNAL(brakePressureSc_raw, CANSIG_FSM_noncriticalErrors_brakePressureSc_SCALE, CANSIG_FSM_noncriticalErrors_brakePressureSc_OFFSET, uint32_t);
    out_msg->brakePressureSc_value = brakePressureSc_val;
    
    // Unpack 1-bit signal brakePressureOc from payload (at bit 19 to bit 20).
    uint32_t brakePressureOc_raw = 0;
    brakePressureOc_raw |= unpackShiftRight(in_data[2], 3, 0x8);   // Unpacks bits ____#___ of msg byte 2
    const bool brakePressureOc_val = DECODE_SIGNAL(brakePressureOc_raw, CANSIG_FSM_noncriticalErrors_brakePressureOc_SCALE, CANSIG_FSM_noncriticalErrors_brakePressureOc_OFFSET, uint32_t);
    out_msg->brakePressureOc_value = brakePressureOc_val;
    
    // Unpack 1-bit signal steeringWheelBroke from payload (at bit 20 to bit 21).
    uint32_t steeringWheelBroke_raw = 0;
    steeringWheelBroke_raw |= unpackShiftRight(in_data[2], 4, 0x10);   // Unpacks bits ___#____ of msg byte 2
    const bool steeringWheelBroke_val = DECODE_SIGNAL(steeringWheelBroke_raw, CANSIG_FSM_noncriticalErrors_steeringWheelBroke_SCALE, CANSIG_FSM_noncriticalErrors_steeringWheelBroke_OFFSET, uint32_t);
    out_msg->steeringWheelBroke_value = steeringWheelBroke_val;
    
}

