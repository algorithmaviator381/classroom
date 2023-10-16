#include <iostream>

using namespace std;

class cls{
public:
    int x,y;

    cls(): x(9), y(2){
        cout<<"Created entity"<<endl;
    }

    ~cls(){
        cout<<"Destroyed entity"<<endl;
    }

    void print(){
        cout<<x<<"\t"<<y<<endl;
    }
};

int main(){
    cls obj;
    obj.print();
}