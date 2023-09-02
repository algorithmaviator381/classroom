#include <iostream>

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;
public:
    List() {
        head = nullptr;
    }

    // Function to insert an element into the list
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to delete an element from the list
    void deleteElement(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Element not found in the list." << std::endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        std::cout << "Element " << value << " deleted from the list." << std::endl;
    }

    // Function to search for a key element in the list and count nodes
    int searchAndCount(int key) {
        Node* current = head;
        int count = 0;

        while (current != nullptr) {
            if (current->data == key) {
                std::cout << "Element " << key << " found at position " << count + 1 << std::endl;
                return count + 1;
            }
            current = current->next;
            count++;
        }

        std::cout << "Element " << key << " not found in the list." << std::endl;
        return -1;
    }
};

int main() {
    List myList;

    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.insert(40);

    myList.deleteElement(20);

    int position = myList.searchAndCount(30);
    if (position != -1) {
        std::cout << "Number of nodes before element: " << position - 1 << std::endl;
        std::cout << "Number of nodes after element: " << 4 - position << std::endl;
    }

    return 0;
}
