#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    explicit node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class linkedList
{
public:
    node *head;
    node *tail;
    node *ploc;
    node *loc;

    linkedList()
    {
        head = nullptr;
        tail = nullptr;
        ploc = nullptr;
        loc = nullptr;
    }

    bool isempty() const
    {
        return head == nullptr;
    }

    int length() const
    {
        node *temp = head;
        int n = 0;

        while (temp != nullptr)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }

    void insetAtHead(int val)
    {
        node *newnode = new node(val);
        if (isempty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertAtTail(int val)
    {
        node *newnode = new node(val);
        if (isempty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertAtPos(int val, int idx)
    {
        if (idx == 0)
        {
            insetAtHead(val);
        }
        else if (idx == length() - 1)
        {
            insertAtTail(val);
        }
        else
        {
            node *newnode = new node(val);
            node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            node *n = temp->next;
            temp->next = newnode;
            newnode->next = n;
        }
    }

    void printll() const
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int search(int val) const
    {
        node *temp = head;
        int idx = 0;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void insertSorted(int val)
    {
        node *temp = head;
        int n = 0;
        while (temp->data < val)
        {
            if (temp->next == nullptr)
            {
                insertAtTail(val);
                return;
            }
            temp = temp->next;
            n++;
        }
        insertAtPos(val, n);
    }
    void swapNodes(int x, int y)
    {
        node *prevX = nullptr;
        node *prevY = nullptr;
        node *currX = nullptr;
        node *currY = nullptr;
        loc = head;
        ploc = nullptr;
        while (loc != nullptr)
        {
            if (loc->data == x)
            {
                prevX = ploc;
                currX = loc;
            }
            else if (loc->data == y)
            {
                prevY = ploc;
                currY = loc;
            }
            ploc = loc;
            loc = loc->next;
        }
        node *nextX = currX->next;

        currX->next = currY->next;
        currY->next = nextX;

        if (currX != head)
        {
            prevX->next = currY;
        }
        if (currY != head)
        {
            prevY->next = currX;
        }

        if (currX == head)
        {
            head = currY;
        }
        if (currX == tail)
        {
            tail = currY;
        }
        if (currY == head)
        {
            head = currX;
        }
        if (currY == tail)
        {
            tail = currX;
        }
        cout << currX->data << endl;

        cout << currY->data << endl;
    }
};

int main()
{
    linkedList ll;
    ll.insetAtHead(1);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    ll.printll();
    ll.swapNodes(8, 1);
    ll.printll();

    return 0;
}