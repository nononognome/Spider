#include "AST.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <memory>

class CodeGen {
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;

public:
    CodeGen() : builder(context), module(std::make_unique<llvm::Module>("my_module", context)) {}

    void generate(const ASTNode& node) {
        if (const auto* numNode = dynamic_cast<const NumberNode*>(&node)) {
            llvm::Value* value = llvm::ConstantInt::get(context, llvm::APInt(32, std::stoi(numNode->value)));
            value->print(llvm::errs());
        } else {
            throw std::runtime_error("Unsupported AST node for code generation");
        }
    }

    void dump() {
        module->print(llvm::errs(), nullptr);
    }
};
