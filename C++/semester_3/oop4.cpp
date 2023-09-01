#include <iostream>
#include <vector>
#include <string>

using namespace std;

class startup {
public:
    string name;
    vector<string> founders;
    
private:
    vector<string> techstack;
    int fundings;
    
public:
    startup(string startupName, vector<string> startupFounders, vector<string> startupTechstack, int startupFundings) {
        name = startupName;
        founders = startupFounders;
        techstack = startupTechstack;
        fundings = startupFundings;
    }
    friend class investor;
};

class investor {
public:
    void display(startup& obj) {
        cout << "Private variables: \n";
        cout << "Name: " << obj.name << endl;
        cout << "Founders: \n";
        for (int i = 0; i < obj.founders.size(); i++) {
            cout << "-" << obj.founders[i] << endl;
        };

        cout << endl;

        cout << "Protected variables: \n";
        cout << "Fundings: " << obj.fundings << endl;
        cout << "Tech Stack: \n";
        for (int i = 0; i < obj.techstack.size(); i++) {
            cout << "-" << obj.techstack[i] << endl;
        };
    }
};

int main() {
    vector<string> founders = { "Aditya Godse", "Atharva Nawale", "Aditya Pawar" };
    vector<string> techstack = { "MongoDB", "FastAPI", "ElasticSearch" };
    int fundings = 0;
    startup bookmysport("Book My Sport", founders, techstack, fundings);

    investor angel;
    angel.display(bookmysport);

    return 0;
}
