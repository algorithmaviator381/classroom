#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
struct singleNode
{
    T data;
    singleNode *next;

    singleNode(const T value) : data(value), next(nullptr) {}
};

template <typename T>
struct doubleNode
{
    doubleNode *previous;
    doubleNode *next;
    T data;

    doubleNode(const T value) : previous(nullptr), next(nullptr), data(value) {}
};

namespace ll
{
    template <typename T>
    class singleLinkedList
    {
    private:
        singleNode<T> *head;

    public:
        singleLinkedList() : head(nullptr) {}

        void insertAtStart(const T &data)
        {
            singleNode<T> *newSingleNode = new singleNode<T>(data);
            newSingleNode->next = head;
            head = newSingleNode;
        }

        void insertAtEnd(const T &data)
        {
            singleNode<T> *newSingleNode = new singleNode<T>(data);

            if (head == nullptr)
            {
                head = newSingleNode;
            }
            else
            {
                singleNode<T> *current = head;

                while (current->next != nullptr)
                {
                    current = current->next;
                }

                current->next = newSingleNode;
            }
        }

        void insertafter(const T &index, const T &data)
        {
            singleNode<T> *newnode = new singleNode<T>(data);
            singleNode<T> *current = head;

            if (head == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }

            while (current != nullptr)
            {
                if (current->data == index)
                {
                    newnode->next = current->next;
                    current->next = newnode;
                    return;
                }
                current = current->next;
            }

            cout << "The element " << index << " is not present in the list" << endl;
        }

        int length()
        {
            int count = 0;

            singleNode<T> *current = head;

            while (current != nullptr)
            {
                count++;
                current = current->next;
            }

            return count;
        }

        void displaylist()
        {
            singleNode<T> *current = head;
            if (length() != 0)
            {
                while (current != nullptr)
                {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            }
            else
            {
                cout << "List is empty" << endl;
            }
        }
    };

    template <typename T>
    class doubleLinkedList
    {
    private:
        doubleNode<T> *head;

    public:
        doubleLinkedList() : head(nullptr) {}

        void insertAtStart(const T &data)
        {
            doubleNode<T> *newNode = new doubleNode<T>(data);
            if (head != nullptr)
            {
                newNode->next = head;
                head->previous = newNode;
            }
            head = newNode;
        }

        int length()
        {
            int count = 0;
            doubleNode<T> *current = head;
            while (current != nullptr)
            {
                count++;
                current = current->next;
            }

            return count;
        }

        void displaylist()
        {
            doubleNode<T> *current = head;
            if (length() != 0)
            {
                while (current != nullptr)
                {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            }
            else
            {
                cout << "List is empty" << endl;
            }
        }
    };
}

int main()
{
    ll::singleLinkedList<std::string> slst;
    slst.insertAtStart("Aditya");
    slst.insertAtEnd("Godse");
    slst.insertafter("Aditya", "Pradip");
    slst.displaylist();

    cout << "Length of list: " << slst.length();
}
