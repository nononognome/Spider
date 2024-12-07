#ifndef AST_H
#define AST_H

#include <string>
#include <memory>

class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class NumberNode : public ASTNode {
public:
    explicit NumberNode(const std::string& value) : value(value) {}
    std::string value;
};

class IdentifierNode : public ASTNode {
public:
    explicit IdentifierNode(const std::string& name) : name(name) {}
    std::string name;
};

#endif
