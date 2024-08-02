import re
from Token import *

class Lexer:
    def __init__(self, input_text):
        self.input_text = input_text
        self.tokens = []
        self.current_pos = 0
        self.line = 1
        self.column = 1

    def tokenize(self):
        for mo in re.finditer(token_regex, self.input_text):
            kind = mo.lastgroup
            value = mo.group(kind)
            column_start = mo.start() - self.input_text.rfind('\n', 0, mo.start())
            if kind == 'EOL':
                self.line += 1
                self.column = 1
                continue
            elif kind == 'SKIP' or kind == 'COMMENT':
                continue
            else:
                token = Token(kind, value, self.line, column_start)
                self.tokens.append(token)
            self.column += len(value)
        return self.tokens

# Example usage
input_code = """
if "hello" in "hello world"{
    this.msg = "this works fine";
    print("I dont need ;")
}
"""
lexer = Lexer(input_code)
tokens = lexer.tokenize()
line = 0
for token in tokens:
    if token.line != line:
        line = token.line
        print('-'*10)
        print(input_code.split('\n')[line-1])
    print(token)