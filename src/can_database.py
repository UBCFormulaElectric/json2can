'''
This file contains various classes to fully describes a CAN bus: The nodes, messages, and signals on the bus.
'''


from dataclasses import dataclass
from enum import Enum
from typing import List, Union
from .utils import bits_for_uint, bits_to_bytes, is_int


@dataclass(frozen=True)
class CanEnumItem:
    '''
    Dataclass for describing a single value table item.
    '''
    name: str
    value: int


@dataclass(frozen=True)
class CanEnum:
    '''
    Dataclass for fully describing a CAN value table.
    Note: Minimum value is assumed to always be 0. TODO: Change this?
    '''
    name: str
    items: List[CanEnumItem]

    def max_val(self) -> int:
        '''
        Maximum value present in this value table's entries.
        '''
        return max(entry.value for entry in self.items)

    def min_val(self) -> int:
        '''
        Minimum value present in this value table's entries.
        '''
        return 0

    def num_bits(self) -> int:
        '''
        Number of bits needed to store this value table.
        '''
        return bits_for_uint(self.max_val()) 


class CanSignalDatatype(str, Enum):
    '''
    Enum for the possible primitive datatypes of a CAN signal.
    '''
    BOOL = 'bool'
    INT = 'int'
    UINT = 'uint32_t'
    DECIMAL = 'float'


@dataclass(frozen=True)
class CanSignal:
    '''
    Dataclass for fully describing a CAN signal.
    '''
    name: str                           # Name of signal
    start_bit: int                      # Start bit of signal in payload
    bits: int                           # Number of bits to represent signal in payload, in bits
    scale: float                        # Scale for encoding/decoding
    offset: float                       # Offset for encoding/decoding
    min_val: float                      # Min allowed value
    max_val: float                      # Max allowed value
    enum: Union[CanEnum, None]          # Value table, None if doesn't specify one
    start_value: Union[int, None]       # Default starting value, None if doesn't specify one
    unit: str                           # Signal's unit
    description: str = 'N/A'            # Description of signal

    def represent_as_integer(self):
        '''
        If this signal holds integer or unsigned integer values only.
        '''
        return is_int(self.scale) and is_int(self.offset)

    def has_unit(self):
        '''
        If this signal specifies a unit.
        '''
        return self.unit != ''

    def has_non_default_start_val(self):
        '''
        If this signal specifies a starting value.
        '''
        return self.start_value is not None

    def datatype_internal(self):
        '''
        How this signal should be stored in memory (specific to C).
        For example, in C, enums and booleans are both stored internally as unsigned integers.
        '''
        if self.enum:
            return CanSignalDatatype.UINT
        elif self.represent_as_integer():
            if self.min_val >= 0:
                return CanSignalDatatype.UINT
            else:
                return CanSignalDatatype.INT
        else:
            return CanSignalDatatype.DECIMAL

    def datatype(self):
        '''
        The name the datatype this signal should be stored as (specific to C).
        '''
        if self.enum:
            return self.enum.name
        elif self.min_val == 0 and self.max_val == 1:
            return CanSignalDatatype.BOOL
        elif self.represent_as_integer():
            if self.min_val >= 0:
                return CanSignalDatatype.UINT
            else:
                return CanSignalDatatype.INT
        else:
            return CanSignalDatatype.DECIMAL


@dataclass(frozen=True)
class CanMessage:
    '''
    Dataclass for fully describing a CAN message.
    '''
    name: str                       # Name of this CAN message
    id: int                         # Message ID
    description: str                # Message description
    cycle_time: Union[int, None]    # Interval that this message should be transmitted at, if periodic. None if not periodic.
    signals: List[CanSignal]        # All signals that make up this message
    tx_node: str                    # The node that transmits this message
    rx_nodes: List[str]             # All nodes which receive this message

    def bytes(self):
        '''
        Length of payload, in bytes.
        '''
        return bits_to_bytes(sum(signal.bits for signal in self.signals))

    def is_periodic(self):
        '''
        If this signal is periodic, i.e. should be continuously transmitted at a certain cycle time.
        '''
        return self.cycle_time is not None


@dataclass(frozen=True)
class CanBusParams:
    '''
    Dataclass for holding various bus parameters.
    '''
    default_receiver: str
    bus_speed: int
    cycle_time_min: int
    cycle_time_max: int
    cycle_time_default: int
    start_value_min: int
    start_value_max: int
    start_value_default: int


@dataclass(frozen=True)
class CanDatabase:
    '''
    Dataclass for fully describing a CAN bus, its nodes, and their messages.
    ''' 
    nodes: List[str] # List of names of the nodes on the bus
    bus_params: CanBusParams # Various bus params
    messages: List[CanMessage] # All messages being sent to the bus
    enums: List[CanEnum] # All enums being used by bus signals

    def messages_transmitted_by_node(self, tx_node: str) -> List[CanMessage]:
        '''
        Return list of all CAN messages transmitted by a specific node.
        '''                
        return [msg for msg in self.messages if tx_node == msg.tx_node]
    
    def messages_received_by_node(self, rx_node: str) -> List[CanMessage]:
        '''
        Return list of all CAN messages received by a specific node.
        '''
        return [msg for msg in self.messages if rx_node in msg.rx_nodes]

    def messages_for_node(self, node: str) -> List[CanMessage]:
        '''
        Return list of all CAN messages either transmitted or received by a specific node.
        '''
        return self.messages_transmitted_by_node(tx_node=node) + self.messages_received_by_node(rx_node=node)