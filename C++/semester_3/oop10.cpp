#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal {
public:
    Animal(const string& name) : name(name) {}
    virtual string makeSound() const = 0;
    string getName() const { return name; }
private:
    string name;
};

class Cows : public Animal {
public:
    Cows() : Animal("cows") {}
    string makeSound() const override {
        return "moo";
    }
};

class Chicks : public Animal {
public:
    Chicks() : Animal("chicks") {}
    string makeSound() const override {
        return "cluck";
    }
};

class Pigs : public Animal {
public:
    Pigs() : Animal("pigs") {}
    string makeSound() const override {
        return "oink";
    }
};

int main() {
    
    vector<Animal*> farmAnimals = {new Cows(), new Chicks(), new Pigs()};

    for (const Animal* animal : farmAnimals) {
        cout << "Old MacDonald had a farm\n";
        cout << "Ee i ee i o\n";
        cout << "And on his farm he had some " << animal->getName() << endl;
        cout << "E-I-E-I-O!\n";
        cout << "With a " << animal->makeSound() << "-" << animal->makeSound() << " here\n";
        cout << "And a " << animal->makeSound() << "-" << animal->makeSound() << " there\n";
        cout << "Here a " << animal->makeSound() << " there a " << animal->makeSound() << endl;
        cout << "Everywhere " << animal->makeSound() << "-" << animal->makeSound() << endl << endl;
    }

    return 0;
}
