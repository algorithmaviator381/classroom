#include <iostream>
#include <stdexcept>
using namespace std;

class DivideByZeroException : public runtime_error {
public:
    DivideByZeroException() : runtime_error("It's Illegal to divide by zero") {}
};

int main() {
    int divident, divisor, result;
    
    cout << "Enter Divident: ";
    cin >> divident;
    
    cout << "Enter divisor: ";
    cin >> divisor;
    
    try {
        if (divisor == 0) {
            throw DivideByZeroException();
        }
        result = divident / divisor;
        cout << "Result: " << result << endl;
    } catch (const DivideByZeroException& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
    
    return 0;
}
