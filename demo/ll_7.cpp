//evenaftetodd
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

void evenafterodd(node *&head)
{

    node *odd = head;
    node *even = head->next;
    node *evenStart = even;
    node *oddStart = odd;

    while (odd->next != NULL && odd->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if (odd->next == NULL)
    {
        evenStart->next = NULL;
    }
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
    inseratnodeattail(head, 1);
    inseratnodeattail(head, 2);

    inseratnodeattail(head, 3);
    inseratnodeattail(head, 4);
    inseratnodeattail(head, 5);
    inseratnodeattail(head, 6);
    inseratnodeattail(head, 7);
    inseratnodeattail(head, 8);
    inseratnodeattail(head, 9);
    display(head);
    evenafterodd(head);
    display(head);

    return 0;
}
