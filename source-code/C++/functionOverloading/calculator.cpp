#include <iostream>
#include <conio.h>

using namespace std;

void show_menu(){
    cout<<"1) Addition"<<endl;
    cout<<"2) Subtraction"<<endl;
    cout<<"3) Multiplication"<<endl;
    cout<<"4) Division"<<endl;
}

int main(){

int choice, result, life=1;
int a,b;

cout<<"Enter number 1: ";
cin>>a;
cout<<"Enter number 2: ";
cin>>b;

while (life==1)
{   
    system("cls");
    cout<<"Number 1: "<<a<<endl;
    cout<<"Number 2: "<<b<<endl<<endl;
    show_menu();

    cout<<"Which operation do you want to perform: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        result = a+b;
        break;
    
    case 2:
        result = a-b;
        break;
    
    case 3:
        result = a*b;
        break;
    
    case 4:
        result = a/b;
        break;
    
    default:
        break;
    }
    cout<<"Requested result: "<<result<<endl;
    getch();
}

}