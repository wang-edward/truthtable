#pragma once
#include "node.h"

class ComboNode : Node{
    std::string name;
    static constexpr int inputSize = 4;
    std::vector<std::unique_ptr<Node>> operands;
    std::unordered_map<std::vector<bool>, bool> truthtable;
public:
    ComboNode(std::string name, std::vector<std::unique_ptr<Node>> operands, 
            std::unordered_map<std::vector<bool>, bool> truthtable);
    NodeType getType() const override;
    void print() const override;
    bool evaluate(const std::unordered_map<std::string, bool>& variableValues) const override;
};
