#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>

#include "node.h"
#include "variable_node.h"
#include "not_node.h"
#include "binary_op_node.h"

class App {

    std::string expression;
    std::vector<std::string> tokens;
    std::unique_ptr<Node> parseTree;
    size_t index = 0;
    const string filenameMap;
    const string filenameExp;
    std::fstream fileExp;
    std::fstream fileMap;
    std::unordered_map<std::string, bool> variableMap;

    // Lexer: Tokenizes the input boolean expression
    std::vector<std::string> lexer(const string& input);
    // Recursive descent parser: Constructs the parse tree
    std::unique_ptr<Node> parseExpression(const std::vector<std::string>& tokens, size_t& index);
    std::unique_ptr<Node> parsePrimary(const std::vector<std::string>& tokens, size_t& index);
    string readFileExp();
    std::unordered_map<std::string, bool> readFileMap();
public:
    App(const string& filenameExp, const string& filenameMap);
    ~App();
    void begin();
};
