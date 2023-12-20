#include "variable_node.h"

using namespace std;

NodeType VariableNode:: getType() const { return NodeType::VARIABLE; }

void VariableNode:: print() const {
    cout << name;
}

bool VariableNode:: evaluate(const unordered_map<string, bool>& variableValues) const {
    // Lookup variable value in the provided map
    auto it = variableValues.find(name);
    if (it != variableValues.end()) {
        return it->second;
    } else {
        // For simplicity, assuming undefined variables are false
        return false;
    }
}

