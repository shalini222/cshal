#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    struct node *l;
    struct node *r;

    node(int val)
    {

        data = val;
        l = NULL;
        r = NULL;
    }
};

void zigzag(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> currLevel;
    stack<node *> nextLevel;

    bool LefttoRight = true;

    currLevel.push(root);
    while (!currLevel.empty())
    {

        struct node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";

            if (LefttoRight)
            {
                if (temp->l)
                {
                    nextLevel.push(temp->l);
                }
                if (temp->r)
                {
                    nextLevel.push(temp->r);
                }
            }
            else
            {
                if (temp->r)
                {
                    nextLevel.push(temp->r);
                }
                if (temp->l)
                {
                    nextLevel.push(temp->l);
                }
            }
        }
        if (currLevel.empty())
        {
            LefttoRight = !LefttoRight;
            swap(currLevel, nextLevel);
        }
    }
}
int main()
{

    struct node *root = new node(12);
    root->l = new node(9);
    root->r = new node(15);

    root->l->l = new node(5);
    root->l->r = new node(10);

    //root->r->l = new node(6);
    // root->r->r = new node(6);

    zigzag(root);
    cout << endl;
    return 0;
}
