#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int evaluatePrefix(const string& prefix) {
    stack<int> operandStack;
    istringstream iss(prefix);
    string token;
    
    while (iss >> token) {
        if (isdigit(token[0])) {
            operandStack.push(stoi(token));
        } else {
            int operand1 = operandStack.top();
            operandStack.pop();
            int operand2 = operandStack.top();
            operandStack.pop();
            
            if (token == "+") {
                operandStack.push(operand1 + operand2);
            } else if (token == "-") {
                operandStack.push(operand1 - operand2);
            } else if (token == "*") {
                operandStack.push(operand1 * operand2);
            } else if (token == "/") {
                operandStack.push(operand1 / operand2);
            }
        }
    }
    
    return operandStack.top();
}

int main() {
    string prefixExpression = "+ 3 * 4 2";
    int result = evaluatePrefix(prefixExpression);
    
    cout << "Prefix Expression: " << prefixExpression << endl;
    cout << "Result: " << result << endl;
    
    return 0;
}