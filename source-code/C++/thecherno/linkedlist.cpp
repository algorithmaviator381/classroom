#include <iostream>
#include "linkedlist.h"


int main(){
    using std::cout;
    using std::cin;

    ll::LinkedList<int> myList;

    myList.insertAtStart(5);
    myList.insertAtStart(10);
    myList.insertAtStart(15);

    cout << "Linked List: ";
    myList.display(); // Output: Linked List: 15 10 5

    return 0;

}
