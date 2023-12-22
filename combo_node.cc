#include "combo_node.h" 

using namespace std;

ComboNode:: ComboNode(string name, vector<unique_ptr<Node>> operands, 
                      unordered_map<vector<bool>, bool> truthtable)
    : name{name}, operands{operands}, truthtable{truthtable} {

    if (operands.size() != inputSize) {
        throw runtime_error{"Invalid number of operands for ComboNode. Provided: " + 
                            to_string(operands.size()) + ", Required: " + to_string(inputSize)};
    }
    if (truthtable.size() != exp2(inputSize)) {
        throw runtime_error{"Invalid truth table size. Provided: " + 
                            to_string(truthtable.size()) + ", Required: " + to_string(inputSize)};
    }
}

NodeType ComboNode:: getType() const {
    return NodeType::COMBO;
}

void ComboNode:: print() const {
    cout << "(" << name;
    for (const auto& n : operands) {
        n->print();

        // don't print comma on last element
        if (&n != &operands.back()) {
            cout << ", ";
        }
    }
    cout << ")";
}

bool ComboNode:: evaluate(const unordered_map<string, bool>& variableValues) const{
    vector<bool> inputs(inputSize);
    {
        auto it = inputs.begin();
        for (auto& o : operands) {
            *it = o->evaluate(variableValues);
            it++;
        }
    }
    auto it = truthtable.find(inputs);
    if (it == truthtable.end()) {
        throw runtime_error{"Invalid truth table. Expected entry: " + printVector(inputs)};
    }

    return it->second;
}
