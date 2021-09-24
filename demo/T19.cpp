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

void printsubtrees(struct node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printsubtrees(root->l, k - 1);
    printsubtrees(root->r, k - 1);
}

int printatk(struct node *root, struct node *target, int k)
{

    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        printsubtrees(root, k);
        return 0;
    }

    int dl = printatk(root->l, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubtrees(root->r, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printatk(root->r, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubtrees(root->l, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}

int main()
{

    struct node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);

    root->l->l = new node(4);

    printatk(root, root->l, 1);

    return 0;
}
