//optimal approch of measuring of dia of BT

//diameter of a BT

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

int calcDiameter(struct node *root, int *height)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = 0;
    int rh = 0;

    int lDiameter = calcDiameter(root->l, &lh);
    int rDiameter = calcDiameter(root->r, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(lDiameter, rDiameter));
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
    int height = 0;
    //cout << countsum(root);
    cout << calcDiameter(root, &height);

    return 0;
}
