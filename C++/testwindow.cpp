#include<iostream>
using namespace std;

int x = 1;
namespace name {
    class myclass{
        int a;
        public:
            myclass(int x) : a(x){}
            void print(){ cout<<a; }

    };
}

int main() {
    name::myclass m(5);
    m.print();
    return 0;
}
