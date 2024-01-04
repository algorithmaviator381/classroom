#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val) : data(val), next(nullptr) {}
};

class linkedList
{
private:
    node *head;

public:
    linkedList() : head(nullptr) {}

    void insert(int data)
    {
        node *newnode = new node(data);

        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            node *current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newnode;
        }
    }

    void display()
    {
        
    }
};

int main()
{
}
