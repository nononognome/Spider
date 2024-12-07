#include "lexer/Lexer.cpp"
#include "parser/Parser.cpp"
#include "semantics/Type.cpp"
#include "codegen/CodeGen.cpp"

int main() {
    std::string source = "42";
    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parse();

    TypeChecker checker;
    checker.check(*ast);

    CodeGen codegen;
    codegen.generate(*ast);
    codegen.dump();

    return 0;
}
