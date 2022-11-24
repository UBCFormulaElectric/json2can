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
 * Pack and send the  TX msg JCT_vitals.
 */
static void App_CanTx_JCT_vitals_Send1Hz();

/**
 * Pack and send the  TX msg JCT_AIRShutdownErrors.
 */
static void App_CanTx_JCT_AIRShutdownErrors_Send1Hz();

/**
 * Pack and send the  TX msg JCT_motorShutdownErrors.
 */
static void App_CanTx_JCT_motorShutdownErrors_Send1Hz();

/**
 * Pack and send the  TX msg JCT_status.
 */
static void App_CanTx_JCT_status_Send1Hz();

/* --------------------- Public Function Definitions ---------------------- */

void Io_CanTx_Enqueue100HzMsgs()
{
}

void Io_CanTx_Enqueue10HzMsgs()
{
}

void Io_CanTx_Enqueue1HzMsgs()
{
    App_CanTx_JCT_vitals_Send1Hz();
    App_CanTx_JCT_AIRShutdownErrors_Send1Hz();
    App_CanTx_JCT_motorShutdownErrors_Send1Hz();
    App_CanTx_JCT_status_Send1Hz();
}

void App_CanTx_JCT_noncriticalErrors_SendAperiodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_noncriticalErrors_ID;
    tx_msg.dlc = CANMSG_JCT_noncriticalErrors_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_noncriticalErrors_Pack(App_CanTx_JCT_noncriticalErrors_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

void App_CanTx_JCT_AlertSet_SendAperiodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_AlertSet_ID;
    tx_msg.dlc = CANMSG_JCT_AlertSet_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_AlertSet_Pack(App_CanTx_JCT_AlertSet_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

void App_CanTx_JCT_AlertCleared_SendAperiodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_AlertCleared_ID;
    tx_msg.dlc = CANMSG_JCT_AlertCleared_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_AlertCleared_Pack(App_CanTx_JCT_AlertCleared_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

/* --------------------- Static Function Definitions ---------------------- */

static void App_CanTx_JCT_vitals_Send1Hz()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_vitals_ID;
    tx_msg.dlc = CANMSG_JCT_vitals_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_vitals_Pack(App_CanTx_JCT_vitals_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void App_CanTx_JCT_AIRShutdownErrors_Send1Hz()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_AIRShutdownErrors_ID;
    tx_msg.dlc = CANMSG_JCT_AIRShutdownErrors_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_AIRShutdownErrors_Pack(App_CanTx_JCT_AIRShutdownErrors_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void App_CanTx_JCT_motorShutdownErrors_Send1Hz()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_motorShutdownErrors_ID;
    tx_msg.dlc = CANMSG_JCT_motorShutdownErrors_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_motorShutdownErrors_Pack(App_CanTx_JCT_motorShutdownErrors_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void App_CanTx_JCT_status_Send1Hz()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_status_ID;
    tx_msg.dlc = CANMSG_JCT_status_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    App_CanUtils_JCT_status_Pack(App_CanTx_JCT_status_GetData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

