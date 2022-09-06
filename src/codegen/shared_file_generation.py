'''
Base class for generating a text file output.
'''


import os


class FileGenerator:
    def __init__(self,  output_path: str):
        self._output_dir = os.getcwd() if os.path.dirname(output_path) == '' else os.path.dirname(output_path)
        self._output_name = os.path.basename(output_path)

    def write_output(self, text_output: str) -> None:
        '''
        Write the text stored in text_output to output_path.
        '''
        # Generate output folder if it doesn't exist yet
        if not os.path.exists(self._output_dir):
            os.makedirs(self._output_dir)
        # Write file to disk
        with open(os.path.join(self._output_dir, self._output_name), 'w') as fout:
            fout.write(text_output)