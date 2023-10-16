#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtStart(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteNode(const T& data) {
        if (head == nullptr)
            return;

        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr) {
            if (current->next->data == data) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    bool search(const T& data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int length() {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> myList;
    myList.insertAtStart(5);
    myList.insertAtStart(10);
    myList.insertAtStart(15);
    myList.display();

    LinkedList<string> strings;
    strings.insertAtStart("Aditya");
    strings.insertAtEnd("Pradip");
    strings.insertAtEnd("Godse");
    strings.insertAtStart("Mr");
    strings.deleteNode("Mr");

    if (strings.search("Aditya")) {
        cout << strings.length() << endl;
    }

    strings.display();

    return 0;
}
