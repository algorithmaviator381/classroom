#include <iostream>
#include <stack>

using namespace std;

void bubblesort(int array[], int size_of_array){
    for(int i=0; i<size_of_array; i++){
        for(int j=0; j<size_of_array-1; j++){
            if(array[j]<array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

int main(){
    int data[] = {1,5,49,87,34};

    int size = sizeof(data)/sizeof(data[0]);

    cout<<"Original data: ";

    for(int i=0; i<size; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;

    bubblesort(data, size);

    cout<<"Reversed data: ";
    for(int i=0; i<size; i++){
        cout<<data[i]<<" ";
    }
}