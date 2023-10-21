#include <iostream>
#include <string>
#include <sstream>

class inputValidations {
public:
    bool validate(int flag, const void* data) {
        if (flag < 1 || flag > 4) {
            std::cout << "Invalid flag. Please use a flag between 1 and 4." << std::endl;
            return false;
        }

        switch (flag) {
            case 1: // Integer
                if (isInteger(*static_cast<const std::string*>(data))) {
                    return true;
                }
                break;
            case 2: // Float
                if (isFloat(*static_cast<const std::string*>(data))) {
                    return true;
                }
                break;
            case 3: // Char
                if (isChar(*static_cast<const std::string*>(data))) {
                    return true;
                }
                break;
            case 4: // String
                if (isString(*static_cast<const std::string*>(data))) {
                    return true;
                }
                break;
        }

        return false;
    }

    // Function to check if a string can be converted to an integer.
    bool isInteger(const std::string& str) {
        std::istringstream ss(str);
        int value;
        return (ss >> value) && ss.eof();
    }

    // Function to check if a string can be converted to a float.
    bool isFloat(const std::string& str) {
        std::istringstream ss(str);
        float value;
        return (ss >> value) && ss.eof();
    }

    // Function to check if a string contains a single character.
    bool isChar(const std::string& str) {
        return str.length() == 1;
    }

    // Function to check if the input is a string.
    bool isString(const std::string& str) {
        return true;
    }
};

int main() {
    inputValidations validator;
    bool isValid;

    int data = 45;
    isValid = validator.validate(1, &data);

    if (isValid) {
        std::cout << "Data is in the specified format." << std::endl;
    } else {
        std::cout << "Data is not in the specified format." << std::endl;
    }

    return 0;
}
