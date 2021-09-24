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

void intersection(node *&head1, node *&head2, int pos)
{

    node *temp1 = head1;
    pos--;
    while (pos != 0)
    {
        temp1 = temp1->next;
        pos--;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int length(node *&head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }

    return l;
}

int checkintersection(node *&head1, node *&head2)
{

    int l1 = length(head1);

    int l2 = length(head2);

    int d = 0;

    node *ptr1;
    node *ptr2;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d != 0)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
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

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    inseratnodeattail(head1, 1);
    inseratnodeattail(head1, 2);
    inseratnodeattail(head1, 3);
    inseratnodeattail(head1, 4);
    inseratnodeattail(head1, 5);
    inseratnodeattail(head1, 6);
    inseratnodeattail(head2, 9);
    inseratnodeattail(head2, 10);

    intersection(head1, head2, 4);

    display(head1);
    display(head2);
    cout << checkintersection(head1, head2) << endl;
    return 0;
}