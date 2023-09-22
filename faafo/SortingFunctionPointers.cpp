#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparison function
bool descendingOrder(int a, int b) {
    return a > b;
}

int main() {
    vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // Sort the vector in descending order using a function pointer
    bool (*compareFunction)(int, int) = descendingOrder;
    sort(numbers.begin(), numbers.end(), compareFunction);

    // Print the sorted vector
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
