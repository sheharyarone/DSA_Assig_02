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
    void insertAtFront(int data)
    {
        node *temp = new node(data);
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
    void insertAtEnd(int data)
    {
        node *temp = new node(data);
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    int deleteFromStart()
    {
        node *temp = start;
        int dataToReturn = temp->data;
        start = start->next;
        start->prev = nullptr;
        delete temp;
        return dataToReturn;
    }
    int deleteFromEnd()
    {
        node *temp = last;
        int dataToReturn = temp->data;
        last = last->prev;
        last->next = nullptr;
        delete temp;
        return dataToReturn;
    }
};
int main()
{

    return 0;
}