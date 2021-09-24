//queue using array

#include <iostream>
using namespace std;

#define n 20

class queue
{
    int *arr;
    int f;
    int b;

public:
    queue()
    {
        arr = new int[n];
        f = -1;
        b = -1;
    }

    void enqueue(int x)
    {
        if (b == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        b++;
        arr[b] = x;

        if (f == -1)
        {
            f++;
        }
    }

    void dequeue()
    {

        if (f == -1 || f > b)
        {
            cout << "Queue Undererflow" << endl;
            return;
        }

        f++;
    }

    int peek()
    {
        if (f == -1 || f > b)
        {
            //cout << "Queue Undererflow" << endl;
            return -1;
        }

        //f++;
        return arr[f];
    }

    bool empty()
    {
        if (f == -1 || f > b)
        {
            //cout << "Queue Undererflow" << endl;
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
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.empty() << endl;
    return 0;
}