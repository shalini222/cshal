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

node *LCA(struct node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *left = LCA(root->l, n1, n2);
    node *right = LCA(root->r, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return left;
    }
    if (right != NULL)
    {
        return right;
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
    root->r->l->l = new node(8);
    //cout << LCA(root, 4, 5);
    int n1 = 8;
    int n2 = 7;
    node *lca = LCA(root, 7, 8);

    if (lca == NULL)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true  " << lca->data << endl;
    }
    return 0;
}

/*1
2 3 
45 67
   8*/