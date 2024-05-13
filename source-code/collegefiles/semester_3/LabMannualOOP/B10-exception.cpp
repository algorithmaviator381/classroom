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
        float numerator, denominator, result;

        char slash;
        ss >> numerator >> slash >> denominator;

        if (denominator == 0)
        {
            throw denominator;
        }

        result = numerator / denominator;

        cout << "Result: " << result << endl;
    }
    catch (float denominator)
    {
        cout << "Cannot divide by zero" << endl;
    }

    return 0;
}
