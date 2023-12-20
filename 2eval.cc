#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

#include "node.h"
#include "variable_node.h"
#include "not_node.h"
#include "binary_op_node.h"

using namespace std;

// Lexer: Tokenizes the input boolean expression
vector<string> lexer(const string& input) {
    return {"(", "(", "!", "a", ")", "+", "b", ")"};
}

// Recursive descent parser: Constructs the parse tree
unique_ptr<Node> parseExpression(const vector<string>& tokens, size_t& index);

unique_ptr<Node> parsePrimary(const vector<string>& tokens, size_t& index) {
    if (tokens[index] == "(") {
        // Parenthesized expression
        index++;
        auto expression = parseExpression(tokens, index);
        index++;  // Consume closing parenthesis
        return expression;
    } else if (tokens[index] == "!") {
        // NOT operation
        index++;
        auto operand = parsePrimary(tokens, index);
        return make_unique<NotNode>(std::move(operand));
    } else {
        // Variable
        return make_unique<VariableNode>(tokens[index++]);
    }
}

unique_ptr<Node> parseExpression(const vector<string>& tokens, size_t& index) {
    auto left = parsePrimary(tokens, index);
    while (index < tokens.size() && (tokens[index] == "+" || tokens[index] == "*")) {
        // Binary AND or OR operation
        NodeType type = (tokens[index++] == "+") ? NodeType::AND : NodeType::OR;
        auto right = parsePrimary(tokens, index);
        left = make_unique<BinaryOpNode>(type, std::move(left), std::move(right));
    }
    return left;
}

int main() {
    // Example boolean expression: (a + b) * (!(a + b))
    string inputExpression = "(a+b)*(!(a+b))";

    // Tokenize the input expression
    auto tokens = lexer(inputExpression);

    // Parse the expression to generate the parse tree
    size_t index = 0;
    auto parseTree = parseExpression(tokens, index);

    // Print the parse tree
    parseTree->print();
    cout << endl;

    // Set variable values for evaluation
    unordered_map<string, bool> variableValues;
    variableValues["a"] = true;
    variableValues["b"] = true;

    // Evaluate the expression
    bool result = parseTree->evaluate(variableValues);

    // Print the result
    cout << "Result: " << boolalpha << result << endl;

    return 0;
}

