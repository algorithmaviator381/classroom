#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// structure for a single node in a singly circular linked list
template <typename T>
struct circularNode
{
    T data;
    circularNode *next;

    circularNode(const T value) : data(value), next(nullptr) {}
};

namespace ll
{
    template <typename T>
    class singleCircularLinkedList
    {
    private:
        circularNode<T> *head;

    public:
        //Constroctor for created object
        singleCircularLinkedList() : head(nullptr) {}
        
        //destructor for created object
        ~singleCircularLinkedList()
        {
            if (head == nullptr)
                return;

            circularNode<T> *current = head;
            circularNode<T> *temp = nullptr;

            do
            {
                temp = current;
                current = current->next;
                delete temp;
            } while (current != head);
        }

        bool is_empty(){return head == nullptr;}

        void insertAtStart(const T &data)
        {
            circularNode<T> *newSingleNode = new circularNode<T>(data);
            if (head == nullptr)
            {
                newSingleNode->next = newSingleNode;
                head = newSingleNode;
            }
            else
            {
                circularNode<T> *temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = newSingleNode;
                newSingleNode->next = head;
                head = newSingleNode;
            }
        }

        void displaylist()
        {
            circularNode<T> *current = head;

            if (head == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }

            do
            {
                cout << current->data << " ->";
                current = current->next;
            } while (current != head);

            cout << "(Head)" << endl;
        }

        void exchangeFirstAndLast()
        {
            if (head == nullptr || head->next == head)
            {
                cout << "The list has single node. Cannot perform the exchange operation." << endl;
                return;
            }

            circularNode<T> *current = head;
            T tempData = head->data;

            while (current->next->next != head)
            {
                current = current->next;
            }

            head->data = current->next->data;
            current->next->data = tempData;
        }

        void reverse()
        {
            if (head == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }

            circularNode<T> *prev = nullptr;
            circularNode<T> *current = head;
            circularNode<T> *next = nullptr;

            do
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            } while (current != head);

            head->next = prev;
            head = prev;
        }
    };

}

int main()
{
    ll::singleCircularLinkedList<int> userList;

    userList.insertAtStart(381);
    userList.insertAtStart(32);
    userList.insertAtStart(68);
    userList.insertAtStart(323);

    cout << "List before swapping : "; // 323 ->68 ->32 ->381 ->(Head)
    userList.displaylist();

    userList.exchangeFirstAndLast();   // data in the first and last nodes has been exchanged exchanged

    cout << "List after swapping  : "; // 381 ->68 ->32 ->323 ->(Head)
    userList.displaylist();
}