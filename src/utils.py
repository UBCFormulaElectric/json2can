import logging
from math import ceil
from typing import Union


BYTE_SIZE = 8


def bits_for_uint(num: int) -> int:
    '''
    Get number of ints required to store unsigned integer num.
    '''
    if num < 0:
        logging.exception('Attempted to count number of bits to represent a negative integer. Not allowed.')

    if num == 0:
        return 1

    bit_count = 0
    while num > 0:
        bit_count += 1
        num //= 2

    return bit_count

def bits_to_bytes(bits: int) -> int:
    '''
    Get number of bytes needed to store bits number of bits.
    '''
    return ceil(bits / BYTE_SIZE)

def max_uint_for_bits(num_bits: int) -> int:
    '''
    Largest unsigned int that can be stored in num_bits number of bits.
    '''
    return int(2 ** num_bits - 1)

def is_int(num: Union[int, float]) -> bool:
    '''
    Return whether or not num is an integer value.
    '''
    return isinstance(num, int) or num.is_integer()

def float_to_str(f):
    '''
    Convert the given float to a string,
    without resorting to scientific notation
    '''
    # ctx = decimal.Context()
    # ctx.prec = 10
    # d1 = ctx.create_decimal(repr(f))
    # return format(d1, 'f')
    # return np.format_float_positional(f)
    return str(float(f))