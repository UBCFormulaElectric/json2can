/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ------------------------- Function Definitions ------------------------- */

#include "App_CanTx.h"

/* -------------------------- Private Variables --------------------------- */

static JCT_TxMsgs tx_table;

/* ------------------------- Function Definitions ------------------------- */

void app_canTx_init()
{
    memset(&tx_table, 0, sizeof(JCT_TxMsgs));
    app_canTx_CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_heartbeat_set(CANSIG_CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_heartbeat_START_VAL);
    app_canTx_CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_timestamp_set(CANSIG_CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_timestamp_START_VAL);
    app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_watchdogTimeout_set(CANSIG_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_watchdogTimeout_START_VAL);
    app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_boardOvertemp_set(CANSIG_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_boardOvertemp_START_VAL);
    app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_boardOvervoltage_set(CANSIG_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_boardOvervoltage_START_VAL);
    app_canTx_CanMessage(name='JCT_AIRShutdownErrors', id=603, description='AIR shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyAirShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_dummyAirShutdown_set(CANSIG_CanMessage(name='JCT_AIRShutdownErrors', id=603, description='AIR shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyAirShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_dummyAirShutdown_START_VAL);
    app_canTx_CanMessage(name='JCT_motorShutdownErrors', id=604, description='Motor shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyMotorShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_dummyMotorShutdown_set(CANSIG_CanMessage(name='JCT_motorShutdownErrors', id=604, description='Motor shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyMotorShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_dummyMotorShutdown_START_VAL);
    app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_contactorsClosed_set(CANSIG_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_contactorsClosed_START_VAL);
    app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_current_set(CANSIG_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_current_START_VAL);
    app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_voltage_set(CANSIG_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_voltage_START_VAL);
}

void app_canTx_CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_heartbeat_set(bool value)
{
    tx_table.CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.heartbeat_value = value;
}

void app_canTx_CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_timestamp_set(uint32_t value)
{
    tx_table.CanMessage(name='JCT_vitals', id=601, description='Heartbeat signal.', cycle_time=1000, signals=[CanSignal(name='heartbeat', start_bit=0, bits=1, scale=1.0, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='timestamp', start_bit=1, bits=32, scale=1, offset=0, min_val=0, max_val=4294967295, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.timestamp_value = value;
}

void app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_watchdogTimeout_set(bool value)
{
    tx_table.CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.watchdogTimeout_value = value;
}

void app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_boardOvertemp_set(bool value)
{
    tx_table.CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.boardOvertemp_value = value;
}

void app_canTx_CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_boardOvervoltage_set(bool value)
{
    tx_table.CanMessage(name='JCT_noncriticalErrors', id=602, description='Non-critical errors.', cycle_time=None, signals=[CanSignal(name='watchdogTimeout', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvertemp', start_bit=1, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A'), CanSignal(name='boardOvervoltage', start_bit=2, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.boardOvervoltage_value = value;
}

void app_canTx_CanMessage(name='JCT_AIRShutdownErrors', id=603, description='AIR shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyAirShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_dummyAirShutdown_set(bool value)
{
    tx_table.CanMessage(name='JCT_AIRShutdownErrors', id=603, description='AIR shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyAirShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.dummyAirShutdown_value = value;
}

void app_canTx_CanMessage(name='JCT_motorShutdownErrors', id=604, description='Motor shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyMotorShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_dummyMotorShutdown_set(bool value)
{
    tx_table.CanMessage(name='JCT_motorShutdownErrors', id=604, description='Motor shutdown.', cycle_time=1000, signals=[CanSignal(name='dummyMotorShutdown', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=None, unit='', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.dummyMotorShutdown_value = value;
}

void app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_contactorsClosed_set(AirState value)
{
    tx_table.CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.contactorsClosed_value = (value > CANSIG_JCT_status_contactorsClosed_MAX) ? CANSIG_JCT_status_contactorsClosed_MAX : value;
}

void app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_current_set(float value)
{
    const float tmp = value < CANSIG_JCT_status_current_MIN ? CANSIG_JCT_status_current_MIN : value;
    tx_table.CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.current_value = tmp > CANSIG_JCT_status_current_MAX ? CANSIG_JCT_status_current_MAX : tmp;
}

void app_canTx_CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_voltage_set(float value)
{
    const float tmp = value < CANSIG_JCT_status_voltage_MIN ? CANSIG_JCT_status_voltage_MIN : value;
    tx_table.CanMessage(name='JCT_status', id=608, description='Message for debugging.', cycle_time=1000, signals=[CanSignal(name='contactorsClosed', start_bit=0, bits=1, scale=1, offset=0, min_val=0, max_val=1, start_val=0, enum=CanEnum(name='AirState', items=[CanEnumItem(name='AIR_OPEN', value=0), CanEnumItem(name='AIR_CLOSED', value=1)]), unit='', description='N/A'), CanSignal(name='current', start_bit=1, bits=12, scale=0.02442002442002442, offset=0, min_val=0, max_val=100, start_val=50, enum=None, unit='A', description='N/A'), CanSignal(name='voltage', start_bit=13, bits=12, scale=0.1221001221001221, offset=0, min_val=0, max_val=500, start_val=0, enum=None, unit='V', description='N/A')], tx_node='JCT', rx_nodes=['DEBUG'])_signals.voltage_value = tmp > CANSIG_JCT_status_voltage_MAX ? CANSIG_JCT_status_voltage_MAX : tmp;
}

bool app_canTx_JCT_vitals_heartbeat_get()
{
    return tx_table.JCT_vitals_signals.heartbeat_value;
}

uint32_t app_canTx_JCT_vitals_timestamp_get()
{
    return tx_table.JCT_vitals_signals.timestamp_value;
}

bool app_canTx_JCT_noncriticalErrors_watchdogTimeout_get()
{
    return tx_table.JCT_noncriticalErrors_signals.watchdogTimeout_value;
}

bool app_canTx_JCT_noncriticalErrors_boardOvertemp_get()
{
    return tx_table.JCT_noncriticalErrors_signals.boardOvertemp_value;
}

bool app_canTx_JCT_noncriticalErrors_boardOvervoltage_get()
{
    return tx_table.JCT_noncriticalErrors_signals.boardOvervoltage_value;
}

bool app_canTx_JCT_AIRShutdownErrors_dummyAirShutdown_get()
{
    return tx_table.JCT_AIRShutdownErrors_signals.dummyAirShutdown_value;
}

bool app_canTx_JCT_motorShutdownErrors_dummyMotorShutdown_get()
{
    return tx_table.JCT_motorShutdownErrors_signals.dummyMotorShutdown_value;
}

AirState app_canTx_JCT_status_contactorsClosed_get()
{
    return tx_table.JCT_status_signals.contactorsClosed_value;
}

float app_canTx_JCT_status_current_get()
{
    return tx_table.JCT_status_signals.current_value;
}

float app_canTx_JCT_status_voltage_get()
{
    return tx_table.JCT_status_signals.voltage_value;
}

const JCT_vitals_Signals* app_canTx_JCT_vitals_getData()
{
    return &tx_table.JCT_vitals_signals;
}

const JCT_noncriticalErrors_Signals* app_canTx_JCT_noncriticalErrors_getData()
{
    return &tx_table.JCT_noncriticalErrors_signals;
}

const JCT_AIRShutdownErrors_Signals* app_canTx_JCT_AIRShutdownErrors_getData()
{
    return &tx_table.JCT_AIRShutdownErrors_signals;
}

const JCT_motorShutdownErrors_Signals* app_canTx_JCT_motorShutdownErrors_getData()
{
    return &tx_table.JCT_motorShutdownErrors_signals;
}

const JCT_status_Signals* app_canTx_JCT_status_getData()
{
    return &tx_table.JCT_status_signals;
}

