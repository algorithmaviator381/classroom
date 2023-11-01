#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

template <typename T>
bool isOperator(T c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
template <typename T>
int precedance(T op)
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

template <typename T>
void operation()
{
    stack<T> myStack;
    myStack.push('1'); // The values pushed in the stack should be of the same data which is written during declaration of stack
    myStack.push('-');
    myStack.push('2');
    myStack.push('4');

    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
        if (isOperator(myStack.top()))
        {
            if (precedance(myStack.top()) == 1)
            {
                cout << "minus operator\n";
            }
            cout << "Operator found!";
            break;
        }
    }
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
            while (!operatorStack.empty() && operatorStack.top() != '(' && precedance(operatorStack.top()) >= precedance(c))
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

bool istheCharInt(char c)
{
}

float operation(float num1, float num2, char c)
{
    switch (c)
    {
    case '+':
        return num2 + num1;
        break;

    case '-':
        return num2 - num1;
        break;

    case '*':
        return num2 * num1;
        break;

    case '/':
        return num2 / num1;
        break;

    default:
        break;
    }
}

int postfixValue(string postfix)
{
    stack<float> operand;
    int value = 0;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            operand.push(c);
        }
        else
        {
            int num1 = operand.top();
            operand.pop();
            int num2 = operand.top();
            operand.pop();

            operand.push(operation(num1, num2, c));
        }
    }

    return operand.top();
}

int main()
{

    string expression = "5+4";
    // cout << "Enter an expression: ";
    // getline(cin, expression);

    cout << "Infix to postfix    : " << infixToPostfix(expression) << endl;
    cout << "Value of epression  : " << postfixValue(infixToPostfix(expression));
    // cout<<isdigit('4');
}