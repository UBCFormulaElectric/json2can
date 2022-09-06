/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ---------------------------------- Includes ---------------------------------- */

#include <string.h>
#include <FreeRTOS.h>
#include <portmacro.h>
#include "Io_CanTx.h"
#include "Io_SharedCanMsg.h"
#include "Io_SharedCan.h"
#include "App_CanUtils.h"
#include "App_CanTx.h" 

/* ---------------------------- Struct declarations ----------------------------- */



/* --------------------------------- Variables ---------------------------------- */



/* ------------------------------ Static functions ------------------------------ */



/* ---------------------------- Function definitions ---------------------------- */

void Io_CanTx_Enqueue1kHzMessages(const uint32_t current_ms) 
{

}

void Io_CanTx_Enqueue100HzMessages(const uint32_t current_ms) 
{

}

void Io_CanTx_Enqueue10HzMessages(const uint32_t current_ms) 
{

}

void Io_CanTx_Enqueue1HzMessages(const uint32_t current_ms) 
{
    App_CanTx_JSONCANTest_VITALS_Send();
    App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_Send();
    App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_Send();
    App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Send();
    App_CanTx_JSONCANTest_STATUS_Send();
}

void App_CanTx_JSONCANTest_VITALS_Send(void) 
{
    // Prepare CAN message header for message JSONCANTest_VITALS
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JSONCANTest_VITALS_ID;
    tx_msg.dlc = CANMSG_JSONCANTest_VITALS_LENGTH;

    // Prepare CAN message payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanMsgs_JSONCANTest_VITALS_Pack(App_CanTx_JSONCANTest_VITALS_GetMessageSignals(), tx_msg.data);
    vPortExitCritical();

    // Send to back of TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

void App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_Send(void) 
{
    // Prepare CAN message header for message JSONCANTest_NON_CRITICAL_ERRORS
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JSONCANTest_NON_CRITICAL_ERRORS_ID;
    tx_msg.dlc = CANMSG_JSONCANTest_NON_CRITICAL_ERRORS_LENGTH;

    // Prepare CAN message payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanMsgs_JSONCANTest_NON_CRITICAL_ERRORS_Pack(App_CanTx_JSONCANTest_NON_CRITICAL_ERRORS_GetMessageSignals(), tx_msg.data);
    vPortExitCritical();

    // Send to back of TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

void App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_Send(void) 
{
    // Prepare CAN message header for message JSONCANTest_AIR_SHUTDOWN_ERRORS
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JSONCANTest_AIR_SHUTDOWN_ERRORS_ID;
    tx_msg.dlc = CANMSG_JSONCANTest_AIR_SHUTDOWN_ERRORS_LENGTH;

    // Prepare CAN message payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanMsgs_JSONCANTest_AIR_SHUTDOWN_ERRORS_Pack(App_CanTx_JSONCANTest_AIR_SHUTDOWN_ERRORS_GetMessageSignals(), tx_msg.data);
    vPortExitCritical();

    // Send to back of TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

void App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Send(void) 
{
    // Prepare CAN message header for message JSONCANTest_MOTOR_SHUTDOWN_ERRORS
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_ID;
    tx_msg.dlc = CANMSG_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_LENGTH;

    // Prepare CAN message payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanMsgs_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_Pack(App_CanTx_JSONCANTest_MOTOR_SHUTDOWN_ERRORS_GetMessageSignals(), tx_msg.data);
    vPortExitCritical();

    // Send to back of TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

void App_CanTx_JSONCANTest_STATUS_Send(void) 
{
    // Prepare CAN message header for message JSONCANTest_STATUS
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JSONCANTest_STATUS_ID;
    tx_msg.dlc = CANMSG_JSONCANTest_STATUS_LENGTH;

    // Prepare CAN message payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanMsgs_JSONCANTest_STATUS_Pack(App_CanTx_JSONCANTest_STATUS_GetMessageSignals(), tx_msg.data);
    vPortExitCritical();

    // Send to back of TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}
