#include "app.h"

using namespace std;

vector<string> App:: lexer(const string& input) {
    vector<string> tokens;
    // Define the regular expression pattern
    regex pattern(R"([\(\)!\*\+]|[a-zA-Z0-9_]+)");

    // Tokenize the input string
    sregex_iterator iterator(input.begin(), input.end(), pattern);
    sregex_iterator end;

    while (iterator != end) {
        tokens.push_back(iterator->str());
        ++iterator;
    }

    return tokens;
}

unique_ptr<Node> App:: parsePrimary(const vector<string>& tokens, size_t& index) {
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

unique_ptr<Node> App:: parseExpression(const vector<string>& tokens, size_t& index) {
    auto left = parsePrimary(tokens, index);
    while (index < tokens.size() && (tokens[index] == "+" || tokens[index] == "*")) {
        // Binary AND or OR operation
        NodeType type;
        if (tokens[index] == "+") {
            type = NodeType::OR;
        } else if (tokens[index] == "*") {
            type = NodeType::AND;
        } else {
            throw runtime_error{"Parsing error: invalid expression"};
        }
        index++;
        auto right = parsePrimary(tokens, index);
        left = make_unique<BinaryOpNode>(type, std::move(left), std::move(right));
    }
    return left;
}

void App:: readFileExp() {
    string ans;
    if (!getline(fileExp, ans)) {
        throw runtime_error{"Invalid expression format"};
    }
    expression = ans;
}

void App:: readFileMap() {
    
    if (!fileMap.is_open()) {
        throw runtime_error{"Error opening file: " + filenameMap};
    }

    std::string line;
    while (std::getline(fileMap, line)) {
        std::istringstream iss(line);

        string variable;
        string valueStr;

        if (iss >> variable >> valueStr) {
            if (valueStr == "TRUE" || valueStr == "true" || valueStr == "1") {
                variableMap[variable] = true;
            } else if (valueStr == "FALSE" || valueStr == "false" || valueStr == "0") {
                variableMap[variable] = false;
            } else {
                throw runtime_error{"Invalid value for variable " + variable + ": " + valueStr};
            }
            variableList.push_back(variable);
        } else {
            throw runtime_error{"Invalid line format: " + line};
        }
    }
}

App:: App(const string& filenameExp, const string& filenameMap):
    filenameExp{filenameExp}, filenameMap{filenameMap}, fileExp{filenameExp}, fileMap{filenameMap} {}

void App:: begin() {
    try {
        readFileExp();
        readFileMap();
        tokens = lexer(expression);
        parseTree = parseExpression(tokens, index);
        bool result = parseTree->evaluate(variableMap);
        cout << boolalpha;
        cout << "Variables:\n";
        for (auto v : variableList) {
            cout << "\t" << v << ": " << variableMap[v] << "\n";
        }
        cout << "Expression: ";
        parseTree->print(); //  Print parsetree recursively (for fun)
        cout << endl;
        cout << "Result: " << result << endl;
    } catch (exception& e) {
        cerr << e.what();
    }
}

App:: ~App() {
    fileExp.close();
    fileMap.close();
}
