#include <iostream>
#include <vector> 

using namespace std;

class bookmysport{
    private:
        vector<string> services;
        int cost;
    
    protected:
        vector<string> techstack;
        int staff;

    public:
        bookmysport(){
            services = {"Search_venue", "Book_venue", "Find_players"};
            techstack = {"MongoDB", "FastAPI", "Firebase", "Python"};

            cost=150000;
            staff=130;
        }

        friend class investor;
};

class investor {
    public:
        void display(bookmysport& item){
            cout<<"Private variables: \n";
            cout<<"Cost: "<<item.cost<<endl;
            for(int i=0; i<item.services.size(); i++){
                cout<<item.services[i]<<" ";
            };

            cout<<endl<<endl;

            cout<<"Procted variables: \n";
            cout<<"Staff: "<<item.staff<<endl;
            for(int i=0; i<item.techstack.size(); i++){
                cout<<item.techstack[i]<<" ";
            };
        };
};

int main(){
    bookmysport employee;
    investor aditya;
    aditya.display(employee);
    return 0;
}