#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int data[]={2,3,5,7,9,11,17,19,23,29};
    int size = sizeof(data)/sizeof(data[0]);

    if(binary_search(data, data+size, 6))
        cout<<"Found";
    else cout<<"Not Found";
}