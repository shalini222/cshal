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

node *makecycle(node *&head, int pos)
{

    node *temp = head;
    node *startnode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

bool checkcycle(node *&head)
{

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void *del_cycle(node *&head)
{

    node *slow = head;
    node *fast = head;

    do
    {

        slow = slow->next;
        fast = fast->next->next;

    } while (fast != slow);

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
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
    makecycle(head, 4);
    //display(head);
    cout << checkcycle(head) << endl;
    //display(head);
    del_cycle(head);

    cout << checkcycle(head) << endl;
    display(head);
    return 0;
}