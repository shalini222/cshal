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
void insertathead(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void inseratnodeattail(node *&head, int val)
{

    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void delatfirst(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *t1 = head;
    temp->next = head->next;
    head = head->next;
    delete t1;
}

void del_ll(node *&head, int pos)
{
    if (pos == 1)
    {
        delatfirst(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *t2 = temp->next;
    temp->next = temp->next->next;
    delete t2;
}

node *display(node *head)
{

    node *temp = head;

    do
    {

        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
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
    insertathead(head, 2);
    display(head);
    del_ll(head, 3);
    display(head);
    delatfirst(head);
    display(head);
    return 0;
}