'''
Entry point for generating CAN drivers and DBC from JSON data, as a command line utility.
TODO: Generate callback functions for received messages? Could be cool
'''


import argparse
from src.json_parsing.json_can_parsing import JsonCanParser
from src.codegen.dbc_generation.dbc_generation import DbcGenerator
from src.codegen.c_generation.can_tx_generation import AppCanTxHeaderGenerator, AppCanTxSourceGenerator, IoCanTxHeaderGenerator, IoCanTxSourceGenerator
from src.codegen.c_generation.can_rx_generation import AppCanRxHeaderGenerator, AppCanRxSourceGenerator, IoCanRxHeaderGenerator, IoCanRxSourceGenerator
from src.codegen.c_generation.can_utils_generation import AppCanMsgsHeaderGenerator, AppCanUtilsSourceGenerator


if __name__ == '__main__':
    # Parse args
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--board',
        help='Choose a board name')
    parser.add_argument(
        '--can_data_dir',
        help='Path to JSON CAN data')
    parser.add_argument(
        '--app_can_tx_source_output',
        help='Path to the output CAN TX source file for the App layer')
    parser.add_argument(
        '--app_can_tx_header_output',
        help='Path to the output CAN TX header file for the App layer')
    parser.add_argument(
        '--io_can_tx_source_output',
        help='Path to the output CAN TX source file for the IO layer')
    parser.add_argument(
        '--io_can_tx_header_output',
        help='Path to the output CAN TX header file for the IO layer')
    parser.add_argument(
        '--app_can_rx_source_output',
        help='Path to the output CAN RX source file for the App layer')
    parser.add_argument(
        '--app_can_rx_header_output',
        help='Path to the output CAN RX header file for the App layer')
    parser.add_argument(
        '--io_can_rx_source_output',
        help='Path to the output CAN RX source file for the IO layer')
    parser.add_argument(
        '--io_can_rx_header_output',
        help='Path to the output CAN RX header file for the IO layer')
    parser.add_argument(
        '--app_can_utils_source_output',
        help='Path to the output source file for packing/unpacking CAN messages')
    parser.add_argument(
        '--app_can_utils_header_output',
        help='Path to the output header file for packing/unpacking CAN messages'
             'for the APP layer')
    parser.add_argument(
        '--dbc_output',
        help='Path to the DBC file')
    args = parser.parse_args()

    # Parse JSON and generate DBC
    can_db = JsonCanParser(can_data_dir=args.can_data_dir).make_database()
    DbcGenerator(database=can_db, output_dir=args.dbc_output).generate_dbc()

    # App Tx
    AppCanTxHeaderGenerator(db=can_db, node=args.board, output_dir=args.app_can_tx_header_output).generate_header()
    AppCanTxSourceGenerator(db=can_db, node=args.board, output_dir=args.app_can_tx_source_output).generate_source()

    # Io Tx
    IoCanTxHeaderGenerator(db=can_db, node=args.board, output_dir=args.io_can_tx_header_output).generate_header()
    IoCanTxSourceGenerator(db=can_db, node=args.board, output_dir=args.io_can_tx_source_output).generate_source()
    
    # App Rx
    AppCanRxHeaderGenerator(db=can_db, node=args.board, output_dir=args.app_can_rx_header_output).generate_header()
    AppCanRxSourceGenerator(db=can_db, node=args.board, output_dir=args.app_can_rx_source_output).generate_source()
    
    # Io Rx
    IoCanRxHeaderGenerator(db=can_db, node=args.board, output_dir=args.io_can_rx_header_output).generate_header()
    IoCanRxSourceGenerator(db=can_db, node=args.board, output_dir=args.io_can_rx_source_output).generate_source()

    # App Utils
    AppCanMsgsHeaderGenerator(db=can_db, node=args.board, output_dir=args.app_can_utils_header_output).generate_header()
    AppCanUtilsSourceGenerator(db=can_db, node=args.board, output_dir=args.app_can_utils_source_output).generate_source()