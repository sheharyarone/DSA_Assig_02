#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int newData)
    {
        next = nullptr;
        prev = nullptr;
        data = newData;
    }
};
class DeQueue
{
public:
    node *start;
    node *last;
    DeQueue()
    {
        start = nullptr;
        last = nullptr;
    }
    bool isEmpty()
    {
        return start == nullptr;
    }
    void insertAtFront(int data)
    {
        node *temp = new node(data);
        if (!isEmpty())
        {
            temp->next = start;
            start->prev = temp;
        }

        start = temp;
        if (last == nullptr)
        {
            last = start;
        }
    }
    void insertAtEnd(int data)
    {
        node *temp = new node(data);
        if (!isEmpty())
        {
            temp->prev = last;
            last->next = temp;
        }
        last = temp;
        if (start == nullptr)
        {
            start = last;
        }
    }
    int deleteFromStart()
    {
        node *temp = start;
        int dataToReturn = temp->data;
        if (start != last)
        {

            start = start->next;
            start->prev = nullptr;
        }
        else
        {
            start = nullptr;
            last = nullptr;
        }
        delete temp;
        return dataToReturn;
    }
    int deleteFromEnd()
    {

        node *temp = last;
        int dataToReturn = temp->data;
        if (last != start)
        {
            last = last->prev;
            last->next = nullptr;
        }
        else
        {
            start = nullptr;
            last = nullptr;
        }
        delete temp;

        return dataToReturn;
    }
    void printDeQueue()
    {
        node *temp = start;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    DeQueue d1;
    d1.insertAtFront(5);
    d1.insertAtEnd(4);
    d1.insertAtEnd(3);
    d1.insertAtEnd(2);
    d1.insertAtEnd(1);
    d1.insertAtEnd(8);
    d1.printDeQueue();
    d1.deleteFromStart();
    d1.deleteFromEnd();
    d1.printDeQueue();
    return 0;
}