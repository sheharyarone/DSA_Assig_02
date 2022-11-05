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
        return start == nullptr && last == nullptr;
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
        cout << endl;
    }
};

void sort(int *arr, int size)
{
    // write your code here
    DeQueue q1, q2; // q1 is for sorted q2 is for sorting of q1
    q1.insertAtFront(arr[0]);
    for (int i = 1; i < size; i++)
    {

        if (arr[i] >= q1.last->data)
        {
            q1.insertAtEnd(arr[i]);
        }
        else
        {
            while ((arr[i] < q1.last->data))
            {

                q2.insertAtEnd(q1.deleteFromEnd());
                if (q1.isEmpty())
                {
                    break;
                }
            }
            // q2.printDeQueue();

            q1.insertAtEnd(arr[i]);
            while (!q2.isEmpty())
            {
                q1.insertAtEnd(q2.deleteFromEnd());
            }
        }
    }
    q1.printDeQueue();
}

int main()
{
    // int *arr =new {1,2,1,2,4,8,5,8,3,5,6,2,1,3,9,4,6,2,4,7};
    int *array{new int[5]{7, 10, 15, 3, 11}};
    sort(array, 5);
    return 0;
}