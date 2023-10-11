#include <iostream>
#include <string>

using namespace std;

int arraySize(string set[], int size) {
    return size;
}

void printarray(string set[], int size) {
    for (int i = 0; i < size; i++) {
        cout << set[i] << endl;
    }
}

int main() {
    string set[3] = {"ab", "cd", "efg"};
    int size = arraySize(set, 3);
    printarray(set, size);
    return 0;
}
