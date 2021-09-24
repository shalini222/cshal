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

int findist(struct node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return dist;
    }

    int left = findist(root->l, k, dist + 1);
    int right = findist(root->r, k, dist + 1);

    if (left != -1)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int disbtnodes(struct node *root, int n1, int n2)
{

    node *lca = LCA(root, n1, n2);

    int d1 = findist(lca, n1, 0);
    int d2 = findist(lca, n2, 0);
    return d1 + d2;
}

int main()
{

    struct node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);

    root->l->l = new node(4);
    // root->l->r = new node(5);

    //root->r->l = new node(6);
    root->r->r = new node(5);
    cout << disbtnodes(root, 4, 5);
    return 0;
}
