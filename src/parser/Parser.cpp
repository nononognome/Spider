#include "AST.h"
#include "Token.h"
#include <vector>
#include <stdexcept>

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens) : tokens(tokens), position(0) {}

    std::unique_ptr<ASTNode> parse() {
        return parseExpression();
    }

private:
    std::vector<Token> tokens;
    size_t position;

    std::unique_ptr<ASTNode> parseExpression() {
        if (tokens[position].type == TokenType::Number) {
            return std::make_unique<NumberNode>(tokens[position++].value);
        } else if (tokens[position].type == TokenType::Identifier) {
            return std::make_unique<IdentifierNode>(tokens[position++].value);
        } else {
            throw std::runtime_error("Unexpected token: " + tokens[position].value);
        }
    }
};
