/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ---------------------------------- Includes ---------------------------------- */

#include "Io_CanRx.h"
#include "App_CanUtils.h"
#include "App_CanRx.h" 

/* ---------------------------- Struct declarations ----------------------------- */



/* --------------------------------- Variables ---------------------------------- */



/* ------------------------------ Static functions ------------------------------ */



/* ---------------------------- Function definitions ---------------------------- */

void Io_CanRx_UpdateRxTableWithMessage(struct CanMsg* message) 
{
    switch (message->std_id)
    {
        case CANMSG_FSM_APPS_ID:
        {
            FSM_APPS_Signals out_msg;
            App_CanMsgs_FSM_APPS_Unpack(message->data, &out_msg);
            
            App_CanRx_FSM_APPS_Papps_Mapped_Pedal_Percentage_UpdateValue(out_msg.Papps_Mapped_Pedal_Percentage_value);
            App_CanRx_FSM_APPS_Sapps_Mapped_Pedal_Percentage_UpdateValue(out_msg.Sapps_Mapped_Pedal_Percentage_value);
            break;
        }
        case CANMSG_FSM_NON_CRITICAL_ERRORS_ID:
        {
            FSM_NON_CRITICAL_ERRORS_Signals out_msg;
            App_CanMsgs_FSM_NON_CRITICAL_ERRORS_Unpack(message->data, &out_msg);
            
            App_CanRx_FSM_NON_CRITICAL_ERRORS_papps_out_of_range_UpdateValue(out_msg.papps_out_of_range_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_sapps_out_of_range_UpdateValue(out_msg.sapps_out_of_range_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_UpdateValue(out_msg.STACK_WATERMARK_ABOVE_THRESHOLD_TASK1HZ_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_UpdateValue(out_msg.STACK_WATERMARK_ABOVE_THRESHOLD_TASK1KHZ_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_UpdateValue(out_msg.STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANRX_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_UpdateValue(out_msg.STACK_WATERMARK_ABOVE_THRESHOLD_TASKCANTX_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_WATCHDOG_TIMEOUT_UpdateValue(out_msg.WATCHDOG_TIMEOUT_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_BSPD_FAULT_UpdateValue(out_msg.BSPD_FAULT_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_LEFT_WHEEL_SPEED_OUT_OF_RANGE_UpdateValue(out_msg.LEFT_WHEEL_SPEED_OUT_OF_RANGE_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_RIGHT_WHEEL_SPEED_OUT_OF_RANGE_UpdateValue(out_msg.RIGHT_WHEEL_SPEED_OUT_OF_RANGE_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_FLOW_RATE_OUT_OF_RANGE_UpdateValue(out_msg.FLOW_RATE_OUT_OF_RANGE_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_ANGLE_OUT_OF_RANGE_UpdateValue(out_msg.STEERING_ANGLE_OUT_OF_RANGE_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OUT_OF_RANGE_UpdateValue(out_msg.BRAKE_PRESSURE_OUT_OF_RANGE_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_SC_UpdateValue(out_msg.BRAKE_PRESSURE_OPEN_SC_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_BRAKE_PRESSURE_OPEN_OC_UpdateValue(out_msg.BRAKE_PRESSURE_OPEN_OC_value);
            App_CanRx_FSM_NON_CRITICAL_ERRORS_STEERING_WHEEL_BROKE_UpdateValue(out_msg.STEERING_WHEEL_BROKE_value);
            break;
        }
        default:
        {
            break;
        }
    }
}

bool Io_CanRx_FilterMessageId(uint32_t std_id) 
{
    bool isFound = false;
    switch (std_id)
    {
        case CANMSG_FSM_APPS_ID:
        case CANMSG_FSM_NON_CRITICAL_ERRORS_ID:
        {
            isFound = true;
            break;
        }
        default:
        {
            break;
        }
    }
    return isFound;
}
