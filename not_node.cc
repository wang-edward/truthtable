#include "not_node.h"

using namespace std; 

NotNode:: NotNode(unique_ptr<Node> operand) : operand(std::move(operand)) {}

NodeType NotNode:: getType() const { return NodeType::NOT; }

void NotNode:: print() const {
    cout << "(!";
    operand->print();
    cout << ")";
}

bool NotNode:: evaluate(const unordered_map<string, bool>& variableValues) const {
    return !operand->evaluate(variableValues);
}


