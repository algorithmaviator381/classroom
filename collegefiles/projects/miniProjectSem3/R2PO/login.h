#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <conio.h>

using std::cin;
using std::cout;
using std::string;

string globalName = "";

int login(string user, string password)
{
    int result;
    system("cls");
    if (user == "adimail" && password == "sonchafa")
    {
        globalName = "Aditya";
        cout << "Login Successful as "<<globalName;
        result = 1;
    }
    else if (user == "the_sakshimane" && password == "aarush")
    {
        globalName = "Sakshi Mane";
        cout << "Login Successful as "<<globalName;
        result = 1;
    }
    else
    {
        cout << "Invalid Username or Password";
        return 0;
    }
    cout << "\n\nPress any key to continue...";
    getch();
    system("cls");
    return result;
}

#endif