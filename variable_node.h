#pragma once
#include "node.h"

// Node for variables
class VariableNode : public Node {
    std::string name;
public:
    VariableNode();
    NodeType getType() const override;
    void print() const override;
    bool evaluate(const std::unordered_map<std::string, bool>& variableValues) const override;
    VariableNode(const std::string& name) : name(name) {}
};
