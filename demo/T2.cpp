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

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
    //cout << endl;
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->l);
    postorder(root->r);
    cout << root->data << " ";
    // cout << endl;
}
int main()
{

    struct node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);

    root->l->l = new node(4);
    root->l->r = new node(5);

    root->r->l = new node(7);
    root->r->r = new node(8);
    //preorder(root);
    // inorder(root);
    postorder(root);
    return 0;
}
