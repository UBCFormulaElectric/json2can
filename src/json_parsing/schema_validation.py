"""
Functions to validate the CAN JSON schema.
"""
from typing import Dict
from schema import Schema, Optional, Or

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
        },
        {
            # Bits/min/max, and signal will range from min to max in X bits, scale/offset will be calculated accordingly
            "bits": int,
            "min": Or(int, float),
            "max": Or(int, float),
            Optional("unit"): str,
            Optional("start_value"): Or(int, float),
            Optional("start_bit"): int,
            Optional("signed"): str,
        },
        {
            # Resolution/min/max, and signal will range from min to max such that scale=resolution, bits/offset will be calculated accordingly
            "resolution": Or(int, float),
            "min": Or(int, float),
            "max": Or(int, float),
            Optional("unit"): str,
            Optional("start_value"): Or(int, float),
            Optional("start_bit"): int,
            Optional("signed"): str,
        },
        {
            # Enum, signal will be generated with minimum # of bits to hold all possible enum values
            "enum": str,
            Optional("start_value"): str,
            Optional("start_bit"): int,
        },
    )
)

tx_msg_schema = Schema(
    {
        "msg_id": Or(int, lambda x: x >= 0),
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
Rx file schemas
"""
rx_schema = Schema({"messages": [str]})

"""
Enum file schemas
"""
enum_schema = Schema(Or({str: {str: int}}, {}))  # If the node doesn"t define any enums

"""
Bus file schemas
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


def validate_tx_json(tx_json: Dict) -> Dict:
    return tx_schema.validate(tx_json)


def validate_rx_json(rx_json: Dict) -> Dict:
    return rx_schema.validate(rx_json)


def validate_enum_json(enum_json: Dict) -> Dict:
    return enum_schema.validate(enum_json)


def validate_bus_json(bus_json: Dict) -> Dict:
    return bus_schema.validate(bus_json)
