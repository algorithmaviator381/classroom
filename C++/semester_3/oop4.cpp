#include <iostream>
#include <vector>
#include <string>

using namespace std;;

class startup{
    public:
        string name = "book my sport";
        vector<string> founders={"Aditya Godse", "Atharva Nawale", "Aditya Pawar"};
    private:
        vector<string> techstack={"MongoDB","FastAPI","ElasticSearch"};
        int fundings = 0;
    
    friend class investor;
};

class investor{
    public:
        void display(startup& obj){
            
            cout<<"Private variables: \n";
            cout<<"Name: "<<obj.name<<endl;
            cout<<"Founders: \n";
            for(int i=0;i<obj.founders.size();i++){
                cout<<"-"<<obj.founders[i]<<endl;
            };

            cout<<endl;

            cout<<"Protected variables: \n";
            cout<<"Fundings: "<<obj.fundings<<endl;
            cout<<"Tech Stack: \n";
            for(int i=0;i<obj.techstack.size();i++){
                cout<<"-"<<obj.techstack[i]<<endl;
            };
        };
};

int main(){
    startup bookmysport;
    investor angel;
    angel.display(bookmysport);

    return 0;
}