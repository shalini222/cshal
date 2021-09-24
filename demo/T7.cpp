
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

int countnodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countnodes(root->l) + countnodes(root->r) + 1;
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

    cout << countnodes(root);

    return 0;
}

//total nodes