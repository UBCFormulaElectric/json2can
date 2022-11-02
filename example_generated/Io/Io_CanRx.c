/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ------------------------------- Includes ------------------------------- */

#include "Io_CanRx.h"
#include "App_CanRx.h"
#include "App_CanUtils.h"

/* ------------------------- Function Definitions ------------------------- */

bool Io_CanRx_FilterMessageId(uint32_t std_id)
{
    bool is_found = false;
    switch (std_id)
    {
        case CANMSG_FSM_apps_ID:
        case CANMSG_FSM_noncriticalErrors_ID:
        {
            is_found = true;
            break;
        }
        default:
        {
            // Do nothing
            break;
        }
    }
    
    return is_found;
}

void Io_CanRx_UpdateRxTableWithMessage(struct CanMsg* msg)
{
    switch (msg->std_id)
    {
        case CANMSG_FSM_apps_ID:
        {
            FSM_apps_Signals out_msg;
            app_canUtils_FSM_apps_unpack(msg->data, &out_msg);
            
            app_canRx_FSM_apps_pappsMappedPedalPercentage_updateValue(out_msg.pappsMappedPedalPercentage_value);
            app_canRx_FSM_apps_sappsMappedPedalPercentage_updateValue(out_msg.sappsMappedPedalPercentage_value);
            break;
        }
        case CANMSG_FSM_noncriticalErrors_ID:
        {
            FSM_noncriticalErrors_Signals out_msg;
            app_canUtils_FSM_noncriticalErrors_unpack(msg->data, &out_msg);
            
            app_canRx_FSM_noncriticalErrors_pappsOutOfRange_updateValue(out_msg.pappsOutOfRange_value);
            app_canRx_FSM_noncriticalErrors_sappsOutOfRange_updateValue(out_msg.sappsOutOfRange_value);
            app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_updateValue(out_msg.stackWatermarkAboveThresholdTask1Hz_value);
            app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_updateValue(out_msg.stackWatermarkAboveThresholdTask1kHz_value);
            app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_updateValue(out_msg.stackWatermarkAboveThresholdTaskCanRx_value);
            app_canRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_updateValue(out_msg.stackWatermarkAboveThresholdTaskCanTx_value);
            app_canRx_FSM_noncriticalErrors_watchdogFault_updateValue(out_msg.watchdogFault_value);
            app_canRx_FSM_noncriticalErrors_bspdFault_updateValue(out_msg.bspdFault_value);
            app_canRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_updateValue(out_msg.leftWheelSpeedOutOfRange_value);
            app_canRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_updateValue(out_msg.rightWheelSpeedOutOfRange_value);
            app_canRx_FSM_noncriticalErrors_flowRateOutOfRange_updateValue(out_msg.flowRateOutOfRange_value);
            app_canRx_FSM_noncriticalErrors_steeringAngleOutOfRange_updateValue(out_msg.steeringAngleOutOfRange_value);
            app_canRx_FSM_noncriticalErrors_brakePressureOutOfRange_updateValue(out_msg.brakePressureOutOfRange_value);
            app_canRx_FSM_noncriticalErrors_brakePressureSc_updateValue(out_msg.brakePressureSc_value);
            app_canRx_FSM_noncriticalErrors_brakePressureOc_updateValue(out_msg.brakePressureOc_value);
            app_canRx_FSM_noncriticalErrors_steeringWheelBroke_updateValue(out_msg.steeringWheelBroke_value);
            break;
        }
        default:
        {
            // Do nothing
            break;
        }
    }
}

