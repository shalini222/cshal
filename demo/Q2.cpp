//queue using ll
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node *f;
    node *b;

public:
    queue()
    {
        f = NULL;
        b = NULL;
    }

    void push(int x)
    {
        node *n = new node(x);
        if (f == NULL)
        {
            b = n;
            f = n;
            return;
        }

        b->next = n;
        b = n;
    }

    void pop()
    {
        if (f == NULL || f > b)
        {
            cout << "Stack underflow";
            return;
        }
        node *todelete = f;
        f = f->next;
        delete todelete;
    }
    int peek()
    {
        if (f == NULL || f > b)
        {

            return -1;
        }
        return f->data;
    }

    bool empty()
    {
        if (f == NULL || f > b)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty() << endl;

    return 0;
}