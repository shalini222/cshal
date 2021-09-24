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

void inseratnodeattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

int length(node *head)
{

    int l = 0;
    node *temp = head;
    while (temp->next != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *kappend(node *&head, int k)
{

    node *newTail;
    node *newHead;
    node *tail = head;

    int l = length(head);
    int count = 1;
    k = k % l;
    while (tail->next != NULL)
    {

        if (count == l - k)
        {

            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }

        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;
    head = newHead;

    return newHead;
}

void display(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    node *head = NULL;
    inseratnodeattail(head, 3);
    inseratnodeattail(head, 4);
    inseratnodeattail(head, 5);
    inseratnodeattail(head, 6);
    inseratnodeattail(head, 7);
    inseratnodeattail(head, 8);
    display(head);
    node *newhead = kappend(head, 2);
    display(newhead);

    return 0;
}