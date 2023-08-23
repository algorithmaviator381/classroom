#include <iostream>
#include <stack>

using namespace std;

int main(){
    int data[] = {1,5,49,87,34};

    int size = sizeof(data)/sizeof(data[0]);

    cout<<"Original data: ";

    for(int i=0; i<size; i++){
        cout<<data[i]<<" ";
    }

    cout<<endl;

    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(data[j]>data[j+1]){
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }

    cout<<"Reversed data: ";
    for(int i=0; i<size; i++){
        cout<<data[i]<<" ";
    }
}