/**
 * @note This file is auto-generated. !!! Do not modify !!!
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
static void app_canTx_JCT_vitals_send1Hz();

/**
 * Pack and send the  TX msg JCT_AIRShutdownErrors.
 */
static void app_canTx_JCT_AIRShutdownErrors_send1Hz();

/**
 * Pack and send the  TX msg JCT_motorShutdownErrors.
 */
static void app_canTx_JCT_motorShutdownErrors_send1Hz();

/**
 * Pack and send the  TX msg JCT_status.
 */
static void app_canTx_JCT_status_send1Hz();

/* --------------------- Public Function Definitions ---------------------- */

void io_canTx_enqueue100HzMsgs()
{
}

void io_canTx_enqueue10HzMsgs()
{
}

void io_canTx_enqueue1HzMsgs()
{
    app_canTx_JCT_vitals_send1Hz();
    app_canTx_JCT_AIRShutdownErrors_send1Hz();
    app_canTx_JCT_motorShutdownErrors_send1Hz();
    app_canTx_JCT_status_send1Hz();
}

void app_canTx_JCT_noncriticalErrors_sendAperiodic()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_noncriticalErrors_ID;
    tx_msg.dlc = CANMSG_JCT_noncriticalErrors_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    app_canUtils_JCT_noncriticalErrors_pack(app_canTx_JCT_noncriticalErrors_getData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

/* --------------------- Static Function Definitions ---------------------- */

static void app_canTx_JCT_vitals_send1Hz()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_vitals_ID;
    tx_msg.dlc = CANMSG_JCT_vitals_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    app_canUtils_JCT_vitals_pack(app_canTx_JCT_vitals_getData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void app_canTx_JCT_AIRShutdownErrors_send1Hz()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_AIRShutdownErrors_ID;
    tx_msg.dlc = CANMSG_JCT_AIRShutdownErrors_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    app_canUtils_JCT_AIRShutdownErrors_pack(app_canTx_JCT_AIRShutdownErrors_getData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void app_canTx_JCT_motorShutdownErrors_send1Hz()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_motorShutdownErrors_ID;
    tx_msg.dlc = CANMSG_JCT_motorShutdownErrors_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    app_canUtils_JCT_motorShutdownErrors_pack(app_canTx_JCT_motorShutdownErrors_getData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

static void app_canTx_JCT_status_send1Hz()
{
    // Prepare msg header
    struct CanMsg tx_msg;
    tx_msg.std_id = CANMSG_JCT_status_ID;
    tx_msg.dlc = CANMSG_JCT_status_DLC;
    
    // Prepare CAN msg payload (The packing function isn't thread-safe so we must guard it)
    vPortEnterCritical();
    app_canUtils_JCT_status_pack(app_canTx_JCT_status_getData(), tx_msg.data);
    vPortExitCritical();
    
    // Enqueue msg in TX FIFO
    Io_SharedCan_TxMessageQueueSendtoBack(&tx_msg);
}

