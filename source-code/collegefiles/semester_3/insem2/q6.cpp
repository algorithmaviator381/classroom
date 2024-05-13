// 6. WRITE A PROGRAM TO DEMONSTRATE FRIEND FUNCTION.
// Sol.:

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class startup
{
public:
    string m_name;
    vector<string> m_founders;

protected:
    vector<string> m_techstack;

private:
    int m_fundings;
    
public:
    startup(const string &startupName, vector<string> founders, vector<string> techstack, int fundings)
    {
        m_name = startupName;
        m_founders = founders;
        m_fundings = fundings;
        m_techstack = techstack;
        ;
    }

    void displayFounders(){
        cout << "Founders: \n";
        for (const string &founder : m_founders)
        {
            cout << "\t-" << founder << endl;
        };
    }

    friend class investor;

    friend void displayStartup(const startup &obj);
};

void displayStartup(const startup& obj){
    {
        cout << "Private variables: \n";
        cout << "Name: " << obj.m_name << endl;
        cout << "Founders: \n";
        for (const string &founder : obj.m_founders)
        {
            cout << "\t-" << founder << endl;
        };

        cout << endl;

        cout << "Protected variables: \n";
        cout << "Fundings: " << obj.m_fundings << endl;
        cout << "Tech Stack: \n";
        for (const string &tech : obj.m_techstack)
        {
            cout << "\t-" << tech << endl;
        };
    }
}

class investor{};

int main(){
    vector<string> founders = { "Aditya Godse", "Richard henricks", "Gilfoyle" };
    vector<string> techstack = { "MongoDB", "FastAPI", "ElasticSearch" };
    int fundings = 4000000;
    startup piedPiper("pied piper", founders, techstack, fundings);

    displayStartup(piedPiper);
}