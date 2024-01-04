Assignment 11


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


class shope
{
public:
    int number;
    int student_roll_no[50];
    string student_division[50];
    string student_name[50];
    string address[50];


    void creat_file()
    {
        ofstream outfile("student_file.txt");
        outfile << left << setw(20) << "student name" << setw(12) << "Roll no" << setw(12) << "student_division" << setw(12) << "address" << endl;
        cout << "enter the number of the student" << endl;
        cin >> number;
        for (int i = 0; i < number; i++)
        {
            cout << "enter the " << i + 1 << " name of student" << endl;
            cin >> student_name[i];
            cout << "enter the Roll no:" << endl;
            cin >> student_roll_no[i];
            cout << "enter the student_division " << endl;
            cin >> student_division[i];
            cout << "enter the address" << endl;
            cin >> address[i];
            outfile << left << setw(20) << student_name[i] << setw(12) << student_roll_no[i] << setw(12) << student_division[i] << setw(12) << address[i] << endl;
        }
        outfile.close();
    }


    void show()
    {
        string mytext;
        ifstream in("student_file.txt");
        while (getline(in, mytext))
        {
            cout << mytext << endl;
        }
        in.close();
    }


    void search()
    {
        string line, b;
        cout << "enter student roll_no :" << endl;
        cin >> b;
        fstream infile("student_file.txt");
        while (getline(infile, line))
        {
            if (line.find(b) != string::npos)
            {
                cout << "available stock:" << endl;
                cout << left << setw(20) << "name" << setw(12) << "Roll no" << setw(12) << "student_division" << setw(12) << "address" << endl;
                cout << line << endl;
            }
        }
        infile.close();
    }


    void update()
    {
        int roll_no1;
        cout << "enter the roll_no of student which you want to update" << endl;
        cin >> roll_no1;


        fstream file("student_file.txt", ios::in | ios::out);
        fstream tempFile("temp.txt", ios::out);


        string line1;


        while (getline(file, line1))
        {
            if (line1.find(to_string(roll_no1)) != string::npos)
            {
                string name, division1, address1;
                cout << "enter the name" << endl;
                cin >> name;
                cout << "enter the student_division" << endl;
                cin >> division1;
                cout << "enter the address" << endl;
                cin >> address1;
                tempFile << left << setw(20) << name << setw(12) << roll_no1 << setw(12) << division1 << setw(12) << address1 << endl;
            }
            else
            {
                tempFile << line1 << endl;
            }
        }


        file.close();
        tempFile.close();


        remove("student_file.txt");
        rename("temp.txt", "student_file.txt");


        show();
    }


    void add()
    {
        ofstream file("student_file.txt", ios::app);


        if (!file.is_open())
        {
            cout << "Error opening file for append." << endl;
            return;
        }


        string name;
        string division1, address1;
        int roll_no1;


        cout << "enter the name" << endl;
        cin >> name;
        cout << "enter the roll no code" << endl;
        cin >> roll_no1;
        cout << "enter the student_division" << endl;
        cin >> division1;
        cout << "enter the address" << endl;
        cin >> address1;
        file << left << setw(20) << name << setw(12) << roll_no1 << setw(12) << division1 << setw(12) << address1 << endl;
        file.close();
        show();
    }


    void delete_student()
    {
        int roll_no1;
        cout << "enter the roll_no of student which you want to delete" << endl;
        cin >> roll_no1;


        fstream file("student_file.txt", ios::in | ios::out);
        fstream tempFile("temp.txt", ios::out);


        string line1;


        while (getline(file, line1))
        {
            if (line1.find(to_string(roll_no1)) == string::npos)
            {
                tempFile << line1 << endl;
            }
        }


        file.close();
        tempFile.close();


        remove("student_file.txt");
        rename("temp.txt", "student_file.txt");


        show();
    }
};


int main()
{
    shope s;
    int choice;
    do
    {
        cout << "\n1: Create file\n";
        cout << "2: Show file\n";
        cout << "3: Search student\n";
        cout << "4: Update information\n";
        cout << "5: Add information\n";
        cout << "6: Delete student information\n";
        cout << "7: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            s.creat_file();
            break;
        case 2:
            s.show();
            break;
        case 3:
            s.search();
            break;
        case 4:
            s.update();
            break;
        case 5:
            s.add();
            break;
        case 6:
            s.delete_student();
            break;
        case 7:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }
    } while (choice != 7);


    return 0;
}


1: Create file
2: Show file
3: Search student
4: Update information
5: Add information
6: Delete student information
7: Exit
Enter your choice: 2
student name        Roll no     student_divisionaddress     
vaidehi             51          A           solapur     
diya                56          A           Sindhudurg  
kaveri              4           A           Nashik

1: Create file
2: Show file
3: Search student
4: Update information
5: Add information
6: Delete student information
7: Exit
Enter your choice: 5
enter the name
sakshi
enter the roll no code
68
enter the student_division
A
enter the address
pune
student name        Roll no     student_divisionaddress
vaidehi             51          A           solapur
diya                56          A           Sindhudurg
kaveri              4           A           Nashik
sakshi              68          A           pune

1: Create file
2: Show file
3: Search student
4: Update information
5: Add information
6: Delete student information
7: Exit
Enter your choice:


16 .Mini Project 




#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;


class Information
{
public:
    int number;
    int employee_number[50];
    int employee_salary[50];
    string employee_name[50];
    string address[50];


    void createFile()
    {
        ofstream outfile("info.txt");
        outfile << left << setw(20) << "Name" << setw(12) << "Employee number" << setw(12) << "Salary" << setw(12) << "Address" << endl;
        cout << "Enter the number of employees: ";
        cin >> number;
        for (int i = 0; i < number; i++)
        {
            cout << "Enter the " << i + 1 << " name of employee: ";
            cin >> employee_name[i];
            cout << "Enter the Employee number: ";
            cin >> employee_number[i];
            cout << "Enter the employee salary: ";
            cin >> employee_salary[i];
            cout << "Enter the address: ";
            cin >> address[i];
            outfile << left << setw(20) << employee_name[i] << setw(12) << employee_number[i] << setw(12) << employee_salary[i] << setw(12) << address[i] << endl;
        }
        outfile.close();
    }


    void show()
    {
        string mytext;
        ifstream in("info.txt");
        while (getline(in, mytext))
        {
            cout << mytext << endl;
        }
        in.close();
    }


    void search()
    {
        int searchNumber;
        cout << "Enter employee number to search: ";
        cin >> searchNumber;


        ifstream infile("info.txt");
        string line;
        while (getline(infile, line))
        {
            if (line.find(to_string(searchNumber)) != string::npos)
            {
                cout << "Found employee:" << endl;
                cout << left << setw(20) << "Name" << setw(12) << "Employee number" << setw(12) << "Salary" << setw(12) << "Address" << endl;
                cout << line << endl;
            }
        }
        infile.close();
    }


    void update()
    {
        int employeeNumberToUpdate;
        cout << "Enter the employee number to update: ";
        cin >> employeeNumberToUpdate;


        fstream file("info.txt", ios::in | ios::out);
        fstream tempFile("temp.txt", ios::out);


        string line;


        while (getline(file, line))
        {
            if (line.find(to_string(employeeNumberToUpdate)) != string::npos)
            {
                string name, salary, address;
                cout << "Enter the name: ";
                cin >> name;
                cout << "Enter the salary: ";
                cin >> salary;
                cout << "Enter the address: ";
                cin >> address;
                tempFile << left << setw(20) << name << setw(12) << employeeNumberToUpdate << setw(12) << salary << setw(12) << address << endl;
            }
            else
            {
                tempFile << line << endl;
            }
        }


        file.close();
        tempFile.close();


        remove("info.txt");
        rename("temp.txt", "info.txt");


        show();
    }


    void add()
    {
        ofstream file("info.txt", ios::app);


        if (!file.is_open())
        {
            cout << "Error opening file for append." << endl;
            return;
        }


        string name;
        string salary, address;
        int employeeNumber;


        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the employee number: ";
        cin >> employeeNumber;
        cout << "Enter the salary: ";
        cin >> salary;
        cout << "Enter the address: ";
        cin >> address;
        file << left << setw(20) << name << setw(12) << employeeNumber << setw(12) << salary << setw(12) << address << endl;
        file.close();
        show();
    }


    void deleteEmployee()
    {
        int employeeNumberToDelete;
        cout << "Enter the employee number to delete: ";
        cin >> employeeNumberToDelete;


        fstream file("info.txt", ios::in | ios::out);
        fstream tempFile("temp.txt", ios::out);


        string line;


        while (getline(file, line))
        {
            if (line.find(to_string(employeeNumberToDelete)) == string::npos)
            {
                tempFile << line << endl;
            }
        }


        file.close();
        tempFile.close();


        remove("info.txt");
        rename("temp.txt", "info.txt");


        show();
    }
};


int main()
{
    Information info;
    int choice;


    do
    {
        cout << "\n1: Create file\n";
        cout << "2: Show file\n";
        cout << "3: Search employee\n";
        cout << "4: Update information\n";
        cout << "5: Add information\n";
        cout << "6: Delete employee information\n";
        cout << "7: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            info.createFile();
            break;
        case 2:
            info.show();
            break;
        case 3:
            info.search();
            break;
        case 4:
            info.update();
            break;
        case 5:
            info.add();
            break;
        case 6:
            info.deleteEmployee();
            break;
        case 7:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }


    } while (choice != 7);


    return 0;
}


1: Create file
2: Show file
3: Search employee
4: Update information
5: Add information
6: Delete employee information
7: Exit
Enter your choice: 1
Enter the number of employees: 3
Enter the 1 name of employee: rajesh
Enter the Employee number: 333
Enter the employee salary: 30000
Enter the address: pune
Enter the 2 name of employee: rakesh
Enter the Employee number: 2222
Enter the employee salary: 5000
Enter the address: pune
Enter the 3 name of employee: rahul
Enter the Employee number: 3444
Enter the employee salary: 9000
Enter the address: pune

1: Create file
2: Show file
3: Search employee
4: Update information
5: Add information
6: Delete employee information
7: Exit
Enter your choice: 2
Name                Employee numberSalary      Address
rajesh              333         30000       pune
rakesh              2222        5000        pune
rahul               3444        9000        pune

1: Create file
2: Show file
3: Search employee
4: Update information
5: Add information
6: Delete employee information
7: Exit
Enter your choice: 3
Enter employee number to search: 2222
Found employee:
Name                Employee numberSalary      Address
rakesh              2222        5000        pune

1: Create file
2: Show file
3: Search employee
4: Update information
5: Add information
6: Delete employee information
7: Exit
Enter your choice: 6
Enter the employee number to delete: 2222
Name                Employee numberSalary      Address
rajesh              333         30000       pune
rahul               3444        9000        pune

1: Create file
2: Show file
3: Search employee
4: Update information
5: Add information
6: Delete employee information
7: Exit
Enter your choice: 2
Name                Employee numberSalary      Address
rajesh              333         30000       pune
rahul               3444        9000        pune

1: Create file
2: Show file
3: Search employee
4: Update information
5: Add information
6: Delete employee information
7: Exit
Enter your choice: N
PS C:\Users\kokar\Desktop\cpp>

