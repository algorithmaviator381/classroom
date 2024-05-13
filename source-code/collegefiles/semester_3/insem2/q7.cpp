// 7. WRITE A PROGRAM TO DEMONSTRATE STATIC MEMBER FUNCTIONS.
// Create a class called Circle with a static member variable PI (float) and a static member function calculateArea that takes the radius of the circle as input and returns the area of the circle. 
// Initialize the PI variable to 3.14. Write a program to input the radius from the user and calculate the area of the circle using the calculateArea static member function.
// Sol.:


#include <iostream>
using namespace std;

class Circle {
public:
    static float PI;
    static float calculateArea(float radius);
};

float Circle::PI = 3.14;

float Circle::calculateArea(float radius) {
    return PI * radius * radius;
}

int main() {
    cout << "Enter the radius of the circle: ";
    float radius;
    cin >> radius;

    float area = Circle::calculateArea(radius);

    cout << "The area of the circle with radius " << radius << " is: " << area << endl;

    return 0;
}
