#include <iostream>
#include <vector>
#define max 100

using namespace std;

int main(){
    vector<int> arr(max);

    int count=10,sum=0;
    ///cout<< "Enter number of elements: ";
    ///cin>>count;

    for(int i=0; i<count; i++){
        arr[i] = i;
        sum += arr[i];
    }

    ///cout<<"Array: " << arr[4]<< endl;
    cout<<"Array sum: " << sum;
}