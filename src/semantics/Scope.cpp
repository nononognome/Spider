#include "AST.h"
#include <unordered_map>
#include <stdexcept>

class ScopeResolver {
    std::unordered_map<std::string, std::string> scope;

public:
    void declare(const std::string& name, const std::string& type) {
        if (scope.find(name) != scope.end()) {
            throw std::runtime_error("Variable already declared: " + name);
        }
        scope[name] = type;
    }

    std::string resolve(const std::string& name) {
        if (scope.find(name) == scope.end()) {
            throw std::runtime_error("Variable not declared: " + name);
        }
        return scope[name];
    }
};
