/**
 * @note This file is auto-generated. Do not modify!
 */
// clang-format off

#pragma once

/* ------------------------------- Includes ------------------------------- */

#include "App_CanUtils.h"

/* ------------------------------- Structs -------------------------------- */

/**
 * Struct for holding all messages transmitted by JCT (i.e. the TX table).
 */
typedef struct
{
    JCT_vitals_Signals JCT_vitals_signals;
    JCT_noncriticalErrors_Signals JCT_noncriticalErrors_signals;
    JCT_AIRShutdownErrors_Signals JCT_AIRShutdownErrors_signals;
    JCT_motorShutdownErrors_Signals JCT_motorShutdownErrors_signals;
    JCT_status_Signals JCT_status_signals;
    JCT_AlertSet_Signals JCT_AlertSet_signals;
    JCT_AlertCleared_Signals JCT_AlertCleared_signals;
} JCT_TxMsgs;


/* ------------------------- Function Prototypes -------------------------- */

/**
 * Initialize TX signals to their starting values.
 */
void App_CanTx_Init();

/**
 * Update value stored in TX table of signal heartbeat in msg JCT_vitals.
 */
void App_CanTx_JCT_vitals_heartbeat_Set(bool value);

/**
 * Update value stored in TX table of signal timestamp in msg JCT_vitals.
 */
void App_CanTx_JCT_vitals_timestamp_Set(uint32_t value);

/**
 * Update value stored in TX table of signal watchdogTimeout in msg JCT_noncriticalErrors.
 */
void App_CanTx_JCT_noncriticalErrors_watchdogTimeout_Set(bool value);

/**
 * Update value stored in TX table of signal boardOvertemp in msg JCT_noncriticalErrors.
 */
void App_CanTx_JCT_noncriticalErrors_boardOvertemp_Set(bool value);

/**
 * Update value stored in TX table of signal boardOvervoltage in msg JCT_noncriticalErrors.
 */
void App_CanTx_JCT_noncriticalErrors_boardOvervoltage_Set(bool value);

/**
 * Update value stored in TX table of signal dummyAirShutdown in msg JCT_AIRShutdownErrors.
 */
void App_CanTx_JCT_AIRShutdownErrors_dummyAirShutdown_Set(bool value);

/**
 * Update value stored in TX table of signal dummyMotorShutdown in msg JCT_motorShutdownErrors.
 */
void App_CanTx_JCT_motorShutdownErrors_dummyMotorShutdown_Set(bool value);

/**
 * Update value stored in TX table of signal contactorsClosed in msg JCT_status.
 */
void App_CanTx_JCT_status_contactorsClosed_Set(AirState value);

/**
 * Update value stored in TX table of signal current in msg JCT_status.
 */
void App_CanTx_JCT_status_current_Set(float value);

/**
 * Update value stored in TX table of signal voltage in msg JCT_status.
 */
void App_CanTx_JCT_status_voltage_Set(float value);

/**
 * Update value stored in TX table of signal unsigned_tester in msg JCT_status.
 */
void App_CanTx_JCT_status_unsigned_tester_Set(int value);

/**
 * Update value stored in TX table of signal JCT_AlertSet in msg JCT_AlertSet.
 */
void App_CanTx_JCT_AlertSet_JCT_AlertSet_Set(JCT_Alert value);

/**
 * Update value stored in TX table of signal JCT_AlertCleared in msg JCT_AlertCleared.
 */
void App_CanTx_JCT_AlertCleared_JCT_AlertCleared_Set(JCT_Alert value);

/**
 * Return value from TX table of signal heartbeat in msg JCT_vitals.
 */
bool App_CanTx_JCT_vitals_heartbeat_Get();

/**
 * Return value from TX table of signal timestamp in msg JCT_vitals.
 */
uint32_t App_CanTx_JCT_vitals_timestamp_Get();

/**
 * Return value from TX table of signal watchdogTimeout in msg JCT_noncriticalErrors.
 */
bool App_CanTx_JCT_noncriticalErrors_watchdogTimeout_Get();

/**
 * Return value from TX table of signal boardOvertemp in msg JCT_noncriticalErrors.
 */
bool App_CanTx_JCT_noncriticalErrors_boardOvertemp_Get();

/**
 * Return value from TX table of signal boardOvervoltage in msg JCT_noncriticalErrors.
 */
bool App_CanTx_JCT_noncriticalErrors_boardOvervoltage_Get();

/**
 * Return value from TX table of signal dummyAirShutdown in msg JCT_AIRShutdownErrors.
 */
bool App_CanTx_JCT_AIRShutdownErrors_dummyAirShutdown_Get();

/**
 * Return value from TX table of signal dummyMotorShutdown in msg JCT_motorShutdownErrors.
 */
bool App_CanTx_JCT_motorShutdownErrors_dummyMotorShutdown_Get();

/**
 * Return value from TX table of signal contactorsClosed in msg JCT_status.
 */
AirState App_CanTx_JCT_status_contactorsClosed_Get();

/**
 * Return value from TX table of signal current in msg JCT_status.
 */
float App_CanTx_JCT_status_current_Get();

/**
 * Return value from TX table of signal voltage in msg JCT_status.
 */
float App_CanTx_JCT_status_voltage_Get();

/**
 * Return value from TX table of signal unsigned_tester in msg JCT_status.
 */
int App_CanTx_JCT_status_unsigned_tester_Get();

/**
 * Return value from TX table of signal JCT_AlertSet in msg JCT_AlertSet.
 */
JCT_Alert App_CanTx_JCT_AlertSet_JCT_AlertSet_Get();

/**
 * Return value from TX table of signal JCT_AlertCleared in msg JCT_AlertCleared.
 */
JCT_Alert App_CanTx_JCT_AlertCleared_JCT_AlertCleared_Get();

/**
 * Returns pointer to the struct of msg JCT_vitals signals in the TX table.
 */
const JCT_vitals_Signals* App_CanTx_JCT_vitals_GetData();

/**
 * Returns pointer to the struct of msg JCT_noncriticalErrors signals in the TX table.
 */
const JCT_noncriticalErrors_Signals* App_CanTx_JCT_noncriticalErrors_GetData();

/**
 * Returns pointer to the struct of msg JCT_AIRShutdownErrors signals in the TX table.
 */
const JCT_AIRShutdownErrors_Signals* App_CanTx_JCT_AIRShutdownErrors_GetData();

/**
 * Returns pointer to the struct of msg JCT_motorShutdownErrors signals in the TX table.
 */
const JCT_motorShutdownErrors_Signals* App_CanTx_JCT_motorShutdownErrors_GetData();

/**
 * Returns pointer to the struct of msg JCT_status signals in the TX table.
 */
const JCT_status_Signals* App_CanTx_JCT_status_GetData();

/**
 * Returns pointer to the struct of msg JCT_AlertSet signals in the TX table.
 */
const JCT_AlertSet_Signals* App_CanTx_JCT_AlertSet_GetData();

/**
 * Returns pointer to the struct of msg JCT_AlertCleared signals in the TX table.
 */
const JCT_AlertCleared_Signals* App_CanTx_JCT_AlertCleared_GetData();

