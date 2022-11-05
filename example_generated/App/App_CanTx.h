/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* ------------------------------- Includes ------------------------------- */

#include <string.h>
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
} JCT_TxMsgs;


/* ------------------------- Function Prototypes -------------------------- */

/**
 * Initialize TX signals to their starting values.
 */
void app_canTx_init();

/**
 * Update value stored in TX table of signal heartbeat in msg JCT_vitals.
 */
void app_canTx_JCT_vitals_heartbeat_set(bool value);

/**
 * Update value stored in TX table of signal timestamp in msg JCT_vitals.
 */
void app_canTx_JCT_vitals_timestamp_set(uint32_t value);

/**
 * Update value stored in TX table of signal watchdogTimeout in msg JCT_noncriticalErrors.
 */
void app_canTx_JCT_noncriticalErrors_watchdogTimeout_set(bool value);

/**
 * Update value stored in TX table of signal boardOvertemp in msg JCT_noncriticalErrors.
 */
void app_canTx_JCT_noncriticalErrors_boardOvertemp_set(bool value);

/**
 * Update value stored in TX table of signal boardOvervoltage in msg JCT_noncriticalErrors.
 */
void app_canTx_JCT_noncriticalErrors_boardOvervoltage_set(bool value);

/**
 * Update value stored in TX table of signal dummyAirShutdown in msg JCT_AIRShutdownErrors.
 */
void app_canTx_JCT_AIRShutdownErrors_dummyAirShutdown_set(bool value);

/**
 * Update value stored in TX table of signal dummyMotorShutdown in msg JCT_motorShutdownErrors.
 */
void app_canTx_JCT_motorShutdownErrors_dummyMotorShutdown_set(bool value);

/**
 * Update value stored in TX table of signal contactorsClosed in msg JCT_status.
 */
void app_canTx_JCT_status_contactorsClosed_set(AirState value);

/**
 * Update value stored in TX table of signal current in msg JCT_status.
 */
void app_canTx_JCT_status_current_set(float value);

/**
 * Update value stored in TX table of signal voltage in msg JCT_status.
 */
void app_canTx_JCT_status_voltage_set(float value);

/**
 * Update value stored in TX table of signal unsigned_tester in msg JCT_status.
 */
void app_canTx_JCT_status_unsigned_tester_set(int value);

/**
 * Return value from TX table of signal heartbeat in msg JCT_vitals.
 */
bool app_canTx_JCT_vitals_heartbeat_get();

/**
 * Return value from TX table of signal timestamp in msg JCT_vitals.
 */
uint32_t app_canTx_JCT_vitals_timestamp_get();

/**
 * Return value from TX table of signal watchdogTimeout in msg JCT_noncriticalErrors.
 */
bool app_canTx_JCT_noncriticalErrors_watchdogTimeout_get();

/**
 * Return value from TX table of signal boardOvertemp in msg JCT_noncriticalErrors.
 */
bool app_canTx_JCT_noncriticalErrors_boardOvertemp_get();

/**
 * Return value from TX table of signal boardOvervoltage in msg JCT_noncriticalErrors.
 */
bool app_canTx_JCT_noncriticalErrors_boardOvervoltage_get();

/**
 * Return value from TX table of signal dummyAirShutdown in msg JCT_AIRShutdownErrors.
 */
bool app_canTx_JCT_AIRShutdownErrors_dummyAirShutdown_get();

/**
 * Return value from TX table of signal dummyMotorShutdown in msg JCT_motorShutdownErrors.
 */
bool app_canTx_JCT_motorShutdownErrors_dummyMotorShutdown_get();

/**
 * Return value from TX table of signal contactorsClosed in msg JCT_status.
 */
AirState app_canTx_JCT_status_contactorsClosed_get();

/**
 * Return value from TX table of signal current in msg JCT_status.
 */
float app_canTx_JCT_status_current_get();

/**
 * Return value from TX table of signal voltage in msg JCT_status.
 */
float app_canTx_JCT_status_voltage_get();

/**
 * Return value from TX table of signal unsigned_tester in msg JCT_status.
 */
int app_canTx_JCT_status_unsigned_tester_get();

/**
 * Returns pointer to the struct of msg JCT_vitals signals in the TX table.
 */
const JCT_vitals_Signals* app_canTx_JCT_vitals_getData();

/**
 * Returns pointer to the struct of msg JCT_noncriticalErrors signals in the TX table.
 */
const JCT_noncriticalErrors_Signals* app_canTx_JCT_noncriticalErrors_getData();

/**
 * Returns pointer to the struct of msg JCT_AIRShutdownErrors signals in the TX table.
 */
const JCT_AIRShutdownErrors_Signals* app_canTx_JCT_AIRShutdownErrors_getData();

/**
 * Returns pointer to the struct of msg JCT_motorShutdownErrors signals in the TX table.
 */
const JCT_motorShutdownErrors_Signals* app_canTx_JCT_motorShutdownErrors_getData();

/**
 * Returns pointer to the struct of msg JCT_status signals in the TX table.
 */
const JCT_status_Signals* app_canTx_JCT_status_getData();

