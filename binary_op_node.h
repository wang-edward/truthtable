#pragma once
#include "node.h"

class BinaryOpNode : public Node {
    NodeType type;
    std::string getOpSymbol() const {
        switch (type) {
            case NodeType::AND: return "*";
            case NodeType::OR: return "+";
            default: return "";
        }
    }
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
public:
    BinaryOpNode(NodeType type, std::unique_ptr<Node> left, std::unique_ptr<Node> right);
    NodeType getType() const override;
    void print() const override;
    bool evaluate(const std::unordered_map<std::string, bool>& variableValues) const override;
    
};

