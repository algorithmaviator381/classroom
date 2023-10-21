#include <iostream>
using namespace std;

void incrementValueByReference(int *value)
{
    (*value)++;
}

class operation
{
public:
    void intSwap(int *num1, int *num2)
    {
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }

    void printArray(int arr[], int size)
    {

        cout << "Element\tAddress" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t" << &arr[i] << endl;
        }
    }
};

int main()
{
    // created objects and pointers to objects to the operation class
    operation obj, *ptrObj;
    int arr[5] = {32, 68, 51, 57, 70};

    // To acces the members of obj class, we use . notation
    obj.intSwap(&arr[0], &arr[1]);

    // To acces the members of pointer to obj class, we use -> notation
    ptrObj->printArray(arr, 5);
}