#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

template <typename T>
bool isOperator(T c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

template <typename T>
int precedence(T op)
{
    if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    return 0;
}

float performOperation(float num1, float num2, char c)
{
    switch (c)
    {
    case '+':
        return num2 + num1;
    case '-':
        return num2 - num1;
    case '*':
        return num2 * num1;
    case '/':
        return num2 / num1;
    default:
        return 0;
    }
}

float postfixValue(string postfix)
{
    stack<float> operandStack;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            operandStack.push(static_cast<float>(c - '0'));
        }
        else if (isOperator(c))
        {
            float num1 = operandStack.top();
            operandStack.pop();
            float num2 = operandStack.top();
            operandStack.pop();

            operandStack.push(performOperation(num1, num2, c));
        }
    }

    return operandStack.top();
}

string infixToPostfix(string infix)
{
    stack<char> operatorStack;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (isOperator(c))
        {
            while (!operatorStack.empty() && operatorStack.top() != '(' && precedence(operatorStack.top()) >= precedence(c))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main()
{
    string infixExpression;
    cout << "Enter an expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Infix expression    : " << infixExpression << endl;
    cout << "Postfix expression  : " << postfixExpression << endl;
    cout << "Result: " << postfixValue(postfixExpression) << endl;

    return 0;
}
