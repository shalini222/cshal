//sum replacement

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

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->l);
    preorder(root->r);
    //cout << endl;
}

void sumreplace(struct node *root)
{

    if (root == NULL)
    {
        return;
    }
    sumreplace(root->l);
    sumreplace(root->r);

    if (root->l != NULL)
    {
        root->data += root->l->data;
    }
    if (root->r != NULL)
    {
        root->data += root->r->data;
    }
}
int main()
{

    struct node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);

    root->l->l = new node(4);
    root->l->r = new node(5);

    root->r->l = new node(6);
    root->r->r = new node(7);
    preorder(root);
    cout << endl;
    sumreplace(root);
    preorder(root);

    return 0;
}