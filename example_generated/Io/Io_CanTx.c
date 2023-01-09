/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off

/* ------------------------------- Includes ------------------------------- */

#include "Io_CanTx.h"
#include <string.h>
#include <FreeRTOS.h>
#include <portmacro.h>
#include "Io_SharedCanMsg.h"
#include "Io_SharedCan.h"
#include "App_CanTx.h"
#include "App_CanUtils.h"

/* ---------------------- Static Function Prototypes ---------------------- */

/**
 * Pack and send the  TX msg JctVitals.
 */
static void App_CanTx_JctVitals_SendPeriodic(void);

/**
 * Pack and send the  TX msg JctAirShutdownErrors.
 */
static void App_CanTx_JctAirShutdownErrors_SendPeriodic(void);

/**
 * Pack and send the  TX msg JctMotorShutdownErrors.
 */
static void App_CanTx_JctMotorShutdownErrors_SendPeriodic(void);

/**
 * Pack and send the  TX msg JctStatus.
 */
static void App_CanTx_JctStatus_SendPeriodic(void);

/* --------------------- Public Function Definitions ---------------------- */

void Io_CanTx_Enqueue1HzMsgs()
{
    App_CanTx_JctVitals_SendPeriodic();
    App_CanTx_JctAirShutdownErrors_SendPeriodic();
}

void Io_CanTx_Enqueue100HzMsgs()
{
}

void Io_CanTx_EnqueueOtherPeriodicMsgs(uint32_t time_ms)
{
    if (time_ms % CAN_MSG_JCT_MOTOR_SHUTDOWN_ERRORS_CYCLE_TIME_MS == 0)
    {
        App_CanTx_JctMotorShutdownErrors_SendPeriodic();
    }
    
    if (time_ms % CAN_MSG_JCT_STATUS_CYCLE_TIME_MS == 0)
    {
        App_CanTx_JctStatus_SendPeriodic();
    }
    
}

void App_CanTx_JctWarnings_SendAperiodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CAN_MSG_JCT_WARNINGS_ID;
    tx_msg.dlc = CAN_MSG_JCT_WARNINGS_BYTES;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JctWarnings_Pack(App_CanTx_JctWarnings_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Append msg to TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

void App_CanTx_JCT_AlertSet_SendAperiodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CAN_MSG_JCT_ALERT_SET_ID;
    tx_msg.dlc = CAN_MSG_JCT_ALERT_SET_BYTES;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_AlertSet_Pack(App_CanTx_JCT_AlertSet_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Append msg to TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

void App_CanTx_JCT_AlertCleared_SendAperiodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CAN_MSG_JCT_ALERT_CLEARED_ID;
    tx_msg.dlc = CAN_MSG_JCT_ALERT_CLEARED_BYTES;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_AlertCleared_Pack(App_CanTx_JCT_AlertCleared_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Append msg to TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

/* --------------------- Static Function Definitions ---------------------- */

static void App_CanTx_JctVitals_SendPeriodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CAN_MSG_JCT_VITALS_ID;
    tx_msg.dlc = CAN_MSG_JCT_VITALS_BYTES;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JctVitals_Pack(App_CanTx_JctVitals_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Append msg to TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void App_CanTx_JctAirShutdownErrors_SendPeriodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CAN_MSG_JCT_AIR_SHUTDOWN_ERRORS_ID;
    tx_msg.dlc = CAN_MSG_JCT_AIR_SHUTDOWN_ERRORS_BYTES;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JctAirShutdownErrors_Pack(App_CanTx_JctAirShutdownErrors_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Append msg to TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void App_CanTx_JctMotorShutdownErrors_SendPeriodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CAN_MSG_JCT_MOTOR_SHUTDOWN_ERRORS_ID;
    tx_msg.dlc = CAN_MSG_JCT_MOTOR_SHUTDOWN_ERRORS_BYTES;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JctMotorShutdownErrors_Pack(App_CanTx_JctMotorShutdownErrors_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Append msg to TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void App_CanTx_JctStatus_SendPeriodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CAN_MSG_JCT_STATUS_ID;
    tx_msg.dlc = CAN_MSG_JCT_STATUS_BYTES;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JctStatus_Pack(App_CanTx_JctStatus_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Append msg to TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

