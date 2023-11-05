// 4. WRITE A PROGRAM FOR DEFAULT CONSTRUCTOR.
// Create a class called circle with attributes radius and area. Implement a default constructor that sets         
// the radius to 1 and calculates the area using the formula area = π * radius * radius. 
// Create an object of the circle class using the default constructor and display its area.

// Sol.:

#include <iostream>
#include <cmath> 
using namespace std;

class Circle {
private:
    double radius;
    double area;
public:
    Circle() {
        radius = 1.0;
        calculateArea();
    }

    void calculateArea() {
        area = 3.1415926535 * radius * radius;
    }
    void displayArea() {
        cout << "Area of the circle with radius " << radius << " is: " << area << endl;
    }
};

int main() {
    Circle myCircle;
    myCircle.displayArea();

    return 0;
}
