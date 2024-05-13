#include <iostream>
#include <string>
#include <vector>

int main() {
    
    using std::cout;
    using std::endl;
    
    const char* dataTypes[] = {"bool", "int", "char", "std::string", "float"};
    size_t numDataTypes = sizeof(dataTypes) / sizeof(dataTypes[0]);

    for (size_t i = 0; i < numDataTypes; i++) {
        printf("Size of %s: %lu\n", dataTypes[i], sizeof(dataTypes[i]));
    }

    cout<<"Size of string: "<<sizeof(std::string);
    return 0;
}