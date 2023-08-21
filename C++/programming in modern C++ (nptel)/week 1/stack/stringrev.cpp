#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(){
    char str[20]="sonchafa";
    stack<char> s;

    for(int i=0; i<strlen(str); i++)
        s.push(str[i]);
    
    cout<<"Reversed sstring: ";
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}