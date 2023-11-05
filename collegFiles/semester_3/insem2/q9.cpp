// 9. WRITE A PROGRAM TO DEMONSTRATE INLINE FUNCTION.
// Create a class Rectangle with data member’s length and width. Implement an Inline function to calculate the area of the rectangle.
// Sol.:

#include<iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w){
        length = l;
        width = w;
    }

    inline double calculateArea() {
        return length * width;
    }
};

int main() {

    Rectangle myRectangle(5, 3);

    // Calculating and displaying the area using the inline function
    cout << "Area of the rectangle: " << myRectangle.calculateArea() << endl;

    return 0;
}
