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
    Base baseObj;
    Derived derivedObj;

    Base* objects[] = {&baseObj, &derivedObj};

    void (*funcPtr1)() = &func1;
    void (*funcPtr2)() = &func2;

    void (*funcPointers[])() = {funcPtr1, funcPtr2};

    for (int i = 0; i < 2; ++i) {
        objects[i]->display();
    }

    for (int i = 0; i < 2; ++i) {
        funcPointers[i]();
    }

    return 0;
}
