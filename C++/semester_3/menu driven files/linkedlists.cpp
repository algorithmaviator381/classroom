#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <limits>
#include <conio.h>

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

        void insertafter(const T &index, const T &data)
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

        void reverse()
        {
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

        void deleteNode(const T &data)
        {
            if (head == nullptr)
            {
                cout << "List is empty, cannot delete" << endl;
                return;
            }

            if (head->data == data)
            {
                doubleNode<T> *temp = head;
                head = head->next;
                delete temp;
                return;
            }

            doubleNode<T> *current = head;
            while (current->next != nullptr)
            {
                if (current->next->data == data)
                {
                    doubleNode<T> *temp = current->next;
                    current->next = current->next->next;
                    current->previous = current->previous->previous;
                    delete temp;
                    return;
                }

                current = current->next;
            }

            cout << "Element " << data << " not found in the list. Deletion failed." << endl;
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

class menu
{
public:
    void portal()
    {
        system("cls");
        cout << "--------------------------------------------------------" << endl;
        cout << "            Welcome to the List ADT portal" << endl;
        cout << "--------------------------------------------------------" << endl;
    }

    void header()
    {
        system("cls");
        cout << "--------------------------------------------------------" << endl;
        cout << "                   List ADT portal" << endl;
        cout << "--------------------------------------------------------" << endl;
    }

    int user_ip()
    {

        int choice;
        cout << endl
             << "--------------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;

        return choice;
    }

    int init()
    {
        int choice;

        cout << "1> Create a singly linked list" << endl;
        cout << "2> Create a doubly linked list" << endl;

        return user_ip();
    }

    int d_type()
    {
        int choice;

        cout << "What type of data would you like to store in your linked list\n\n";

        cout << "1> Integer linked list" << endl;
        cout << "2> float linked list" << endl;
        cout << "3> Character linked list" << endl;
        cout << "4> string linked list" << endl;

        return user_ip();
    }

    int operation()
    {
        int choice;

        cout << "1> Add element at the beginning of the linked list" << endl;
        cout << "2> Add element at the end of the linked list" << endl;
        cout << "3> Add element after a specific valuein the  linked list" << endl;
        cout << "4> Remove an element from the linked list" << endl;
        cout << "5> Find the length of the linked list" << endl;
        cout << "6> Reverse the linked list" << endl;
        cout << "7> Search an element in the list" << endl;
        cout << "8> Display the entire linked list" << endl;

        cout << "0> Exit" << endl;

        return user_ip();
    }
};

template <typename T>
void single_list_life(ll::singleLinkedList<T> &userlist)
{
    menu program;
    bool lifespan = true;
    T data, index;

    while (lifespan)
    {
        menu program;
        program.header();

        int choice = program.operation();

        system("cls");
        switch (choice)
        {
        case 1:

            cout << "Enter the data to insert at the beginning: ";
            cin >> data;
            userlist.insertAtStart(data);
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 2:
            cout << "Enter the data to insert at the end: ";
            cin >> data;
            userlist.insertAtEnd(data);
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 3:
            cout << "Enter the element after which you want to insert another element: ";
            cin >> index;
            cout << "Enter data to insert: ";
            cin >> data;
            userlist.insertafter(index, data);
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 4:
            cout << "Enter the element to delete from the list: ";
            cin >> data;
            userlist.deleteNode(data);
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 5:
            cout << "The list contains " << userlist.length() << " elements.";
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 6:
            userlist.reverse();
            cout << "\nYour List after reversing: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 7:
            cout << "Enter the element to search in the list: ";
            cin >> data;

            if (userlist.search(data))
            {
                cout << "Element found in the list";
            }
            else
            {
                cout << "Element not found in the list";
            }

            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 8:
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 0:
            lifespan = false;
            cout << "Exiting the application. Press any key to close window\n";
            getch();
            system("cls");
            break;

        default:
            break;
        }
    }
}

template <typename T>
void double_list_life(ll::doubleLinkedList<T> &userlist)
{
    menu program;
    bool lifespan = true;
    T data, index;

    while (lifespan)
    {
        menu program;
        program.header();

        int choice = program.operation();

        system("cls");
        switch (choice)
        {
        case 1:

            cout << "Enter the data to insert at the beginning: ";
            cin >> data;
            userlist.insertAtStart(data);
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 2:
            cout << "Enter the data to insert at the end: ";
            cin >> data;
            userlist.insertAtEnd(data);
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 3:
            cout << "Enter the element after which you want to insert another element: ";
            cin >> index;
            cout << "Enter data to insert: ";
            cin >> data;
            userlist.insertafter(index, data);
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 4:
            cout << "Enter the element to delete from the list: ";
            cin >> data;
            userlist.deleteNode(data);
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 5:
            cout << "The list contains " << userlist.length() << " elements.";
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 6:
            userlist.reverse();
            cout << "\nYour List after reversing: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 7:
            cout << "Enter the element to search in the list: ";
            cin >> data;

            if (userlist.search(data))
            {
                cout << "Element found in the list";
            }
            else
            {
                cout << "Element not found in the list";
            }

            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 8:
            cout << "\nYour List: " << endl;
            userlist.displaylist();
            getch();
            system("cls");
            break;

        case 0:
            lifespan = false;
            cout << "Exiting the application. Press any key to close window\n";
            getch();
            system("cls");
            break;

        default:
            break;
        }
    }
}

int main()
{
    menu program;
    int list_profile, d_type;
    bool life = true;

    ll::singleLinkedList<int> s_user_list_int;
    ll::doubleLinkedList<int> d_user_list_int;
    ll::singleLinkedList<float> s_user_list_float;
    ll::doubleLinkedList<float> d_user_list_float;
    ll::singleLinkedList<char> s_user_list_char;
    ll::doubleLinkedList<char> d_user_list_char;
    ll::singleLinkedList<string> s_user_list_string;
    ll::doubleLinkedList<string> d_user_list_string;

    system("cls");

    program.portal();
    cout<<"Press any key to continue...";
    getch();
    program.portal();
    list_profile = program.init();
    program.portal();
    d_type = program.d_type();

    system("cls");
    cout << "Linked list created successfully. Press any key- to continue to list operations...";
    getch();

    switch (d_type)
    {
    case 1:
        switch (list_profile)
        {
        case 1:
            single_list_life(s_user_list_int);
            break;

        case 2:
            double_list_life(d_user_list_int);
            break;

        default:
            break;
        }
        break;

    case 2:
        switch (list_profile)
        {
        case 1:
            single_list_life(s_user_list_float);
            break;

        case 2:
            double_list_life(d_user_list_float);
            break;

        default:
            break;
        }
        break;

    case 3:
        switch (list_profile)
        {
        case 1:
            single_list_life(s_user_list_char);
            break;

        case 2:
            double_list_life(d_user_list_char);
            break;

        default:
            break;
        }
        break;

    case 4:
        switch (list_profile)
        {
        case 1:
            single_list_life(s_user_list_string);
            break;

        case 2:
            double_list_life(d_user_list_string);
            break;

        default:
            break;
        }
        break;

    default:
        cout << "Select appropriate option" << endl;
        getch();
        break;
    }
}
