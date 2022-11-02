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
 * Update value stored in TX table of signal heartbeat in msg CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_heartbeat_set(bool value);

/**
 * Update value stored in TX table of signal timestamp in msg CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_timestamp_set(uint32_t value);

/**
 * Update value stored in TX table of signal watchdogTimeout in msg CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_watchdogTimeout_set(bool value);

/**
 * Update value stored in TX table of signal boardOvertemp in msg CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_boardOvertemp_set(bool value);

/**
 * Update value stored in TX table of signal boardOvervoltage in msg CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_boardOvervoltage_set(bool value);

/**
 * Update value stored in TX table of signal dummyAirShutdown in msg CanMessage(name='JCT_AIRShutdownErrors', id=603, description='AIR shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyAirShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_AIRShutdownErrors', id=603, description='AIR shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyAirShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_dummyAirShutdown_set(bool value);

/**
 * Update value stored in TX table of signal dummyMotorShutdown in msg CanMessage(name='JCT_motorShutdownErrors', id=604, description='Motor shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyMotorShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_motorShutdownErrors', id=604, description='Motor shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyMotorShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_dummyMotorShutdown_set(bool value);

/**
 * Update value stored in TX table of signal contactorsClosed in msg CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_contactorsClosed_set(AirState value);

/**
 * Update value stored in TX table of signal current in msg CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_current_set(float value);

/**
 * Update value stored in TX table of signal voltage in msg CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG']).
 */
void app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_voltage_set(float value);

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

