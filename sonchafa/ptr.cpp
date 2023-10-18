#include <iostream>
using namespace std;

void change(int* value){
    (*value)++;
}

int main()
{
    int arr[5] = {32, 68, 51, 57, 70};
    int* ptr = &arr[4];
    change(ptr);
    cout << "Element\tAddress" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "\t" << &arr[i] << endl;
    }
}