#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    
    stack<int> myStack;

    myStack.push(1);
    myStack.push(0);
    myStack.push(5);
    myStack.push(6);
    myStack.push(31);

    while(!myStack.empty()){
        cout<<myStack.top()<<endl;
        myStack.pop();
    }
    
    return 0;
}