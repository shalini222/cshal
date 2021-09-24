
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

int countsum(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countsum(root->l) + countsum(root->r) + root->data;
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

    cout << countsum(root);

    return 0;
}
