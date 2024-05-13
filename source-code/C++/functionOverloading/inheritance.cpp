#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Base{
protected:
    int m_num1;

    void getnum1(){
        cout<<"Enter num 1: ";
        cin>>m_num1;
    }
};

class derived_1 : public Base{
protected:
    int m_num2;

    void getnum2(){
        cout<<"Enter num 2: ";
        cin>>m_num2;
    }
};

class derived_2: public derived_1{
public:
    int m_num3;

    void getnumbers(){
        getnum1();
        getnum2();
        cout<<"Enter num 3: ";
        cin>>m_num3;

        displaySum();
    }

    void displaySum(){
        cout<<"Summation of numbers: "<<m_num1+m_num2+m_num3;
    }
};


int main(){

    derived_2 obj;
    
    obj.getnumbers();

    return 0;
}
