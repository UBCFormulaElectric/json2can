"""
Functions to validate the CAN JSON schema.
"""
from typing import Dict
from schema import Schema, Optional, Or, And

"""
Tx file schemas
"""
tx_signal_schema = Schema(
    # 4 options to define a signal"s representation...
    Or(
        {
            # Just bits, and signal will be a uint of X bits, i.e. scale=1, offset=0, min=0, max=(2^bits-1)
            "bits": int,
            Optional("unit"): str,
            Optional("start_value"): int,
            Optional("start_bit"): int,
            Optional("signed"): bool,
        },
        {
            # Bits/min/max, and signal will range from min to max in X bits, scale/offset will be calculated accordingly
            "bits": int,
            "min": Or(int, float),
            "max": Or(int, float),
            Optional("unit"): str,
            Optional("start_value"): Or(int, float),
            Optional("start_bit"): int,
        },
        {
            # Resolution/min/max, and signal will range from min to max such that scale=resolution, bits/offset will be calculated accordingly
            "resolution": Or(int, float),
            "min": Or(int, float),
            "max": Or(int, float),
            Optional("unit"): str,
            Optional("start_value"): Or(int, float),
            Optional("start_bit"): int,
        },
        {
            # Enum, signal will be generated with minimum # of bits to hold all possible enum values
            "enum": str,
            Optional("start_value"): str,
            Optional("start_bit"): int,
        },
        {
            # Scale/offset/bits/signedness: Basically if you want to configure like a DBC file
            "scale": Or(int, float),
            "offset": Or(int, float),
            "bits": int,
            "min": Or(int, float),
            "max": Or(int, float),
            Optional("start_value"): str,
            Optional("start_bit"): int,
            Optional("signed"): bool,
        },
    )
)

tx_msg_schema = Schema(
    {
        "msg_id": And(int, lambda x: x >= 0),
        "signals": {
            str: tx_signal_schema,
        },
        Optional("cycle_time"): Or(int, lambda x: x >= 0),
        Optional("num_bytes"): Or(int, lambda x: x >= 0 and x <= 8),
        Optional("description"): str,
    }
)

tx_schema = Schema({str: tx_msg_schema})

"""
Rx file schema
"""
rx_schema = Schema({"messages": [str]})

"""
Enum file schema
"""
enum_schema = Schema(Or({str: {str: int}}, {}))  # If the node doesn"t define any enums

"""
Bus file schema
"""
bus_schema = Schema(
    {
        "default_receiver": str,
        "bus_speed": int,
        "default_endianness": str,
        "cycle_time_min": int,
        "cycle_time_max": int,
        "cycle_time_default": int,
        "start_value_min": int,
        "start_value_max": int,
        "start_value_default": int,
    }
)

"""
Alerts file schema
"""
alerts_schema = Schema(
    Or(
        {
            "alert_set_msg_id": And(int, lambda x: x >= 0),
            "alert_cleared_msg_id": And(int, lambda x: x >= 0),
            "alerts": [str],
        },
        {},
    )
)


def validate_tx_json(json: Dict) -> Dict:
    return tx_schema.validate(json)


def validate_rx_json(json: Dict) -> Dict:
    return rx_schema.validate(json)


def validate_enum_json(json: Dict) -> Dict:
    return enum_schema.validate(json)


def validate_bus_json(json: Dict) -> Dict:
    return bus_schema.validate(json)


def validate_alerts_json(json: Dict) -> Dict:
    return alerts_schema.validate(json)
