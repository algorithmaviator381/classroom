#include <iostream>
#include <sstream>

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex addComplex(Complex num1, Complex num2) {
    Complex result;
    
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    
    return result;
}

Complex subtractComplex(Complex num1, Complex num2) {
    Complex result;
    
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    
    return result;
}

Complex parseComplex(string input) {
    Complex num;
    stringstream ss(input);
    char plusMinus;
    
    ss >> num.real;
    ss >> plusMinus;
    ss >> num.imag;
    
    if (plusMinus == '-') {
        num.imag = -num.imag;
    }
    
    return num;
}

int main() {
    string input1, input2;
    
    cout << "Enter the first complex number (e.g., 5+7i or 6i-5): ";
    cin >> input1;
    cout << "Enter the second complex number (e.g., 5+7i or 6i-5): ";
    cin >> input2;

    Complex num1 = parseComplex(input1);
    Complex num2 = parseComplex(input2);
    
    Complex sum = addComplex(num1, num2);
    Complex difference = subtractComplex(num1, num2);
    
    cout << "Sum of the two complex numbers: " << sum.real << " + " << sum.imag << "i" << endl;
    cout << "Difference of the two complex numbers: " << difference.real << " - " << difference.imag << "i" << endl;
    
    return 0;
}
