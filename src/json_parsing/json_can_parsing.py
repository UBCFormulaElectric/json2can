'''
Module for parsing CAN JSON, and returning a CanDatabase object. 
'''


import os
from typing import Dict, Tuple
import json
from math import ceil
from ..can_database import *
from .schema_validation import validate_bus_json, validate_enum_json, validate_tx_json
from ..utils import max_uint_for_bits


class InvalidCanJson(Exception):
    ...


def calc_signal_scale_and_offset(max_val: int, min_val: int, num_bits: int) -> Tuple[float, float]:
    '''
    Calculate scale and offset used to linearly interpoltate between unsigned data of specified bit length and 
    the provided min and max values.
    '''
    scale = (max_val - min_val) / max_uint_for_bits(num_bits)
    offset = min_val
    return scale, offset


class JsonCanParser:
    def __init__(self, can_data_dir: str):
        self._bus_data = None
        self._nodes = [] # List of node names
        self._messages = {} # Dict of msg names to msg objects
        self._enums = {} # Dict of enum names to enum objects

        self._parse_json_data(dir=can_data_dir)

    def make_database(self) -> CanDatabase:
        '''
        Make and return CanDatabase object form the parsed data.
        '''
        return CanDatabase(
            bus_params=self._bus_data,
            nodes=self._nodes,
            messages=self._messages.values(),
            enums=self._enums.values()
        )

    def _parse_json_data(self, dir: str):
        '''
        Load all CAN JSON data from specified directory.
        '''
        # Load shared JSON data
        raw_bus_json_data = self._get_raw_json_data_from_file(f'{dir}/bus')
        bus_json_data = validate_bus_json(raw_bus_json_data)

        raw_shared_enum_json_data = self._get_raw_json_data_from_file(f'{dir}/shared_enum')
        shared_enum_json_data = validate_enum_json(raw_shared_enum_json_data)

        # Parse bus data
        self._bus_data = CanBusParams(
            default_receiver=bus_json_data['default_receiver'], 
            bus_speed=bus_json_data['bus_speed'],
            cycle_time_min=bus_json_data['cycle_time_min'],
            cycle_time_max=bus_json_data['cycle_time_max'],
            cycle_time_default=bus_json_data['cycle_time_default'],
            start_value_min=bus_json_data['start_value_min'],
            start_value_max=bus_json_data['start_value_max'],
            start_value_default=bus_json_data['start_value_default'],
        )

        # Parse shared enum JSON
        for enum_name, enum_data in shared_enum_json_data.items():
            # Check if this enum name is a duplicate
            if enum_name in self._enums:
                raise InvalidCanJson(f'Shared enum "{enum_name}" is a duplicate, enums must have unique names.')

            can_enum = self._get_parsed_can_enum(enum_name=enum_name, enum_json_data=enum_data)
            self._enums[enum_name] = can_enum

        # Parse node's tx and enum JSON
        self._nodes = [f.name for f in os.scandir(dir) if f.is_dir()]
        for node in self._nodes:
            raw_node_tx_json_data = self._get_raw_json_data_from_file(f'{dir}/{node}/{node}_tx')
            node_tx_json_data = validate_tx_json(raw_node_tx_json_data)

            raw_node_enum_json_data = self._get_raw_json_data_from_file(f'{dir}/{node}/{node}_enum')  
            node_enum_json_data = validate_enum_json(raw_node_enum_json_data)

            # Parse node's enums
            for enum_name, enum_data in node_enum_json_data.items():
                # Check if this enum name is a duplicate
                if enum_name in self._enums:
                    raise InvalidCanJson(f'Enum "{enum_name}" for node "{node}" is a duplicate, enums must have unique names.')

                can_enum = self._get_parsed_can_enum(enum_name=enum_name, enum_json_data=enum_data)
                self._enums[enum_name] = can_enum

            # Parse node's tx messages
            for tx_msg_name, msg_data in node_tx_json_data.items():
                # Check if this message name is a duplicate
                if tx_msg_name in self._messages:
                    raise InvalidCanJson(f'Message "{tx_msg_name}" transmitted by node "{node}" is a duplicate, messages must have unique names.')

                can_msg = self._get_parsed_can_message(msg_name=tx_msg_name, msg_json_data=msg_data, node=node)
                self._messages[tx_msg_name] = can_msg

        # Parse node's RX JSON (have to do this last so all messages on this bus are already found, from TX JSON)
        for node in self._nodes:
            node_rx_json_data = self._get_raw_json_data_from_file(f'{dir}/{node}/{node}_rx')
            node_rx_msgs = node_rx_json_data['messages']

            for tx_msg_name in node_rx_msgs:
                # Check if this message is defined
                if tx_msg_name not in self._messages:
                    raise InvalidCanJson(f'Message "{tx_msg_name}" received by "{node}" is not defined. Make sure it is correctly defined in the TX JSON.')

                rx_msg = self._messages[tx_msg_name]
                if rx_msg not in rx_msg.rx_nodes:
                    rx_msg.rx_nodes.append(node)

    def _get_parsed_can_message(self, msg_name: str, msg_json_data: Dict, node: str) -> CanMessage:
        '''
        Parse JSON data dictionary representing a CAN message.
        '''
        id = msg_json_data['msg_id']
        description, _ = self._get_optional_value(msg_json_data, 'description', '')
        msg_cycle_time, _ = self._get_optional_value(msg_json_data, 'cycle_time', None)

        # Check if message ID is unique
        if id in {msg.id for msg in self._messages.values()}:
            raise InvalidCanJson(f'ID for message "{msg_name}" transmitted by "{node}" is a duplicate, messages must have unique IDs.')

        signals = []
        next_available_bit = 0
        occupied_bits = [None] * 64
        require_start_bit_specified = False

        # Parse message signals
        for name, data in msg_json_data['signals'].items():
            signal, specified_start_bit = self._get_parsed_can_signal(
                signal_name=name, 
                signal_json_data=data, 
                next_available_bit=next_available_bit
            )

            # If we specify one start bit, we require that the rest of the message specify start bit too
            if specified_start_bit:
                require_start_bit_specified = True
            elif require_start_bit_specified:
                raise InvalidCanJson(f'Signal "{signal.name}" in "{msg_name}" must specify a start bit positions, because other signals in this message have specified start bits.')

            # Mark a signal's bits as occupied, by inserting the signal's name
            for idx in range(signal.start_bit, signal.start_bit + signal.bits):
                if idx < 0 or idx > 63:
                    raise InvalidCanJson(f'Signal "{signal.name}" in "{msg_name}" is requesting to put a bit at invalid position {idx}. Messages have a maximum length of 64 bits.')
                elif occupied_bits[idx] != None:
                    raise InvalidCanJson(f'Signal "{signal.name}" in "{msg_name}" is requesting to put a bit at invalid position {idx}. That position is already occupied by the signal "{occupied_bits[idx]}".')

                occupied_bits[idx] = signal.name
            
            signals.append(signal)
            next_available_bit += signal.bits

        return CanMessage(
            name=msg_name,
            id=id,
            description=description,
            signals=signals,
            cycle_time=msg_cycle_time,
            tx_node=node,
            rx_nodes=[self._bus_data.default_receiver]
        )

    def _get_parsed_can_signal(self, signal_name: str, signal_json_data: Dict, next_available_bit: int) -> CanSignal:
        '''
        Parse JSON data dictionary representing a CAN signal.
        '''
        max_val = 0
        min_val = 0  
        scale = 0
        offset = 0
        bits = 0
        enum = None

        # Parse unit, default start value, and starting bit position
        unit, _ = self._get_optional_value(signal_json_data, 'unit', '')
        start_value, _ = self._get_optional_value(signal_json_data, 'start_value', None)
        start_bit, specified_start_bit = self._get_optional_value(signal_json_data, 'start_bit', next_available_bit)

        # Get signal value data. Method depends on which data provided in JSON file.
        # Option 1: Provide min, max, and bit length. Scale and offset are calculated.
        if all(datum in signal_json_data for datum in ('min', 'max', 'bits')):
            max_val = signal_json_data['max']
            min_val = signal_json_data['min']
            bits = signal_json_data['bits']

            scale, offset = calc_signal_scale_and_offset(
                max_val=max_val, 
                min_val=min_val, 
                num_bits=bits
            )

        # Option 2: Provide min, max, and resolution (scale). Offset and bit length are calculated.
        elif all(datum in signal_json_data for datum in ('min', 'max', 'resolution')):
            max_val = signal_json_data['max']
            min_val = signal_json_data['min']
            sig_resolution = signal_json_data['resolution']
            scale = sig_resolution
            offset = min_val

            max_raw_val = ceil((max_val - min_val) / sig_resolution) 
            bits = max_raw_val.bit_length()

        # Option 3: Provide an enum. Min, max, bits, have to be calculated. 
        # Scale and offset are assumed to be 1 and 0, respectively (so start your enums at 0!)
        elif 'enum' in signal_json_data:
            enum_name = signal_json_data['enum']
            if enum_name not in self._enums:
                raise InvalidCanJson(f'Signal "{signal_name}" requests an enum named "{enum_name}", but an enum by that name was not defined.')

            enum = self._enums[enum_name]
            max_val = enum.max_val()
            min_val = enum.min_val()
            bits = enum.num_bits()
            scale = 1
            offset = 0

        # Option 4: Just provide bits, and will be considered to be an unsigned int of however many bits.
        elif 'bits' in signal_json_data:
            bits=signal_json_data['bits']
            max_val=max_uint_for_bits(bits)
            min_val=0
            scale=1
            offset=0

        # Otherwise, payload data was not inputted correctly
        else:
            raise InvalidCanJson(f'Signal "{signal_name}" has invalid payload representation, and could not be parsed.')

        # Check if this message name is a duplicate
        if bits < 1 or bits > 32:
            raise InvalidCanJson(f'Signal "{signal_name}" has invalid bit length {bits}. Bit length must be between 1 and 32.')

        return CanSignal(
            name=signal_name, 
            start_bit=start_bit,
            bits=bits,
            scale=scale,
            offset=offset,
            min_val=min_val, 
            max_val=max_val, 
            unit=unit,
            enum=enum,
            start_value=start_value,
        ), specified_start_bit

    def _get_parsed_can_enum(self, enum_name: str, enum_json_data: Dict) -> CanEnum:  
        '''
        Parse JSON data dictionary representing a CAN enum.
        '''
        items = []
        for name, value in enum_json_data.items():
            if value < 0:
                raise InvalidCanJson(f'Negative enum value found for enum "{enum_name}", which is not supported. Use only positive integers or zero.')
                
            if value in {item.value for item in items}:
                raise InvalidCanJson(f'Repeated value {value} for enum "{enum_name}", which is not allowed.')

            items.append(CanEnumItem(name=name, value=value))

        if 0 not in {item.value for item in items}:        
            raise InvalidCanJson(f'Enum "{enum_name}" must define the value 0.')

        return CanEnum(name=enum_name, items=items)

    def _get_raw_json_data_from_file(self, file_path: str) -> Dict:
        '''
        Load an individual JSON file from specified path.
        '''
        with open(f'{file_path}.json') as file:
            try:
                data = json.load(file)
                return data
            except json.JSONDecodeError:
                raise InvalidCanJson(f'Error parsing JSON data from file path "{file_path}".')

    def _get_optional_value(self, data: Dict, key: str, default: str) -> str:
        '''
        Parse a value from a key in data. If key not found, return default.
        '''
        if key in data: 
            return data[key], True
        else: 
            return default, False