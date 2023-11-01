#include <iostream>

template <typename T>
class SearchAlgorithm {
public:
    static int LinearSearchRecursive(const T arr[], const T& searchElement, int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return -1;
        }

        if (arr[startIndex] == searchElement) {
            return startIndex;
        }

        return LinearSearchRecursive(arr, searchElement, startIndex + 1, endIndex);
    }

    static int LinearSearch(const T arr[], const T& searchElement, int size) {
        return LinearSearchRecursive(arr, searchElement, 0, size - 1);
    }
};

int main() {
    int n;

    // std::cout << "Enter the array size: ";
    // std::cin >> n;

    n=4;

    int arr[n] = {32,68,323,381};

    // std::cout << "Enter array elements separated by space: ";
    // for (int i = 0; i < n; ++i) {
    //     std::cin >> arr[i];
    // }

    int searchElement=32;
    // std::cout << "Enter the search element: ";
    // std::cin >> searchElement;

    int result = SearchAlgorithm<int>::LinearSearch(arr, searchElement, n);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
