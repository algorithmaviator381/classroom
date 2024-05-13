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

    friend void displayStartupInfo(const startup& obj);
};

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
    vector<string> founders = { "Sam Altman", "Elon Musk", "Greg Brockman", "Ilya Sutskever" };
    vector<string> techstack = { "Generative Pre-trained Transformer", "python", "Neural Network", "NLP", "C++", "CUDA" };
    int fundings = 127000000;
    startup openai("OpenAI", founders, techstack, fundings);

    displayStartupInfo(openai);

    return 0;
}
