#include "Token.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class Lexer {
    public:
        explicit Lexer(const std::string& source) : source(source), position(0) {}

        std::vector<Token> tokenize() {
            std::vector<Token> tokens;

            while (position < source.size()) {
                if (std::isspace(currentChar())) {
                    handleWhitespace();
                } else if (std::isdigit(currentChar())) {
                    tokens.push_back(lexNumber());
                } else if (currentChar() == '"' || currentChar() == '\'') {
                    tokens.push_back(lexString());
                } else if (std::isalpha(currentChar()) || currentChar() == '_') {
                    tokens.push_back(lexIdentifierOrKeyword());
                } else if (isSymbol()) {
                    tokens.push_back(lexSymbol());
                } else {
                    tokens.push_back(Token(TokenType::Unknown, std::string(1, currentChar())));
                    position++;
                }
            }

            return tokens;
        }

    private:
        std::string source;
        size_t position;

        bool in_range(char c, char hi, char low){
            return (low <= c && hi >= c);
        }

        bool is_alpha(char c){
            return in_range(c, 'a', 'z') || in_range(c, 'A', 'Z');
        }

        bool is_numeric(char c){
            return in_range(c, '0', '9');
        }

        bool is_whitespace(char c){
            return c == ' ' || c == '\t' || c == '\r';
        }

        bool is_delimiter(char c){
            return 
                c == ';' || c == '\n' || c == '{' || c == '}' ||
                c == ',' || c == '.' || c == '\'' || c == '"' ||
                c == '(' || c == ')' || c == '[' || c == ']'  ||
                c == '%' || c == '_' ;
        }

        bool is_operator(char c){
            return 
                c == '+' || c == '-' || c == '*' || c == '/' ||
                c == '^' || c == '~' || c == '&' || c == '|' ||
                c == '=' || c == '<' || c == '>' || c == '!' ||
                c == ':' ;
        }

        // Identifier Name Check
        bool is_valid_identifier_beginning(char c){
            return is_alpha(c) || c == '_';
        }

        bool is_valid_identifier_char(char c){
            return is_valid_identifier_beginning(c) || is_numeric(c);
        }

};