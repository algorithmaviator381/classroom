#include <iostream>
#include <string>

using namespace std;

void print_2d_matrix(auto arr){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // string str[3] = {"Cat", "Dog", "Mat"};
    // string other_str[3];

    // cout<<"Initial String\n";
    // print_2d_matrix(str);
    // cout<<"\n\nUpdated String\n";
    // print_2d_matrix(other_str);
}

