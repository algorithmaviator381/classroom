#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;

class SubjectMarks
{
public:
    int inSem;
    int Practical;
    int Endsem;

    SubjectMarks() : inSem(0), Practical(0), Endsem(0) {}
};

class Student
{
protected:
    string m_name;
    int m_roll;

    vector<SubjectMarks> MarksList;

public:
    Student(string Name, int RollNo) : m_name(Name), m_roll(RollNo), MarksList(5) {}

    void print()
    {
        cout << "Student Details:\n";
        cout << "Name         : " << m_name << endl;
        cout << "Roll Number  : " << m_roll << endl;
    }

    int getInput(int maxMarks, const string &prompt)
    {
        int marks;
        do
        {
            cout << prompt;
            cin >> marks;
            if (marks < 0 || marks > maxMarks)
            {
                cout << "Invalid input. Enter marks between 0 and " << maxMarks << ": ";
            }
        } while (marks < 0 || marks > maxMarks);
        return marks;
    }

    void inputMarks()
    {
        cout << "\nHello " << m_name << endl;
        cout << "Enter marks for 5 subjects (out of 100):" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "\nSubject " << (i + 1) << ":" << endl;

            MarksList[i].inSem = getInput(20, "In-Semester Marks (out of 20)    : ");
            MarksList[i].Practical = getInput(20, "Practical Exam Marks (out of 20) : ");
            MarksList[i].Endsem = getInput(60, "End-Semester Marks (out of 60)   : ");

            cout << "   -Subject Total: "
                 << MarksList[i].inSem + MarksList[i].Practical + MarksList[i].Endsem
                 << endl;
        }
    }

    void getMinMaxMarks()
    {
        int tempMin, tempMax;

        cout << "\nSubject-wise Maximum and Minimum Marks:" << endl;
        for (int i = 0; i < 5; i++)
        {
            tempMin = min(min(MarksList[i].inSem, MarksList[i].Practical), MarksList[i].Endsem);
            tempMax = max(max(MarksList[i].inSem, MarksList[i].Practical), MarksList[i].Endsem);

            cout << "Subject " << (i + 1) << ":"
                 << "\n   - Maximum Marks: " << tempMax
                 << "\n   - Minimum Marks: " << tempMin
                 << endl;
        }
    }
};

int main()
{
    string StudentName = "Sakshi Mane";
    int RollNumber = 68;

    Student student(StudentName, RollNumber);
    student.inputMarks();

    student.getMinMaxMarks();

    return 0;
}
