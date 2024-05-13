#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
class Stack
{
private:
    vector<T> elements;

public:
    void push(const T &element)
    {
        elements.push_back(element);
    }

    void pop()
    {
        if (!empty())
        {
            elements.pop_back();
        }
        else
        {
            cout << "Stack is empty. Cannot pop.\n";
        }
    }

    T top() const
    {
        if (!empty())
        {
            return elements.back();
        }
        else
        {
            std::cerr << "Stack is empty. Cannot retrieve top element.\n";
            exit(EXIT_FAILURE);
        }
    }

    bool empty() const
    {
        return elements.empty();
    }

    int size() const
    {
        return elements.size();
    }
};

template <typename T>
void displayStack(Stack<T> source)
{

    cout<<"\nstack: \n";
    if (source.size() == 0)
    {
        return;
    }

    while (!source.empty())
    {
        cout<<"\t|" << source.top() <<"\t|" << endl;
        source.pop();
    }
    cout<<endl;
}


template <typename T>
class Queue
{
private:
    vector<T> elements;

public:
    void enqueue(const T &element)
    {
        elements.push_back(element);
    }

    void dequeue()
    {
        if (!empty())
        {
            elements.erase(elements.begin());
        }
        else
        {
            cout << "Queue is empty. Cannot dequeue.\n";
        }
    }

    T front() const
    {
        if (!empty())
        {
            return elements.front();
        }
        else
        {
            std::cerr << "Queue is empty. Cannot retrieve front element.\n";
            exit(EXIT_FAILURE);
        }
    }

    bool empty() const
    {
        return elements.empty();
    }

    int size() const
    {
        return elements.size();
    }
};

int main()
{
    Stack<string> intStack;
    intStack.push("My");
    intStack.push("Name");
    intStack.push("Is");
    intStack.push("Khan");

    cout << "Stack size: " << intStack.size() << endl;
    cout << "Top element: " << intStack.top() << endl;

    displayStack(intStack);

    intStack.pop();
    cout << "After popping, top element: " << intStack.top() << endl;

    Queue<string> stringQueue;
    stringQueue.enqueue("My");
    stringQueue.enqueue("Name");
    stringQueue.enqueue("Is");
    stringQueue.enqueue("Khan");

    cout << "\nQueue size: " << stringQueue.size() << endl;
    cout << "Front element: " << stringQueue.front() << endl;

    stringQueue.dequeue();
    cout << "After dequeuing, front element: " << stringQueue.front() << endl;

    return 0;
}
