#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <memory>
enum class NodeType {
    VARIABLE,
    NOT,
    AND,
    OR
};

class Node {
public:
    virtual NodeType getType() const = 0;
    virtual void print() const = 0;
    virtual bool evaluate(const std::unordered_map<std::string, bool>& variableValues) const = 0;
    virtual ~Node() {}
};
