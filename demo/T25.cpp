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

void Printpreorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Printpreorder(root->l);
    Printpreorder(root->r);
    //cout << endl;
}

struct node *consBST(int pre[], int *preIdx, int key, int min, int max, int n)
{
    if (*preIdx >= n)
    {
        return NULL;
    }

    struct node *root = NULL;

    if (key > min && key < max)
    {
        root = new node(key);
        *preIdx = *preIdx + 1;

        if (*preIdx < n)
        {
            root->l = consBST(pre, preIdx, pre[*preIdx], min, key, n);
        }
        if (*preIdx < n)
        {
            root->r = consBST(pre, preIdx, pre[*preIdx], key, max, n);
        }
    }

    return root;
}

int main()
{

    int pre[] = {10, 2, 1, 13, 11};
    int preIdx = 0;
    int n = 5;

    struct node *root = consBST(pre, &preIdx, pre[0], INT_MIN, INT_MAX, n);
    Printpreorder(root);
    return 0;
}