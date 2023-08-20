#include <iostream>
#include <vector>

using namespace std;

int main(){
    int count,sum=0;
    cout<<"Enter the number of elements: ";
    cin>>count;

    vector<int> arr;
    arr.resize(count);

    for(int i=0; i<count; i++){
        arr[i]=i;
        sum+=arr[i];
    }   

    cout<<"Sum of array elements: "<<sum;
}