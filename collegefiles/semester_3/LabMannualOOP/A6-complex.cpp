#include <iostream>
#include <string>

using namespace std;


class complex
{
public:
    int m_real, m_imag;

    complex();
    complex(int x, int y): m_real(x), m_imag(y){};

    complex operator+(complex obj){
        return complex(m_real+obj.m_real,  m_imag + obj.m_imag);
    }

    complex operator-(complex obj){
        return complex(m_real-obj.m_real,  m_imag - obj.m_imag);
    }

    void displayNumber(){

        string operation = "+";

        if(m_imag<0){
            operation="";
        }

        cout<<m_real<<operation<<m_imag<<"i"<<endl;
    }
};

int main()
{
    complex num1(4,3);
    complex num2(5,-9);

    complex sum = num1 + num2;
    complex diff = num1 - num2;

    // num1.displayNumber();
    // num2.displayNumber();

    cout<<"Sum of two complex numbers         : ";
    sum.displayNumber();

    cout<<"Difference of two complex numbers  : ";
    diff.displayNumber();
}