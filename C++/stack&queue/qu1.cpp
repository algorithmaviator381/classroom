#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    
    queue<int> myqueue;

    myqueue.push(1);
    myqueue.push(0);
    myqueue.push(5);
    myqueue.push(6);
    myqueue.push(31);

    // cout<<myqueue.front()<<endl;
    while(!myqueue.empty()){
        cout<<myqueue.front()<<endl;
        myqueue.pop();
    }
    
    return 0;
}