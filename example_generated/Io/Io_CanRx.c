/**
 * @note This file is auto-generated. Do not modify!
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
            App_CanUtils_FSM_apps_Unpack(msg->data, &out_msg);
            
            App_CanRx_FSM_apps_pappsMappedPedalPercentage_UpdateValue(out_msg.pappsMappedPedalPercentage_value);
            App_CanRx_FSM_apps_sappsMappedPedalPercentage_UpdateValue(out_msg.sappsMappedPedalPercentage_value);
            break;
        }
        case CANMSG_FSM_noncriticalErrors_ID:
        {
            FSM_noncriticalErrors_Signals out_msg;
            App_CanUtils_FSM_noncriticalErrors_Unpack(msg->data, &out_msg);
            
            App_CanRx_FSM_noncriticalErrors_pappsOutOfRange_UpdateValue(out_msg.pappsOutOfRange_value);
            App_CanRx_FSM_noncriticalErrors_sappsOutOfRange_UpdateValue(out_msg.sappsOutOfRange_value);
            App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1Hz_UpdateValue(out_msg.stackWatermarkAboveThresholdTask1Hz_value);
            App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTask1kHz_UpdateValue(out_msg.stackWatermarkAboveThresholdTask1kHz_value);
            App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanRx_UpdateValue(out_msg.stackWatermarkAboveThresholdTaskCanRx_value);
            App_CanRx_FSM_noncriticalErrors_stackWatermarkAboveThresholdTaskCanTx_UpdateValue(out_msg.stackWatermarkAboveThresholdTaskCanTx_value);
            App_CanRx_FSM_noncriticalErrors_watchdogFault_UpdateValue(out_msg.watchdogFault_value);
            App_CanRx_FSM_noncriticalErrors_bspdFault_UpdateValue(out_msg.bspdFault_value);
            App_CanRx_FSM_noncriticalErrors_leftWheelSpeedOutOfRange_UpdateValue(out_msg.leftWheelSpeedOutOfRange_value);
            App_CanRx_FSM_noncriticalErrors_rightWheelSpeedOutOfRange_UpdateValue(out_msg.rightWheelSpeedOutOfRange_value);
            App_CanRx_FSM_noncriticalErrors_flowRateOutOfRange_UpdateValue(out_msg.flowRateOutOfRange_value);
            App_CanRx_FSM_noncriticalErrors_steeringAngleOutOfRange_UpdateValue(out_msg.steeringAngleOutOfRange_value);
            App_CanRx_FSM_noncriticalErrors_brakePressureOutOfRange_UpdateValue(out_msg.brakePressureOutOfRange_value);
            App_CanRx_FSM_noncriticalErrors_brakePressureSc_UpdateValue(out_msg.brakePressureSc_value);
            App_CanRx_FSM_noncriticalErrors_brakePressureOc_UpdateValue(out_msg.brakePressureOc_value);
            App_CanRx_FSM_noncriticalErrors_steeringWheelBroke_UpdateValue(out_msg.steeringWheelBroke_value);
            break;
        }
        default:
        {
            // Do nothing
            break;
        }
    }
}

