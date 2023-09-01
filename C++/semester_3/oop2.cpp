#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived class" << std::endl;
    }
};

void func1() {
    std::cout << "Function 1" << std::endl;
}

void func2() {
    std::cout << "Function 2" << std::endl;
}

int main() {
    // Creating objects
    Base baseObj;
    Derived derivedObj;

    // Array of pointers to objects
    Base* objects[] = {&baseObj, &derivedObj};

    // Pointer to functions
    void (*funcPtr1)() = &func1;
    void (*funcPtr2)() = &func2;

    // Array of pointers to functions
    void (*funcPointers[])() = {funcPtr1, funcPtr2};

    // Using array of pointers to objects
    for (int i = 0; i < 2; ++i) {
        objects[i]->display();
    }

    // Using array of pointers to functions
    for (int i = 0; i < 2; ++i) {
        funcPointers[i]();
    }

    return 0;
}
