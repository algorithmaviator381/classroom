#include <iostream>

using namespace std;

int sum(int a, int b){
    return a+b;   
}

int diff(int a, int b){
    return a-b;   
}

int (*operation)(int,int);

int main(){
    operation = sum;
    cout<<operation(5,8);
}