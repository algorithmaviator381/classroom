#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
    public:
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

        void deleteNode(const T &data)
        {
            if (head == nullptr)
            {
                cout << "List is empty, cannot delete" << endl;
                return;
            }

            if (head->data == data)
            {
                singleNode<T> *temp = head;
                head = head->next;
                delete temp;
                return;
            }

            singleNode<T> *current = head;
            while (current->next != nullptr)
            {
                if (current->next->data == data)
                {
                    singleNode<T> *temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }

                current = current->next;
            }

            cout << "Element " << data << " not found in the list. Deletion failed." << endl;
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
                    if (current != nullptr)
                    {
                        cout << " -> ";
                    }
                }
                cout << endl;
            }
            else
            {
                cout << "List is empty" << endl;
            }
        }

        bool search(const T &data)
        {

            if (head == nullptr)
            {
                cout << "List is empty" << endl;
                return false;
            }

            singleNode<T> *current = head;

            while (current != nullptr)
            {
                if (current->data == data)
                {
                    return true;
                }

                current = current->next;
            }

            return false;
        }

        void reverse()
        {
            singleNode<T> *previous = nullptr;
            singleNode<T> *current = head;
            singleNode<T> *m_next = nullptr;

            while (current != nullptr)
            {
                m_next = current->next;
                current->next = previous;
                previous = current;
                current = m_next;
            }

            head = previous;
        }
    };

    template <typename T>
    class doubleLinkedList
    {
    protected:
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

        void insertAtEnd(const T &data)
        {
            doubleNode<T> *newnode = new doubleNode<T>(data);

            if (head == nullptr)
            {
                head = newnode;
            }
            else
            {
                doubleNode<T> *current = head;

                while (current->next != nullptr)
                {
                    current = current->next;
                }

                current->next = newnode;
                newnode->previous = current;
            }
        }

        void insertAfter(const T &index, const T &data)
        {
            doubleNode<T> *newnode = new doubleNode<T>(data);
            doubleNode<T> *current = head;

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
                    newnode->previous = current;
                    current->next = newnode;
                    return;
                }
                current = current->next;
            }

            cout << "Element " << index << " not found in list" << endl;
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

        void reverse(){
            doubleNode<T> *current = head;
            doubleNode<T> *temp = nullptr;

            while (current != nullptr)
            {
                // Swap the previous and next pointers of the current node
                temp = current->previous;
                current->previous = current->next;
                current->next = temp;

                // Move to the next node
                current = current->previous;
            }

            if (temp != nullptr)
            {
                head = temp->previous;
            }
        }

        bool search(const T &data)
        {

            if (head == nullptr)
            {
                cout << "List is empty!" << endl;
                return false;
            }

            doubleNode<T> *current = head;

            while (current != nullptr)
            {
                if (current->data == data)
                {
                    return true;
                }

                current = current->next;
            }

            return false;
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
                    if (current != nullptr)
                    {
                        cout << " <->  ";
                    }
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

void sampleSingleLinkedListImplementation()
{
    ll::singleLinkedList<string> slst;
    slst.insertAtStart("Aditya");
    slst.insertAtEnd("Godse");
    slst.insertafter("Aditya", "Pradip");
    slst.insertAtStart("Mr");
    slst.deleteNode("Mr");
    // slst.reverse();
    slst.displaylist();

    if (slst.search("Aditya"))
    {
        cout << "Length of list: " << slst.length()<<endl;
    }

    cout<< slst.head->data;
}


void sampleDoubleLinkedListImplementation()
{
    ll::doubleLinkedList<int> dll;
    dll.insertAtStart(5);
    dll.insertAtStart(2);
    dll.insertAtStart(77);
    dll.insertAtEnd(10000);
    dll.reverse();

    if (dll.search(2))
    {
        dll.insertAfter(2, 11);
    }
    dll.displaylist();
    cout << "Length: " << dll.length() << endl;
}

int main()
{
    sampleSingleLinkedListImplementation();
    // sampleDoubleLinkedListImplementation();

    
}
