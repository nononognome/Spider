IDENTIFIERS = [('IDENTIFIER',   r'\b[A-Za-z_][A-Za-z_0-9]*\b')]


ASSIGNOPS = [
    ('PLUS_ASSIGN',       r'\+='),
    ('MINUS_ASSIGN',      r'-='),
    ('MUL_ASSIGN',        r'\*='),
    ('DIV_ASSIGN',        r'/='),
    ('ASSIGN',            r'='),
    ('TYPE_ASSIGN',       r':'),
]


LITERALS = [
    ('NUMBER',       r'\b\d+(\.\d+)?\b'),

    ('MULTISTRING',  r'\"\"\"[\s\S]*?\"\"\"|\'\'\'[\s\S]*?\'\'\''),
    ('SINGLESTRING', r'\"[^\"\n]*\"|\'[^\'\n]*\''),

    ('BOOLEAN',      r'\b(?:true|false|TRUE|FALSE|True|False)\b'),
    
    ('NONE',         r'\b(?:none|null|NONE|NULL|None|Null)\b'),
]


KEYWORDS = [
    ('RETURN',       r'\breturn\b'),

    ('DEFINEAS',     r'\bdefineas\b'),

    ('IF',           r'\bif\b'),

    ('WHILE',        r'\bwhile\b'),
    ('FOR',          r'\bfor\b'),

    ('CLASS',        r'\bclass\b'),
    ('EXTENDS',      r'\bextends\b'),
    ('SELFREF',      r'\bthis\b'),

    ('IN',           r'\bin\b'),

    ('MOD',          r'\bmod\b'),
    ('INT_DIV',      r'\bdiv\b'),

    ('NOT',          r'\bnot\b'),
    ('AND',          r'\band\b'),
    ('OR',           r'\bor\b'),
    ('BIT_XOR',      r'\bxor\b'),
]


UNIARYOPS = [
    ('INCREMENT',    r'\+\+'),
    ('DECREMENT',    r'--'),
]


SINGLEBINARYOPS = [
    ('MEMBEROF',     r'\.'),

    ('PLUS',         r'\+'),
    ('MINUS',        r'-'),
    ('MUL',          r'\*'),
    ('DIV',          r'/'),

    ('BIT_NOT',      r'~'),
    ('BIT_AND',      r'&'),
    ('BIT_OR',       r'\|'),
]


DOUBLEBINARYOPS = [
    ('SHIFT_RIGHT',  r'>>'),
    ('SHIFT_LEFT',   r'<<'),

    ('LOG_NOT',      r'!'),
    ('LOG_AND',      r'&&'),
    ('LOG_OR',       r'\|\|'),

    ('EXACT_LE',     r'<='),
    ('EXACT_GE',     r'>='),
    ('EXACT_NE',     r'!='),
    ('EXACT_EQ',     r'=='),

    ('APPROX_LE',    r'<~'),
    ('APPROX_GE',    r'>~'),
    ('APPROX_NE',    r'!~'),
    ('APPROX_EQ',    r'~~'),

    ('POW',          r'\*\*'),
    ('ROOT',         r'/\*\*'),
]


TERNARYOPS = [

]


NONEXECUTABLES = [
    ('LPAREN',       r'\('),
    ('RPAREN',       r'\)'),

    ('LBRACE',       r'{'),
    ('RBRACE',       r'}'),

    ('LSQUARE',      r'\['),
    ('RSQUARE',      r'\]'),

    ('COMMA',        r','),

    ('EOL',          r';|\n'),
    ('SKIP',         r'[ \t]+'),
    ('COMMENT',      r'%.*'),
]


# Define the token specification -- IN ORDER
token_specification =  LITERALS + KEYWORDS + UNIARYOPS + DOUBLEBINARYOPS + SINGLEBINARYOPS + TERNARYOPS + NONEXECUTABLES + ASSIGNOPS + IDENTIFIERS

# Compile the regular expressions into a single pattern
token_regex = '|'.join(f'(?P<{pair[0]}>{pair[1]})' for pair in token_specification)

class Token:
    def __init__(self, type, value, line, column):
        self.type = type
        self.value = value
        self.line = line
        self.column = column

    def __repr__(self):
        return f'{self.type}({self.value}) at {self.line}:{self.column}'