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
        case CAN_MSG_FSM_APPS_ID:
        case CAN_MSG_FSM_WARNINGS_ID:
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
        case CAN_MSG_FSM_APPS_ID:
        {
            FsmApps_Signals out_msg;
            App_CanUtils_FsmApps_Unpack(msg->data, &out_msg);
            
            App_CanRx_FsmApps_PappsMappedPedalPercentage_UpdateValue(out_msg.PappsMappedPedalPercentage_value);
            App_CanRx_FsmApps_SappsMappedPedalPercentage_UpdateValue(out_msg.SappsMappedPedalPercentage_value);
            break;
        }
        case CAN_MSG_FSM_WARNINGS_ID:
        {
            FsmWarnings_Signals out_msg;
            App_CanUtils_FsmWarnings_Unpack(msg->data, &out_msg);
            
            App_CanRx_FsmWarnings_PappsOutOfRange_UpdateValue(out_msg.PappsOutOfRange_value);
            App_CanRx_FsmWarnings_SappsOutOfRange_UpdateValue(out_msg.SappsOutOfRange_value);
            App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1Hz_UpdateValue(out_msg.StackWatermarkAboveThresholdTask1Hz_value);
            App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTask1kHz_UpdateValue(out_msg.StackWatermarkAboveThresholdTask1kHz_value);
            App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanRx_UpdateValue(out_msg.StackWatermarkAboveThresholdTaskCanRx_value);
            App_CanRx_FsmWarnings_StackWatermarkAboveThresholdTaskCanTx_UpdateValue(out_msg.StackWatermarkAboveThresholdTaskCanTx_value);
            App_CanRx_FsmWarnings_WatchdogFault_UpdateValue(out_msg.WatchdogFault_value);
            App_CanRx_FsmWarnings_BspdFault_UpdateValue(out_msg.BspdFault_value);
            App_CanRx_FsmWarnings_LeftWheelSpeedOutOfRange_UpdateValue(out_msg.LeftWheelSpeedOutOfRange_value);
            App_CanRx_FsmWarnings_RightWheelSpeedOutOfRange_UpdateValue(out_msg.RightWheelSpeedOutOfRange_value);
            App_CanRx_FsmWarnings_FlowRateOutOfRange_UpdateValue(out_msg.FlowRateOutOfRange_value);
            App_CanRx_FsmWarnings_SteeringAngleOutOfRange_UpdateValue(out_msg.SteeringAngleOutOfRange_value);
            App_CanRx_FsmWarnings_BrakePressureOutOfRange_UpdateValue(out_msg.BrakePressureOutOfRange_value);
            App_CanRx_FsmWarnings_BrakePressureSc_UpdateValue(out_msg.BrakePressureSc_value);
            App_CanRx_FsmWarnings_BrakePressureOc_UpdateValue(out_msg.BrakePressureOc_value);
            App_CanRx_FsmWarnings_SteeringWheelBroke_UpdateValue(out_msg.SteeringWheelBroke_value);
            break;
        }
        default:
        {
            // Do nothing
            break;
        }
    }
}

