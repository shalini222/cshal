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

struct node *insertBST(struct node *&root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->l = insertBST(root->l, val);
    }
    if (val > root->data)
    {
        root->r = insertBST(root->r, val);
    }
    return root;
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

int main()
{

    struct node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    inorder(root);
    // cout << endl;
    return 0;
}