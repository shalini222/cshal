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
node *knodes(node *&head, int k)
{

    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    int count = 0;

    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = knodes(nextptr, k);
    }
    return prevptr;
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

    node *newhead = knodes(head, 2);
    display(newhead);

    return 0;
}