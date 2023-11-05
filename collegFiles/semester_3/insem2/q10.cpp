// 10. WRITE A PROGRAM USING COPY DESTRUCTOR.
// You are tasked with developing a simple library management system. For this system, you need to create a class Book that represents a book in the library. Your goal is to implement a destructor for the Book class to ensure proper cleanup of resources when a book object is destroyed
// Sol.:


#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(const string& t, const string& a) {
        title = t;
        author = a;
        cout << "Book '" << title << "' by " << author << " created." << endl;
    }

    ~Book() {
        cout << "Book '" << title << "' by " << author << " destroyed." << endl;
    }

    void displayInfo() const {
        cout << "Title: " << title << "\nAuthor: " << author << endl;
        cout<<"--------------------------------"<<endl;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger");
    Book book2("To Kill a Mockingbird", "Harper Lee");

    cout << "\nBook Information:\n";
    book1.displayInfo();
    book2.displayInfo();

    return 0;
}
