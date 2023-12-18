#include <iostream>
#include <algorithm>

using namespace std;

int recursiveLinearSearch(int arr[], int key, int index, int size)
{
    if (index == size)
    {
        return -1;
    }
    if (arr[index] == key)
    {
        return index;
    }
    return recursiveLinearSearch(arr, key, index + 1, size);
}

int linearSearch(int arr[], int key, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        return recursiveBinarySearch(arr, key, low, mid - 1);
    }
    else
    {
        return recursiveBinarySearch(arr, key, mid + 1, high);
    }
}

int BinarySearch(int arr[], int key, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 11, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    sort(arr, arr + size);

    // int result = recursiveLinearSearch(arr, key, 0, size);
    // int result = linearSearch(arr, key, size);
    // int result = recursiveBinarySearch(arr, key, 0, size - 1);
    int result = BinarySearch(arr, key, size);

    if (result != -1)
    {
        cout << "Element " << key << " found at index " << result << endl;
    }
    else
    {
        cout << "Element " << key << " not found" << endl;
    }

    return 0;
}
