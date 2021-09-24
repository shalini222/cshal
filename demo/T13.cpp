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

int caLheight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = caLheight(root->l);
    int rh = caLheight(root->r);
    return max(lh, rh) + 1;
}

bool checkHeight(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    checkHeight(root->l);
    checkHeight(root->r);
    int lh = caLheight(root->l);
    int rh = caLheight(root->r);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    // struct node *root = new node(1);
    // root->l = new node(2);
    // root->r = new node(3);

    // root->l->l = new node(4);
    // root->l->r = new node(5);

    // root->r->l = new node(6);
    // root->r->r = new node(7);

    struct node *root = new node(1);
    root->l = new node(2);
    // root->r = new node(3);

    root->l->l = new node(4);
    // root->l->r = new node(5);

    // root->r->l = new node(6);
    // root->r->r = new node(7);

    if (checkHeight(root))
    {
        cout << "Balanced Tree";
    }
    else
    {
        cout << "Unbalanced Tree";
    }

    return 0;
}