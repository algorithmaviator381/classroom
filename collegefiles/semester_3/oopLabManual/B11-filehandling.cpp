#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class OldMacDonald
{
public:
    OldMacDonald(const string &farmName, const string &animalName, const T &sound)
        : farmName(farmName), animalName(animalName), sound(sound) {}

    void sing() const
    {
        cout << farmName << " had a farm" << endl;
        cout << "Ee i ee i o" << endl;
        cout << "And on his farm he had some " << animalName << endl;
        cout << "E-I-E-I-O!" << endl;
        cout << "With a " << sound << "-" << sound << " here" << endl;
        cout << "And a " << sound << "-" << sound << " there" << endl;
        cout << "Here a " << sound << " there a " << sound << endl;
        cout << "Everywhere " << sound << "-" << sound << endl
             << endl;
    }

private:
    string farmName;
    string animalName;
    T sound;
};

class FarmAnimal
{
public:
    FarmAnimal(const string &name, const string &sound)
        : name(name), sound(sound) {}

    virtual void sing() const
    {
        OldMacDonald<string> poem("Old MacDonald", name, sound);
        poem.sing();
    }

protected:
    string name;
    string sound;
};

class Cow : public FarmAnimal
{
public:
    Cow() : FarmAnimal("Cows", "moo") {}
};

class Chicken : public FarmAnimal
{
public:
    Chicken() : FarmAnimal("Chicks", "cluck") {}
};

class Pig : public FarmAnimal
{
public:
    Pig() : FarmAnimal("Pigs", "oink") {}
};

class Duck : public FarmAnimal
{
public:
    Duck() : FarmAnimal("Ducks", "quack") {}
};

int main()
{
    ofstream MyFile("Assignment No 8.txt");

    vector<FarmAnimal *> animals;

        Cow cow;
        Chicken chicken;
        Pig pig;
        Duck duck;

        animals.push_back(&cow);
        animals.push_back(&chicken);
        animals.push_back(&pig);
        animals.push_back(&duck);

        for (const FarmAnimal *animal : animals)
        {
            animal->sing();
        }

        return 0;

    MyFile.close();
}