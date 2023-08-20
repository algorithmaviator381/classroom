#include <iostream>

using namespace std;

int main(){
    int num,sum=0;

    cout<<"Enter the limit of summation from 1 to n: ";
    cin>>num;

    for(int i=1;i<=num;i++){
        sum+=i;
    }

    cout<<"The sum of numbers from 1 to " << num << " is " << sum;
}