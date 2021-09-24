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
    n->next = head;
    head = n;
}

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

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void deleteatspecificnode(node *&head, int val)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        return;
    }

    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
}

void delatfirst(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

// node *reverse_ll_byiteration(node *&head)
// {

//     node *prevptr = NULL;
//     node *currentptr = head;
//     node *nextptr;

//     while (currentptr != NULL)
//     {
//         nextptr = currentptr->next;
//         currentptr->next = prevptr;

//         prevptr = currentptr;
//         currentptr = nextptr;
//     }

//     return prevptr;
// }

node *reverserecursion(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *temp = reverserecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}
int main()
{

    node *head = nullptr;
    inseratnodeattail(head, 3);
    inseratnodeattail(head, 4);
    inseratnodeattail(head, 5);
    inseratnodeattail(head, 6);

    display(head);
    //insertathead(head, 2);
    // display(head);
    // search(head, 3);
    //
    // deleteatspecificnode(head, 3);
    // display(head);
    // delatfirst(head);
    // display(head);

    // node *newhead = reverse_ll_byiteration(head);
    // display(newhead);
    node *newhead = reverserecursion(head);
    display(newhead);

    return 0;
}