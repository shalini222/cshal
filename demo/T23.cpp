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

struct node *searchBST(struct node *&root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        root->l = searchBST(root->l, key);
    }
    if (key > root->data)
    {
        root->r = searchBST(root->r, key);
    }
    //return;
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
    if (searchBST(root, 5) == NULL)
    {
        cout << "Fuck OFF";
    }
    else
    {
        cout << "exists";
    }

    return 0;
}