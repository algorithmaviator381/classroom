#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string student_name;
    int student_roll;
    string student_address;
    string student_branch;

public:
    // Default constructor
    Student() {
        student_name = "";
        student_roll = 0;
        student_address = "";
        student_branch = "";
    }

    // Parameterized constructor
    Student(const string& name, int roll, const string& address, const string& branch) {
        student_name = name;
        student_roll = roll;
        student_address = address;
        student_branch = branch;
    }

    // Copy constructor
    Student(const Student& other) {
        student_name = other.student_name;
        student_roll = other.student_roll;
        student_address = other.student_address;
        student_branch = other.student_branch;
    }

    // Display student information
    void displayInfo() {
        cout << "Student Name: " << student_name << endl;
        cout << "Student Roll: " << student_roll << endl;
        cout << "Student Address: " << student_address << endl;
        cout << "Student Branch: " << student_branch << endl;
    }
};

int main() {
    // Using default constructor
    Student defaultStudent;
    cout << "Default Student Information:" << endl;
    defaultStudent.displayInfo();
    cout << endl;

    // Using parameterized constructor
    Student paramStudent("John Doe", 123, "123 Main St", "Computer Science");
    cout << "Parameterized Student Information:" << endl;
    paramStudent.displayInfo();
    cout << endl;

    // Using copy constructor
    Student copiedStudent = paramStudent;
    cout << "Copied Student Information:" << endl;
    copiedStudent.displayInfo();

    return 0;
}
