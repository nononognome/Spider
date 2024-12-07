#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// Enum for token types
enum class TokenType {
    identifier,
    keyword,
    delimiter,
    ops,
    literal,
};

// Token struct
struct Token {
    TokenType type;
    std::string value;
    int row;
    int col;

    Token(TokenType type, const std::string& value, int row, int col) : type(type), value(value), row(row), col(col) {}
};

#endif
