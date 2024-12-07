#include "AST.h"
#include <stdexcept>
#include <iostream>

class TypeChecker {
public:
    void check(const ASTNode& node) {
        // Placeholder for type checking logic
        if (dynamic_cast<const NumberNode*>(&node)) {
            std::cout << "Type: Number" << std::endl;
        } else if (dynamic_cast<const IdentifierNode*>(&node)) {
            std::cout << "Type: Identifier" << std::endl;
        } else {
            throw std::runtime_error("Unknown node type");
        }
    }
};
