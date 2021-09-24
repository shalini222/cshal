

#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    node *l;
    node *r;

    node(int val)
    {

        data = val;
        l = NULL;
        r = NULL;
    }
};

struct Info
{
    int sz;
    int min;
    int max;
    int ans;
    bool isBST;
};

Info isbiggestBST(node *root)
{

    if (root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 0, true};
    }
    if (root->l == NULL && root->r == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }
    Info left = isbiggestBST(root->l);
    Info right = isbiggestBST(root->r);

    Info curr;
    curr.sz = (1 + left.sz + right.sz);

    if (left.isBST && right.isBST && left.max < root->data && root->data < right.min)
    {

        curr.min = min(left.min, min(right.min, root->data));
        curr.max = max(right.max, max(left.max, root->data));

        curr.ans = curr.sz;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    node *root = new node(60);
    root->l = new node(65);
    root->r = new node(70);
    root->l->l = new node(50);

    cout << "largest BST in BT is " << isbiggestBST(root).ans << endl;
    return 0;
}
