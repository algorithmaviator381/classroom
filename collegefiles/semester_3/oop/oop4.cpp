#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

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

    // Declare the friend function
    friend void displayStartupInfo(const startup& obj);
};

// Define the friend function outside the class
void displayStartupInfo(const startup& obj) {
    cout << "Private variables: \n";
    cout << "Name: " << obj.name << endl;
    cout << "Founders: \n";
    for (const string& founder : obj.founders) {
        cout << "-" << founder << endl;
    };

    cout << endl;

    cout << "Protected variables: \n";
    cout << "Fundings: " << obj.fundings << endl;
    cout << "Tech Stack: \n";
    for (const string& tech : obj.techstack) {
        cout << "-" << tech << endl;
    };
}

int main() {
    vector<string> founders = { "Aditya Godse", "Atharva Nawale", "Aditya Pawar" };
    vector<string> techstack = { "MongoDB", "FastAPI", "ElasticSearch" };
    int fundings = 40000;
    startup bookmysport("Book My Sport", founders, techstack, fundings);

    // Call the friend function to display startup information
    displayStartupInfo(bookmysport);

    return 0;
}
