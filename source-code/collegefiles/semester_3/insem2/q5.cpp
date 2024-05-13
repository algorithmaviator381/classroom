// 5. WRITE A PROGRAM TO DEMONSTRATE PARAMETERISED CONSTRUCTOR.
// Create a class called student with attributes name, roll number, and grade. 
// Implement a parameterized constructor that takes these attributes as parameters and initializes them. 
// Create an object of the student class using the constructor and display the student's details.
// Sol.:

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    char grade;

public:
    Student(string studentName, int studentRollNumber, char studentGrade) {
        name = studentName;
        rollNumber = studentRollNumber;
        grade = studentGrade;
    }

    void displayDetails() {
        cout << "Student Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student student1("John Doe", 12345, 'A');

    student1.displayDetails();

    return 0;
}
