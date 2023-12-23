#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "util.h"
enum class NodeType {
    VARIABLE,
    NOT,
    AND,
    OR,
    COMBO
};

class Node {
public:
    virtual NodeType getType() const = 0;
    virtual void print() const = 0;
    virtual bool evaluate(const std::unordered_map<std::string, bool>& variableValues) const = 0;
    virtual ~Node() {}
    std::string printNodeType() const {
        switch(this->getType()) {
            case NodeType::VARIABLE:
                return "VARIABLE";
                break;
            case NodeType::NOT:
                return "NOT";
                break;
            case NodeType::AND:
                return "AND";
                break;
            case NodeType::OR:
                return "OR";
                break;
            case NodeType::COMBO:
                return "COMBO";
                break;
        }
    }
};
