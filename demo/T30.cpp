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

bool isIdentical(node *&root1, node *&root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->l, root2->l);
        bool cond3 = isIdentical(root1->r, root2->r);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
    }
}

int main()
{
    node *root1 = new node(2);
    root1->l = new node(1);
    root1->r = new node(3);

    node *root2 = new node(2);
    root2->l = new node(1);
    root2->r = new node(3);

    if (isIdentical(root1, root2))
    {
        cout << " BST are equal";
    }
    else
    {
        cout << " BST are inequal";
    }
    return 0;
}