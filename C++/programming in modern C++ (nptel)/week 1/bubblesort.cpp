#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int i, int j){
    return i<j;
}

void bubblesort(int ary[], int size_of_arry){

    for(int i=0; i<size_of_arry-1;++i){
        for(int j=0; j<size_of_arry-i-1; ++j){
            if(ary[j] > ary[j+1]){  // < for descending order, > for ascending order
                int temp=ary[j];
                ary[j]=ary[j+1];
                ary[j+1]=temp;
            }
        }
    }
    
}

int main(){
    int temp,data[]={13,16,78,94,15};
    
    int size_of_arry = sizeof(data)/sizeof(data[0]);

    cout<<"Original Array: "<<endl;
    for(int i=0; i<size_of_arry; i++){
        cout<<data[i]<<' ';
    }
    cout<<endl;

    bubblesort(data, size_of_arry);
    // sort(data,data+5,compare);

    cout<<"Sorted Array:   "<<endl;
    for(int i=0; i<5; i++){
        cout<<data[i]<<' ';
    }
}