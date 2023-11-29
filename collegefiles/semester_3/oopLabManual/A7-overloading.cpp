#include <iostream>
#include <string>
#include <sstream> // Add this for stringstream
#include <conio.h>

using namespace std;

void show_menu()
{
    cout << "1) Addition" << endl;
    cout << "2) Subtraction" << endl;
    cout << "3) Multiplication" << endl;
    cout << "4) Division" << endl;
    cout << "5) Get Conjugate" << endl;
    cout << "------------------------" << endl;
    cout << "0) Exit" << endl;

    cout << "\n\nChoice: ";
}

class complex
{
public:
    int m_real, m_imag;
    string input;

    // Default constructor
    complex() : m_real(0), m_imag(0) {}

    complex(int x, int y) : m_real(x), m_imag(y) {}

    complex operator+(const complex &obj) const
    {
        return complex(m_real + obj.m_real, m_imag + obj.m_imag);
    }

    complex operator-(const complex &obj) const
    {
        return complex(m_real - obj.m_real, m_imag - obj.m_imag);
    }

    complex operator*(const complex &obj) const
    {
        int realPart = (m_real * obj.m_real - m_imag * obj.m_imag);
        int imgPart = (m_imag * obj.m_real + m_real * obj.m_imag);

        return complex(realPart, imgPart);
    }

    complex operator/(const complex &obj) const
    {
        complex conjugate = obj.conjugate();

        int realPart = (m_real * obj.m_real + m_imag * obj.m_imag);
        int imgPart = (m_imag * obj.m_real - m_real * obj.m_imag);

        int denominator = (obj.m_real * obj.m_real + obj.m_imag * obj.m_imag);

        realPart /= denominator;
        imgPart /= denominator;

        return complex(realPart, imgPart);
    }

    complex conjugate() const
    {
        return complex(m_real, -m_imag);
    }

    void displayNumber() const
    {
        string operation = "+";
        string result = "";

        if (m_imag < 0)
        {
            operation = "";
        }

        if (m_real != 0)
        {
            result += to_string(m_real);
        }
        if (m_imag != 0)
        {
            result += operation;
            result += to_string(m_imag);
            result += "i";
        }

        cout << result << endl;
    }

    complex parseComplex()
    {
        stringstream ss(input);

        char plusMinus;

        ss >> m_real;
        ss >> plusMinus;
        ss >> m_imag;

        if (plusMinus == '-')
        {
            return complex(m_real, -m_imag);
        }

        return complex(m_real, m_imag);
    }
};

int main()
{
    int choice, result;
    complex num1, num2;

    system("cls");

    cout << "Enter the first complex number (e.g. 5+7i)      : ";
    cin >> num1.input;
    num1 = num1.parseComplex();

    cout << "Enter the second complex number (e.g. 5+7i)     : ";
    cin >> num2.input;
    num2 = num2.parseComplex();

    while (true)
    {
        system("cls");
        cout << "Number 1: ";
        num1.displayNumber();
        cout << "Number 2: ";
        num2.displayNumber();
        cout << endl;
        show_menu();

        cout << "Which operation do you want to perform: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting the application...";
            cout << "Press any key to continue...";
            getch();
            break;
        }

        switch (choice)
        {
        case 1:
            (num1 + num2).displayNumber();
            break;

        case 2:
            (num1 - num2).displayNumber();
            break;

        case 3:
            (num1 * num2).displayNumber();
            break;

        case 4:
            (num1 / num2).displayNumber();
            break;

        case 5:
            system("cls");
            int expression;
            cout << "Which number do you want to find the Conjugate: \n";

            cout << "1) Complex number 1: ";
            num1.displayNumber();
            cout << "2) Complex number 2: ";
            num2.displayNumber();

            cin >> expression;

            cout << "---------------------------------------------\n";

            switch (expression)
            {
            case 1:
                (num1.conjugate()).displayNumber();
                break;

            case 2:
                (num2.conjugate()).displayNumber();
                break;

            default:
                break;
            }
            break;

        default:
            cout << "Press appropriate key [0-5]";
            break;
        }

        cout << "Press any key to continue...";
        getch();
    }

    return 0;
}
