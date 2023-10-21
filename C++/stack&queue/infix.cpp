#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '^') {
        return 3;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

string infixToPostfix(string infix); // Function prototype

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }
    string postfix = infixToPostfix(infix);
    return reverseString(postfix);
}

string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            operatorStack.push(c);
        }
        else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (isOperator(c)) {
            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

// The rest of your code remains the same

string prefixToInfix(string prefix)
{
    stack<string> expressionStack;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isalnum(prefix[i]))
        {
            string operand(1, prefix[i]);
            expressionStack.push(operand);
        }
        else if (isOperator(prefix[i]))
        {
            string operand1 = expressionStack.top();
            expressionStack.pop();
            string operand2 = expressionStack.top();
            expressionStack.pop();
            string combinedExpression = "(" + operand1 + prefix[i] + operand2 + ")";
            expressionStack.push(combinedExpression);
        }
    }

    return expressionStack.top();
}

string postfixToInfix(string postfix)
{
    stack<string> expressionStack;

    for (char c : postfix)
    {
        if (isalnum(c))
        {
            string operand(1, c);
            expressionStack.push(operand);
        }
        else if (isOperator(c))
        {
            string operand2 = expressionStack.top();
            expressionStack.pop();
            string operand1 = expressionStack.top();
            expressionStack.pop();
            string combinedExpression = "(" + operand1 + c + operand2 + ")";
            expressionStack.push(combinedExpression);
        }
    }

    return expressionStack.top();
}

string prefixToPostfix(string prefix)
{
    string reversedPrefix = reverseString(prefix);
    string infix = prefixToInfix(reversedPrefix);
    return infixToPostfix(infix);
}

string postfixToPrefix(string postfix)
{
    string infix = postfixToInfix(postfix);
    return infixToPrefix(infix);
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    string postfixExpression = infixToPostfix(expression);
    cout << "Infix to Postfix: " << postfixExpression << endl;

    string prefixExpression = infixToPrefix(expression);
    cout << "Infix to Prefix: " << prefixExpression << endl;

    string infixExpression1 = postfixToInfix(postfixExpression);
    cout << "Postfix to Infix: " << infixExpression1 << endl;

    string infixExpression2 = prefixToInfix(prefixExpression);
    cout << "Prefix to Infix: " << infixExpression2 << endl;

    string postfixExpression1 = prefixToPostfix(prefixExpression);
    cout << "Prefix to Postfix: " << postfixExpression1 << endl;

    string prefixExpression1 = postfixToPrefix(postfixExpression);
    cout << "Postfix to Prefix: " << prefixExpression1 << endl;

    return 0;
}
