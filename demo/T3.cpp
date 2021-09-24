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

int search(int inorder[], int start, int end, int curr)
{

    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }

    return -1;
}

struct node *buildTree(int preorder[], int inorder[], int start, int end)
{

    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;

    struct node *n = new node(curr);

    if (start == end)
    {
        return n;
    }
    int pos = search(inorder, start, end, curr);
    n->l = buildTree(preorder, inorder, start, pos - 1);
    n->r = buildTree(preorder, inorder, pos + 1, end);

    return n;
}

void printTree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printTree(root->l);
    cout << root->data << " ";
    printTree(root->r);
    //cout << endl;
}

int main()
{

    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    struct node *root = buildTree(preorder, inorder, 0, 4);
    printTree(root);
    return 0;
}

//{1, 2, 4, 3, 5};
//int inorder[] = {4, 2, 1, 5, 3
