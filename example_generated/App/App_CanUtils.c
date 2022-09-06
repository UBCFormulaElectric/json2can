/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ---------------------------------- Includes ---------------------------------- */

#include "App_CanUtils.h" 

/* ---------------------------- Struct declarations ----------------------------- */



/* --------------------------------- Variables ---------------------------------- */



/* ------------------------------ Static functions ------------------------------ */

/**
 * @brief Shift input left by shift bits, and apply mask, for packing CAN messages.
 */ 
uint8_t PackShiftLeft(uint32_t input, uint8_t shift, uint8_t mask) 
{
    return (uint8_t)((uint8_t)(input << shift) & mask);
}

/**
 * @brief Shift input right by shift bits, and apply mask, for packing CAN messages.
 */ 
uint8_t PackShiftRight(uint32_t input, uint8_t shift, uint8_t mask) 
{
    return (uint8_t)((uint8_t)(input >> shift) & mask);
}

/**
 * @brief Apply mask, then shift input left by shift bits, for unpacking CAN messages.
 */ 
uint32_t UnpackShiftLeft(uint8_t input, uint8_t shift, uint8_t mask) 
{
    return (uint32_t)((uint32_t)(input & mask) << shift);
}

/**
 * @brief Apply mask, then shift input right by shift bits, for unpacking CAN messages.
 */ 
uint32_t UnpackShiftRight(uint8_t input, uint8_t shift, uint8_t mask) 
{
    return (uint32_t)((uint32_t)(input & mask) >> shift);
}

/**
 * @brief Encode signal value to get CAN payload represenation.
 */ 
uint32_t Encode_Uint(uint32_t input, uint32_t scale, uint32_t offset) 
{
    return (uint32_t)((input - offset) / scale);
}

/**
 * @brief Encode signal value to get CAN payload represenation.
 */ 
uint32_t Encode_Int(int input, int scale, int offset) 
{
    return (uint32_t)((input - offset) / scale);
}

/**
 * @brief Encode signal value to get CAN payload represenation.
 */ 
uint32_t Encode_Float(float input, float scale, float offset) 
{
    return (uint32_t)((input - offset) / scale);
}

/**
 * @brief Decode payload bits to get signal value.
 */ 
uint32_t Decode_Uint(uint32_t input, uint32_t scale, uint32_t offset) 
{
    return (uint32_t)((uint32_t)input * scale + offset);
}

/**
 * @brief Decode payload bits to get signal value.
 */ 
int Decode_Int(uint32_t input, int scale, int offset) 
{
    return (int)((int)input * scale + offset);
}

/**
 * @brief Decode payload bits to get signal value.
 */ 
float Decode_Float(uint32_t input, float scale, float offset) 
{
    return (float)((float)input * scale + offset);
}

/* ---------------------------- Function definitions ---------------------------- */

void App_CanMsgs_JSONCANTest_VITALS_Pack(const JSONCANTest_VITALS_Signals* const in_msg, uint8_t* const out_data) 
{
    // Pack 5-byte (40-bit) message JSONCANTest_VITALS.
    
    // Pack 1-bit signal HEARTBEAT into message (at bit 0 to bit 1).
    const bool HEARTBEAT_value = in_msg->HEARTBEAT_value;
    const uint32_t HEARTBEAT_raw = Encode_Uint(HEARTBEAT_value, CANSIG_JSONCANTest_VITALS_HEARTBEAT_SCALE, CANSIG_JSONCANTest_VITALS_HEARTBEAT_OFFSET);
    out_data[0] |= PackShiftRight(HEARTBEAT_raw, 0, 0x1);   // Packs bits _______# (mask=0b00000001) of message byte 0

    // Pack 32-bit signal TIMESTAMP into message (at bit 1 to bit 33).
    const uint32_t TIMESTAMP_value = in_msg->TIMESTAMP_value;
    const uint32_t TIMESTAMP_raw = Encode_Uint(TIMESTAMP_value, CANSIG_JSONCANTest_VITALS_TIMESTAMP_SCALE, CANSIG_JSONCANTest_VITALS_TIMESTAMP_OFFSET);
    out_data[0] |= PackShiftLeft(TIMESTAMP_raw, 1, 0xfe);   // Packs bits #######_ (mask=0b11111110) of message byte 0
    out_data[1] |= PackShiftRight(TIMESTAMP_raw, 7, 0xff);   // Packs bits ######## (mask=0b11111111) of message byte 1
    out_data[2] |= PackShiftRight(TIMESTAMP_raw, 15, 0xff);   // Packs bits ######## (mask=0b11111111) of message byte 2
    out_data[3] |= PackShiftRight(TIMESTAMP_raw, 23, 0xff);   // Packs bits ######## (mask=0b11111111) of message byte 3
    out_data[4] |= PackShiftRight(TIMESTAMP_raw, 31, 0x1);   // Packs bits _______# (mask=0b00000001) of message byte 4
}

void App_CanMsgs_JSONCANTest_NON_CRITICAL_ERRORS_Pack(const JSONCANTest_NON_CRITICAL_ERRORS_Signals* const in_msg, uint8_t* const out_data) 
{
    // Pack 1-byte (8-bit) message JSONCANTest_NON_CRITICAL_ERRORS.
    
    // Pack 1-bit signal WATCHDOG_TIMEOUT into message (at bit 0 to bit 1).
    const bool WATCHDOG_TIMEOUT_value = in_msg->WATCHDOG_TIMEOUT_value;
    const uint32_t WATCHDOG_TIMEOUT_raw = Encode_Uint(WATCHDOG_TIMEOUT_value, CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_SCALE, CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_OFFSET);
    out_data[0] |= PackShiftRight(WATCHDOG_TIMEOUT_raw, 0, 0x1);   // Packs bits _______# (mask=0b00000001) of message byte 0

    // Pack 1-bit signal BOARD_OVERTEMP into message (at bit 1 to bit 2).
    const bool BOARD_OVERTEMP_value = in_msg->BOARD_OVERTEMP_value;
    const uint32_t BOARD_OVERTEMP_raw = Encode_Uint(BOARD_OVERTEMP_value, CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_SCALE, CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERTEMP_OFFSET);
    out_data[0] |= PackShiftLeft(BOARD_OVERTEMP_raw, 1, 0x2);   // Packs bits ______#_ (mask=0b00000010) of message byte 0

    // Pack 1-bit signal BOARD_OVERVOLTAGE into message (at bit 2 to bit 3).
    const bool BOARD_OVERVOLTAGE_value = in_msg->BOARD_OVERVOLTAGE_value;
    const uint32_t BOARD_OVERVOLTAGE_raw = Encode_Uint(BOARD_OVERVOLTAGE_value, CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_SCALE, CANSIG_JSONCANTest_NON_CRITICAL_ERRORS_BOARD_OVERVOLTAGE_OFFSET);
    out_data[0] |= PackShiftLeft(BOARD_OVERVOLTAGE_raw, 2, 0x4);   // Packs bits _____#__ (mask=0b00000100) of message byte 0
}

void App_CanMsgs_JSONCANTest_AIR_SHUTDOWN_ERRORS_Pack(const JSONCANTest_AIR_SHUTDOWN_ERRORS_Signals* const in_msg, uint8_t* const out_data) 
{
    // Pack 1-byte (8-bit) message JSONCANTest_AIR_SHUTDOWN_ERRORS.
    
    // Pack 1-bit signal DUMMY_AIR_SHUTDOWN into message (at bit 0 to bit 1).
    const bool DUMMY_AIR_SHUTDOWN_value = in_msg->DUMMY_AIR_SHUTDOWN_value;
    const uint32_t DUMMY_AIR_SHUTDOWN_raw = Encode_Uint(DUMMY_AIR_SHUTDOWN_value, CANSIG_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_SCALE, CANSIG_JSONCANTest_AIR_SHUTDOWN_ERRORS_DUMMY_AIR_SHUTDOWN_OFFSET);
    out_data[0] |= PackShiftRight(DUMMY_AIR_SHUTDOWN_raw, 0, 0x1);   // Packs bits _______# (mask=0b00000001) of message byte 0
}

void App_CanMsgs_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Pack(const JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Signals* const in_msg, uint8_t* const out_data) 
{
    // Pack 1-byte (8-bit) message JSONCANTest_MOTOR_SHUTDOWN_ERRORS.
    
    // Pack 1-bit signal DUMMY_MOTOR_SHUTDOWN into message (at bit 0 to bit 1).
    const bool DUMMY_MOTOR_SHUTDOWN_value = in_msg->DUMMY_MOTOR_SHUTDOWN_value;
    const uint32_t DUMMY_MOTOR_SHUTDOWN_raw = Encode_Uint(DUMMY_MOTOR_SHUTDOWN_value, CANSIG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_SCALE, CANSIG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_DUMMY_MOTOR_SHUTDOWN_OFFSET);
    out_data[0] |= PackShiftRight(DUMMY_MOTOR_SHUTDOWN_raw, 0, 0x1);   // Packs bits _______# (mask=0b00000001) of message byte 0
}

void App_CanMsgs_JSONCANTest_STATUS_Pack(const JSONCANTest_STATUS_Signals* const in_msg, uint8_t* const out_data) 
{
    // Pack 4-byte (32-bit) message JSONCANTest_STATUS.
    
    // Pack 1-bit signal CONTACTORS_CLOSED into message (at bit 0 to bit 1).
    const AIR_STATE CONTACTORS_CLOSED_value = in_msg->CONTACTORS_CLOSED_value;
    const uint32_t CONTACTORS_CLOSED_raw = Encode_Uint(CONTACTORS_CLOSED_value, CANSIG_JSONCANTest_STATUS_CONTACTORS_CLOSED_SCALE, CANSIG_JSONCANTest_STATUS_CONTACTORS_CLOSED_OFFSET);
    out_data[0] |= PackShiftRight(CONTACTORS_CLOSED_raw, 0, 0x1);   // Packs bits _______# (mask=0b00000001) of message byte 0

    // Pack 12-bit signal CURRENT into message (at bit 1 to bit 13).
    const float CURRENT_value = in_msg->CURRENT_value;
    const uint32_t CURRENT_raw = Encode_Float(CURRENT_value, CANSIG_JSONCANTest_STATUS_CURRENT_SCALE, CANSIG_JSONCANTest_STATUS_CURRENT_OFFSET);
    out_data[0] |= PackShiftLeft(CURRENT_raw, 1, 0xfe);   // Packs bits #######_ (mask=0b11111110) of message byte 0
    out_data[1] |= PackShiftRight(CURRENT_raw, 7, 0x1f);   // Packs bits ___##### (mask=0b00011111) of message byte 1

    // Pack 12-bit signal VOLTAGE into message (at bit 13 to bit 25).
    const float VOLTAGE_value = in_msg->VOLTAGE_value;
    const uint32_t VOLTAGE_raw = Encode_Float(VOLTAGE_value, CANSIG_JSONCANTest_STATUS_VOLTAGE_SCALE, CANSIG_JSONCANTest_STATUS_VOLTAGE_OFFSET);
    out_data[1] |= PackShiftLeft(VOLTAGE_raw, 5, 0xe0);   // Packs bits ###_____ (mask=0b11100000) of message byte 1
    out_data[2] |= PackShiftRight(VOLTAGE_raw, 3, 0xff);   // Packs bits ######## (mask=0b11111111) of message byte 2
    out_data[3] |= PackShiftRight(VOLTAGE_raw, 11, 0x1);   // Packs bits _______# (mask=0b00000001) of message byte 3
}

void App_CanMsgs_FSM_APPS_Unpack(const uint8_t* const in_data, FSM_APPS_Signals* const out_msg) 
{
    // Unpack 8-byte (64-bit) message FSM_APPS.
    
    // Unpack 32-bit signal Papps_Mapped_Pedal_Percentage from CAN message payload (at bit 0 to bit 32).
    uint32_t Papps_Mapped_Pedal_Percentage_raw = 0;
    Papps_Mapped_Pedal_Percentage_raw |= UnpackShiftRight(in_data[0], 0, 0xff);   // Unpacks bits ######## of message byte 0 (mask=0b11111111)
    Papps_Mapped_Pedal_Percentage_raw |= UnpackShiftLeft(in_data[1], 8, 0xff);   // Unpacks bits ######## of message byte 1 (mask=0b11111111)
    Papps_Mapped_Pedal_Percentage_raw |= UnpackShiftLeft(in_data[2], 16, 0xff);   // Unpacks bits ######## of message byte 2 (mask=0b11111111)
    Papps_Mapped_Pedal_Percentage_raw |= UnpackShiftLeft(in_data[3], 24, 0xff);   // Unpacks bits ######## of message byte 3 (mask=0b11111111)
    const float Papps_Mapped_Pedal_Percentage_value = Decode_Float(Papps_Mapped_Pedal_Percentage_raw, CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_SCALE, CANSIG_FSM_APPS_Papps_Mapped_Pedal_Percentage_OFFSET);
    out_msg->Papps_Mapped_Pedal_Percentage_value = Papps_Mapped_Pedal_Percentage_value;

    // Unpack 32-bit signal Sapps_Mapped_Pedal_Percentage from CAN message payload (at bit 32 to bit 64).
    uint32_t Sapps_Mapped_Pedal_Percentage_raw = 0;
    Sapps_Mapped_Pedal_Percentage_raw |= UnpackShiftRight(in_data[4], 0, 0xff);   // Unpacks bits ######## of message byte 4 (mask=0b11111111)
    Sapps_Mapped_Pedal_Percentage_raw |= UnpackShiftLeft(in_data[5], 8, 0xff);   // Unpacks bits ######## of message byte 5 (mask=0b11111111)
    Sapps_Mapped_Pedal_Percentage_raw |= UnpackShiftLeft(in_data[6], 16, 0xff);   // Unpacks bits ######## of message byte 6 (mask=0b11111111)
    Sapps_Mapped_Pedal_Percentage_raw |= UnpackShiftLeft(in_data[7], 24, 0xff);   // Unpacks bits ######## of message byte 7 (mask=0b11111111)
    const float Sapps_Mapped_Pedal_Percentage_value = Decode_Float(Sapps_Mapped_Pedal_Percentage_raw, CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_SCALE, CANSIG_FSM_APPS_Sapps_Mapped_Pedal_Percentage_OFFSET);
    out_msg->Sapps_Mapped_Pedal_Percentage_value = Sapps_Mapped_Pedal_Percentage_value;
}

void App_CanMsgs_FSM_NON_CRITICAL_ERRORS_Unpack(const uint8_t* const in_data, FSM_NON_CRITICAL_ERRORS_Signals* const out_msg) 
{
    // Unpack 3-byte (24-bit) message FSM_NON_CRITICAL_ERRORS.
    
    // Unpack 1-bit signal papps_out_of_range from CAN message payload (at bit 0 to bit 1).
    uint32_t papps_out_of_range_raw = 0;
    papps_out_of_range_raw |= UnpackShiftRight(in_data[0], 0, 0x1);   // Unpacks bits _______# of message byte 0 (mask=0b00000001)
    const bool papps_out_of_range_value = Decode_Uint(papps_out_of_range_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_OFFSET);
    out_msg->papps_out_of_range_value = papps_out_of_range_value;

    // Unpack 1-bit signal sapps_out_of_range from CAN message payload (at bit 1 to bit 2).
    uint32_t sapps_out_of_range_raw = 0;
    sapps_out_of_range_raw |= UnpackShiftRight(in_data[0], 1, 0x2);   // Unpacks bits ______#_ of message byte 0 (mask=0b00000010)
    const bool sapps_out_of_range_value = Decode_Uint(sapps_out_of_range_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_OFFSET);
    out_msg->sapps_out_of_range_value = sapps_out_of_range_value;

    // Unpack 1-bit signal STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ from CAN message payload (at bit 2 to bit 3).
    uint32_t STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_raw = 0;
    STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_raw |= UnpackShiftRight(in_data[0], 2, 0x4);   // Unpacks bits _____#__ of message byte 0 (mask=0b00000100)
    const bool STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_value = Decode_Uint(STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_OFFSET);
    out_msg->STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_value = STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_value;

    // Unpack 1-bit signal STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ from CAN message payload (at bit 3 to bit 4).
    uint32_t STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_raw = 0;
    STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_raw |= UnpackShiftRight(in_data[0], 3, 0x8);   // Unpacks bits ____#___ of message byte 0 (mask=0b00001000)
    const bool STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_value = Decode_Uint(STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_OFFSET);
    out_msg->STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_value = STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_value;

    // Unpack 1-bit signal STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX from CAN message payload (at bit 4 to bit 5).
    uint32_t STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_raw = 0;
    STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_raw |= UnpackShiftRight(in_data[0], 4, 0x10);   // Unpacks bits ___#____ of message byte 0 (mask=0b00010000)
    const bool STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_value = Decode_Uint(STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_OFFSET);
    out_msg->STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_value = STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_value;

    // Unpack 1-bit signal STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX from CAN message payload (at bit 5 to bit 6).
    uint32_t STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_raw = 0;
    STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_raw |= UnpackShiftRight(in_data[0], 5, 0x20);   // Unpacks bits __#_____ of message byte 0 (mask=0b00100000)
    const bool STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_value = Decode_Uint(STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_OFFSET);
    out_msg->STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_value = STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_value;

    // Unpack 1-bit signal WATCHDOG_TIMEOUT from CAN message payload (at bit 6 to bit 7).
    uint32_t WATCHDOG_TIMEOUT_raw = 0;
    WATCHDOG_TIMEOUT_raw |= UnpackShiftRight(in_data[0], 6, 0x40);   // Unpacks bits _#______ of message byte 0 (mask=0b01000000)
    const bool WATCHDOG_TIMEOUT_value = Decode_Uint(WATCHDOG_TIMEOUT_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_OFFSET);
    out_msg->WATCHDOG_TIMEOUT_value = WATCHDOG_TIMEOUT_value;

    // Unpack 1-bit signal BSPD_FAULT from CAN message payload (at bit 7 to bit 8).
    uint32_t BSPD_FAULT_raw = 0;
    BSPD_FAULT_raw |= UnpackShiftRight(in_data[0], 7, 0x80);   // Unpacks bits #_______ of message byte 0 (mask=0b10000000)
    const bool BSPD_FAULT_value = Decode_Uint(BSPD_FAULT_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_OFFSET);
    out_msg->BSPD_FAULT_value = BSPD_FAULT_value;

    // Unpack 2-bit signal LEFT_WHEEL_SPEED_OUT_OF_RANGE from CAN message payload (at bit 8 to bit 10).
    uint32_t LEFT_WHEEL_SPEED_OUT_OF_RANGE_raw = 0;
    LEFT_WHEEL_SPEED_OUT_OF_RANGE_raw |= UnpackShiftRight(in_data[1], 0, 0x3);   // Unpacks bits ______## of message byte 1 (mask=0b00000011)
    const uint32_t LEFT_WHEEL_SPEED_OUT_OF_RANGE_value = Decode_Uint(LEFT_WHEEL_SPEED_OUT_OF_RANGE_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_OFFSET);
    out_msg->LEFT_WHEEL_SPEED_OUT_OF_RANGE_value = LEFT_WHEEL_SPEED_OUT_OF_RANGE_value;

    // Unpack 2-bit signal RIGHT_WHEEL_SPEED_OUT_OF_RANGE from CAN message payload (at bit 10 to bit 12).
    uint32_t RIGHT_WHEEL_SPEED_OUT_OF_RANGE_raw = 0;
    RIGHT_WHEEL_SPEED_OUT_OF_RANGE_raw |= UnpackShiftRight(in_data[1], 2, 0xc);   // Unpacks bits ____##__ of message byte 1 (mask=0b00001100)
    const uint32_t RIGHT_WHEEL_SPEED_OUT_OF_RANGE_value = Decode_Uint(RIGHT_WHEEL_SPEED_OUT_OF_RANGE_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_OFFSET);
    out_msg->RIGHT_WHEEL_SPEED_OUT_OF_RANGE_value = RIGHT_WHEEL_SPEED_OUT_OF_RANGE_value;

    // Unpack 2-bit signal FLOW_RATE_OUT_OF_RANGE from CAN message payload (at bit 12 to bit 14).
    uint32_t FLOW_RATE_OUT_OF_RANGE_raw = 0;
    FLOW_RATE_OUT_OF_RANGE_raw |= UnpackShiftRight(in_data[1], 4, 0x30);   // Unpacks bits __##____ of message byte 1 (mask=0b00110000)
    const uint32_t FLOW_RATE_OUT_OF_RANGE_value = Decode_Uint(FLOW_RATE_OUT_OF_RANGE_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_OFFSET);
    out_msg->FLOW_RATE_OUT_OF_RANGE_value = FLOW_RATE_OUT_OF_RANGE_value;

    // Unpack 2-bit signal STEERING_ANGLE_OUT_OF_RANGE from CAN message payload (at bit 14 to bit 16).
    uint32_t STEERING_ANGLE_OUT_OF_RANGE_raw = 0;
    STEERING_ANGLE_OUT_OF_RANGE_raw |= UnpackShiftRight(in_data[1], 6, 0xc0);   // Unpacks bits ##______ of message byte 1 (mask=0b11000000)
    const uint32_t STEERING_ANGLE_OUT_OF_RANGE_value = Decode_Uint(STEERING_ANGLE_OUT_OF_RANGE_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_OFFSET);
    out_msg->STEERING_ANGLE_OUT_OF_RANGE_value = STEERING_ANGLE_OUT_OF_RANGE_value;

    // Unpack 2-bit signal BRAKE_PRESSURE_OUT_OF_RANGE from CAN message payload (at bit 16 to bit 18).
    uint32_t BRAKE_PRESSURE_OUT_OF_RANGE_raw = 0;
    BRAKE_PRESSURE_OUT_OF_RANGE_raw |= UnpackShiftRight(in_data[2], 0, 0x3);   // Unpacks bits ______## of message byte 2 (mask=0b00000011)
    const uint32_t BRAKE_PRESSURE_OUT_OF_RANGE_value = Decode_Uint(BRAKE_PRESSURE_OUT_OF_RANGE_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_OFFSET);
    out_msg->BRAKE_PRESSURE_OUT_OF_RANGE_value = BRAKE_PRESSURE_OUT_OF_RANGE_value;

    // Unpack 1-bit signal BRAKE_PRESSURE_OPEN_SC from CAN message payload (at bit 18 to bit 19).
    uint32_t BRAKE_PRESSURE_OPEN_SC_raw = 0;
    BRAKE_PRESSURE_OPEN_SC_raw |= UnpackShiftRight(in_data[2], 2, 0x4);   // Unpacks bits _____#__ of message byte 2 (mask=0b00000100)
    const bool BRAKE_PRESSURE_OPEN_SC_value = Decode_Uint(BRAKE_PRESSURE_OPEN_SC_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_OFFSET);
    out_msg->BRAKE_PRESSURE_OPEN_SC_value = BRAKE_PRESSURE_OPEN_SC_value;

    // Unpack 1-bit signal BRAKE_PRESSURE_OPEN_OC from CAN message payload (at bit 19 to bit 20).
    uint32_t BRAKE_PRESSURE_OPEN_OC_raw = 0;
    BRAKE_PRESSURE_OPEN_OC_raw |= UnpackShiftRight(in_data[2], 3, 0x8);   // Unpacks bits ____#___ of message byte 2 (mask=0b00001000)
    const bool BRAKE_PRESSURE_OPEN_OC_value = Decode_Uint(BRAKE_PRESSURE_OPEN_OC_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_OFFSET);
    out_msg->BRAKE_PRESSURE_OPEN_OC_value = BRAKE_PRESSURE_OPEN_OC_value;

    // Unpack 1-bit signal STEERING_WHEEL_BROKE from CAN message payload (at bit 20 to bit 21).
    uint32_t STEERING_WHEEL_BROKE_raw = 0;
    STEERING_WHEEL_BROKE_raw |= UnpackShiftRight(in_data[2], 4, 0x10);   // Unpacks bits ___#____ of message byte 2 (mask=0b00010000)
    const bool STEERING_WHEEL_BROKE_value = Decode_Uint(STEERING_WHEEL_BROKE_raw, CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_SCALE, CANSIG_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_OFFSET);
    out_msg->STEERING_WHEEL_BROKE_value = STEERING_WHEEL_BROKE_value;
}
