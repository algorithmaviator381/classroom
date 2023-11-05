// 8. WRITE A PROGRAM TO DEMONSTRATE ACCESS SPECIFIER.
// Create a class Student with data members name, roll Number, and grade. Implement functions to display these details.
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
    void setDetails(const string& studentName, int studentRollNumber, char studentGrade) {
        name = studentName;
        rollNumber = studentRollNumber;
        grade = studentGrade;
    }

    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student student1;

    student1.setDetails("John Doe", 101, 'A');

    cout << "Student Details:" << endl;
    student1.displayDetails();

    return 0;
}
