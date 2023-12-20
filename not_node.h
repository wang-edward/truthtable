#pragma once
#include "node.h"

class NotNode : public Node {
    std::unique_ptr<Node> operand;
public:
    NotNode(std::unique_ptr<Node> operand);
    NodeType getType() const override;
    void print() const override;
    bool evaluate(const std::unordered_map<std::string, bool>& variableValues) const override;
};
