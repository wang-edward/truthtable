#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <regex>

#include "node.h"
#include "variable_node.h"
#include "not_node.h"
#include "binary_op_node.h"

class App {
    std::string expression;
    std::vector<std::string> tokens;
    std::unique_ptr<Node> parseTree;
    std::unordered_map<std::string, bool> variableMap;
    std::string filenameExp;
    std::string filenameMap;
    std::fstream fileExp;
    std::fstream fileMap;
    std::vector<std::string> lexer(const std::string& input);
    std::unique_ptr<Node> parsePrimary(const std::vector<std::string>& tokens, size_t& index);
    std::unique_ptr<Node> parseExpression(const std::vector<std::string>& tokens, size_t& index);

    void readFileExp();
    void readFileMap();

public:
    App(const std::string& filenameExp, const std::string& filenameMap);
    void begin();
    ~App(); 
};
