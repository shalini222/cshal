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

struct node *sortedarrayBST(int arr[], int start, int end)
{

    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct node *root = new node(arr[mid]);

    root->l = sortedarrayBST(arr, start, mid - 1);
    root->r = sortedarrayBST(arr, mid + 1, end);
    return root;
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->l);
    preorder(root->r);
    //cout << endl;
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    struct node *root = sortedarrayBST(arr, 0, 4);
    preorder(root);
}