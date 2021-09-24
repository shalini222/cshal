
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

bool isBST(struct node *root, struct node *min = NULL, struct node *max = NULL)
{

    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool L = isBST(root->l, min, root);
    bool R = isBST(root->r, root, max);
    return L and R;
}

int main()
{

    struct node *root = new node(11);
    root->l = new node(2);
    root->r = new node(13);

    if (isBST(root))
    {
        cout << " Valid";
    }
    else
    {
        cout << " Invalid";
    }
    return 0;
}