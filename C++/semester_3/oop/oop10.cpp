#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FarmAnimals {
public:
    FarmAnimals(const string& name, const string& sound)
        : name(name), sound(sound) {}

    string makeSound() const {
        return sound;
    }

    string getName() const {
        return name;
    }

private:
    string name;
    string sound;
};

int main() {
    vector<FarmAnimals> animal;
    
    animal.emplace_back("Cows", "moo");
    animal.emplace_back("Chicks", "cluck");
    animal.emplace_back("Pigs", "oink");
    animal.emplace_back("ducks","quack");

    for (const FarmAnimals& animal : animal) {
        cout << "Old MacDonald had a farm\n";
        cout << "Ee i ee i o\n";
        cout << "And on his farm he had some " << animal.getName() << endl;
        cout << "E-I-E-I-O!\n";
        cout << "With a " << animal.makeSound() << "-" << animal.makeSound() << " here\n";
        cout << "And a " << animal.makeSound() << "-" << animal.makeSound() << " there\n";
        cout << "Here a " << animal.makeSound() << " there a " << animal.makeSound() << endl;
        cout << "Everywhere " << animal.makeSound() << "-" << animal.makeSound() << endl << endl;
    }

    return 0;
}
