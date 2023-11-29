#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    try
    {
        string input;

        cout << "Enter expression (e.g. 5/3): ";
        getline(cin, input);

        std::stringstream ss(input);
        int numerator, denominator;
        float result;

        char slash;
        ss >> numerator >> slash >> denominator;

        if (denominator == 0)
        {
            throw std::runtime_error("Error: Division by zero is not allowed");
        }

        result = numerator / denominator;

        cout << "Result: " << result << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
