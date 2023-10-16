#include <iostream>

using namespace std;

void increment(int& value){
    // (*value)++; 
    value++;
    //first derefrence the value and then increment the value
    //*value++; will just increment the memory address
}

int main(){

    int a=10;
    int* b=&a;
    int& ref=a;

    increment(a);

    cout<<a<<endl;

    return 0;
}