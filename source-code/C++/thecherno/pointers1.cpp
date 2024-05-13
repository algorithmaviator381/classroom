#include <iostream>

using namespace std;

int main(){

    int32_t value1 = 988875;  //address: 0x61ff08
    int64_t value2 = 988875;     //address: 0x61fef0

    int arr[10] = {5,4,8,7,6,4,1,2,3,6};

    int* ptr = &arr[0];
    *ptr = 9;

    // void* ptr = nullptr;    //null pointer

    // cout<<"Data value   : "<<value2<<endl;   
    // cout<<"Data pointer : "<<&value2<<endl;
    // cout<<ptr;

    cout<<"Data\tPointer"<<endl;

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cout<<arr[i]<<"\t"<<&arr[i]<<endl;
    }

    return 0;
}