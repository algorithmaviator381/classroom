// 2: Student Information
// Create a class Student with data members name, rollNumber, and grade.
// Implement public member functions to set and display these details.
// Use appropriate access specifiers to ensure data encapsulation.
// Create objects of the class and demonstrate the functionality in your program.
// Sol.:

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Student
{

protected:
    string m_name;
    string m_rollno;

public:
    Student(const string &name, const string &roll) : m_name(name), m_rollno(roll) {}

    float calculatePercentage();
    float calculatePointer();
    string calculateGrade();
};

class Subject : public Student
{
protected:
    vector<int> inSemesterMarks;
    vector<int> practicalExamMarks;
    vector<int> endSemesterMarks;

public:
    Subject(string n, string roll) : Student(n, roll)
    {
        inSemesterMarks.resize(5, 0);
        practicalExamMarks.resize(5, 0);
        endSemesterMarks.resize(5, 0);
    }

    void inputMarks()
    {
        cout << "\nHello " << name << endl;
        cout << "Enter marks for 5 subjects (out of 100):" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "\nSubject " << (i + 1) << ":" << endl;

            cout << "In-Semester Marks (out of 20)    : ";
            inSemesterMarks[i] = getInput(20);

            cout << "Practical Exam Marks (out of 20) : ";
            practicalExamMarks[i] = getInput(20);

            cout << "End-Semester Marks (out of 60)   : ";
            endSemesterMarks[i] = getInput(60);

            cout << "   -Subject Total: " << inSemesterMarks[i] + practicalExamMarks[i] + endSemesterMarks[i] << endl;
        }
    }

    int getInput(int maxMarks)
    {
        int marks;
        do
        {
            cin >> marks;
            if (marks < 0 || marks > maxMarks)
            {
                cout << "Invalid input. Enter marks between 0 and " << maxMarks << ": ";
            }
        } while (marks < 0 || marks > maxMarks);
        return marks;
    }
};

// int main() {
//     Student student1, student2;

//     student1.setName("John Doe");
//     student1.setRollNumber(101);
//     student1.setGrade('A');

//     student2.setName("Jane Smith");
//     student2.setRollNumber(102);
//     student2.setGrade('B');

//     cout << "Details for Student 1:" << endl;
//     student1.displayDetails();
//     cout << endl;

//     cout << "Details for Student 2:" << endl;
//     student2.displayDetails();

//     return 0;
// }

int main()
{
    cout << "Hiya" << endl;
    return 0;
}