from typing import Tuple
from ..shared_file_generation import FileGenerator
from ...can_database import *
from ...utils import *


HEADER_TEMPLATE = '''\
/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

#pragma once

/* --------------------------------- Includes ----------------------------------- */

{includes}

/* ---------------------------------- Macros ------------------------------------ */

{macros}

/* ---------------------------------- Structs ----------------------------------- */

{enum_declarations}

/* ----------------------------------- Enums ------------------------------------ */

{struct_declarations}

/* --------------------------- Function declarations ---------------------------- */

{function_declarations}
'''

SOURCE_TEMPLATE = '''\
/**
 * @note This file is auto-generated. !!! Do not modify !!!
 */
// clang-format off

/* ---------------------------------- Includes ---------------------------------- */

{includes} 

/* ---------------------------- Struct declarations ----------------------------- */

{struct_declarations}

/* --------------------------------- Variables ---------------------------------- */

{variables}

/* ------------------------------ Static functions ------------------------------ */

{static_functions}

/* ---------------------------- Function definitions ---------------------------- */

{function_defs}
'''


class EmbeddedFileGenerator(FileGenerator):
    def __init__(self, db: CanDatabase, node: str, output_dir: str):
        super().__init__(output_path=output_dir)
        self._db = db
        self._node = node

        self._includes = []
        self._macros_text = ''
        self._enums = []
        self._structs = []
        self._variables = []
        self._static_functions = []
        self._functions = []

    def generate_header(self):
        includes_text = '\n'.join(header_inc.include() for header_inc in self._includes)
        functions_declarations_text = '\n\n'.join(func.declaration() for func in self._functions)
        enum_definitions_text = '\n\n'.join(enum.declaration() for enum in self._enums)
        struct_declarations_text = '\n\n'.join(struct.declaration() for struct in self._structs)

        header_text = HEADER_TEMPLATE.format(
            includes=includes_text,
            macros=self._macros_text,
            enum_declarations=enum_definitions_text,
            struct_declarations=struct_declarations_text,
            function_declarations=functions_declarations_text
        )
        self.write_output(text_output=header_text)

    def generate_source(self):
        includes_text = '\n'.join(header_inc.include() for header_inc in self._includes)
        function_defs_text = '\n\n'.join(func.definition() for func in self._functions)
        struct_declarations_text = '\n\n'.join(struct.declaration() for struct in self._structs)
        variables_text = '\n\n'.join(var.decl_for_var() for var in self._variables)
        static_functions_text = '\n\n'.join(func.definition(add_comment=True) for func in self._static_functions)

        source_text = SOURCE_TEMPLATE.format(
            includes=includes_text,
            function_defs=function_defs_text,
            struct_declarations=struct_declarations_text,
            variables=variables_text,
            static_functions=static_functions_text,
        )
        self.write_output(text_output=source_text)


@dataclass(frozen=True)
class CHeaderInclude():
    header_name: str

    def include(self):
        return f'#include {self.header_name}'


@dataclass(frozen=True)
class CMacro():
    name: str
    body: str
    comment: str = ''

    def get_declaration(self):
        return '''\
/**
 * @brief {comment}
 */
#define {name} ({body})'''.format(comment=self.comment, name=self.name, body=self.body) if self.comment != '' else '''\
#define {name} ({body})'''.format(name=self.name, body=self.body)


@dataclass(frozen=True)
class CEnum():
    name: str
    members: List[Tuple[str, int]]

    def declaration(self):
        return '''\
typedef enum
{{
{members}
}} {name};'''.format(
    name=self.name,
    members='\n'.join(
        f'    {member[0]} = {member[1]},' for member in self.members
    )
)


@dataclass(frozen=True)
class CVarDeclaration():
    type: str
    name: str
    comment: str = ''

    def decl_for_var(self):
            return f'{self.type} {self.name};'

    def decl_for_struct(self):
        return f'''\
    /*
{self.comment}
    */
    {self.type} {self.name};\n''' if self.comment != '' else f'''\
    {self.type} {self.name};'''


@dataclass(frozen=True)
class CStruct():
    name: str
    comment: str
    members: List[CVarDeclaration]

    def declaration(self):
        return '''\
/**
 * {comment}
 */
typedef struct
{{
{members}
}} {name};'''.format(
    name=self.name,
    comment=self.comment,
    members='\n'.join(
        f'{member.decl_for_struct()}' for member in self.members
    )
)


@dataclass(frozen=True)
class CFunction():
    signature: str
    comment: str
    body: str

    def declaration(self):
        return '''\
/**
 * @brief {comment}
 */ 
{signature};'''.format(comment=self.comment, signature=self.signature)

    def definition(self, add_comment=False):
        return '''\
/**
 * @brief {comment}
 */ 
{signature} 
{{
{body}
}}'''.format(comment=self.comment, signature=self.signature, body=self.body) if add_comment else '''\
{signature} 
{{
{body}
}}'''.format(signature=self.signature, body=self.body)


@dataclass
class CIntLiteral:
    value: int

    def bin(self, bit_len=BYTE_SIZE):
        return f'0b{format(self.value, f"0{bit_len}b")}'

    def hex(self):
        return str(hex(self.value))

    def dec(self):
        return str(self.value)