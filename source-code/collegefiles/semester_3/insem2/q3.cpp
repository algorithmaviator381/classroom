// 3. WRITE A PROGRAM USING COPY CONSTRUCTOR.
// Create a class called Person with attributes name and age. 
// Implement a copy constructor that takes another Person object as a parameter and creates a new object with the same name and age.
// Sol.:

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Person {
private:
    string name;
    int age;

public:

    Person(string n, int a) {
        name = n;
        age = a;
    }

    Person(const Person &other) {
        name = other.name;
        age = other.age;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person person1("John Doe", 25);

    cout << "Original Person:" << endl;
    person1.display();

    Person person2(person1);

    cout << "\nCopied Person:" << endl;
    person2.display();

    return 0;
}
