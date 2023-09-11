#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    
    stack<int> mystack;

    mystack.push(1);
    mystack.push(0);
    mystack.push(5);
    mystack.push(6);
    mystack.push(31);

    while(!mystack.empty()){
        cout<<mystack.top()<<endl;
        mystack.pop();
    }
    
    return 0;
}