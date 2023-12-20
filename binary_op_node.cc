#include "binary_op_node.h"
using namespace std;

BinaryOpNode:: BinaryOpNode(NodeType type, unique_ptr<Node> left, unique_ptr<Node> right)
    : type(type), left(std::move(left)), right(std::move(right)) {}

NodeType BinaryOpNode:: getType() const { return type; }

void BinaryOpNode:: print() const {
    cout << "(";
    left->print();
    cout << " " << getOpSymbol() << " ";
    right->print();
    cout << ")";
}

bool BinaryOpNode:: evaluate(const unordered_map<string, bool>& variableValues) const {
    bool leftValue = left->evaluate(variableValues);
    bool rightValue = right->evaluate(variableValues);

    if (type == NodeType::AND) {
        return leftValue && rightValue;
    } else if (type == NodeType::OR) {
        return leftValue || rightValue;
    } else {
        // For simplicity, returning false for undefined operation
        return false;
    }
}
