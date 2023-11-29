#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Student
{
protected:
    string m_name, m_address, m_branch;
    int m_rollNumber;

public:
    //DEfault constructor
    Student(){
        m_name="default_student_name";
        m_address="default_student_address";
        m_branch="default_branch";
        m_rollNumber=0;
    }

    //Parameterized constructor
    Student(string name, string address, string branch, int roll){
        m_name=name;
        m_address=address;
        m_branch=branch;
        m_rollNumber=roll;
    }

    //Copy constructor
    Student(Student &obj)
    {
         m_name = obj.m_name;
         m_address = obj.m_address;
         m_branch = obj.m_branch;
         m_rollNumber = obj.m_rollNumber;
    }

    void display(){
        cout<<"Record of: "<<m_name<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"Address     : "<<m_address<<endl;
        cout<<"Branch      : "<<m_branch<<endl;
        cout<<"Roll Number : "<<m_rollNumber<<endl<<endl;
    }
};

int main()
{
    Student student1;
    Student student2("Aditya Pradip Godse", "Moshi, Milleliun Divine, A1004", "AI&DS", 32); 

    student1.display();
    student2.display();  

    Student copyOfstdudent2(student2);
    copyOfstdudent2.display();

    return 0;
}
