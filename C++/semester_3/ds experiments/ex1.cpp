#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Student {
protected:
    string name;
    string rollNumber;

public:
    Student(string n, string roll){
        name = n;
        rollNumber = roll;
    }

    virtual float calculatePercentage() = 0;
    virtual float calculatePointer() = 0;
    virtual string calculateGrade() = 0;
};

class Subject : public virtual Student {
protected:
    vector<int> inSemesterMarks;
    vector<int> practicalExamMarks;
    vector<int> endSemesterMarks;

public:
    Subject(string n, string roll) : Student(n, roll) {
        inSemesterMarks.resize(5);
        practicalExamMarks.resize(5);
        endSemesterMarks.resize(5);
    }

    void inputMarks() {
        cout << "Enter marks for 5 subjects (out of 100):" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "\nSubject " << (i + 1) << ":" << endl;
            
            cout << "In-Semester Marks (out of 20)    : ";
            inSemesterMarks[i] = getInput(20);

            cout << "Practical Exam Marks (out of 20) : ";
            practicalExamMarks[i] = getInput(20);

            cout << "End-Semester Marks (out of 60)   : ";
            endSemesterMarks[i] = getInput(60);

            cout << "     -Subject Total: "<<inSemesterMarks[i]+practicalExamMarks[i]+endSemesterMarks[i]<<endl;
        }
    }

    int getInput(int maxMarks) {
        int marks;
        do {
            cin >> marks;
            if (marks < 0 || marks > maxMarks) {
                cout << "Invalid input. Enter marks between 0 and " << maxMarks << ": ";
            }
        } while (marks < 0 || marks > maxMarks);
        return marks;
    }
};

class Result : public virtual Student, public Subject {
public:
    Result(string n, string roll) : Student(n, roll), Subject(n, roll) {}

    float calculatePercentage() {
        float totalMarks = 0;
        float maxMarks = 500;
        for (int i = 0; i < 5; i++) {
            totalMarks += inSemesterMarks[i] + practicalExamMarks[i] + endSemesterMarks[i];
        }
        return (totalMarks / maxMarks) * 100;
    }

    float calculatePointer() {
        return calculatePercentage() / 9.5;
    }

    string calculateGrade() {
        float percentage = calculatePercentage();
        if (percentage >= 95) return "A+";
        else if (percentage >= 90) return "A";
        else if (percentage >= 85) return "B+";
        else if (percentage >= 80) return "B";
        else if (percentage >= 75) return "C+";
        else if (percentage >= 70) return "C";
        else if (percentage >= 65) return "D+";
        else if (percentage >= 60) return "D";
        else return "F";
    }

    void displayResult() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Percentage: " << calculatePercentage() << "%" << endl;
        cout << "Pointer: " << calculatePointer() << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }
};

int main() {
    string name, roll;

    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter roll number (E-32 format): ";
    cin >> roll;

    Result studentResult(name, roll);
    studentResult.inputMarks();
    studentResult.displayResult();

    return 0;
}