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

struct node *buildTree(int postorder[], int inorder[], int start, int end)
{

    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }
    int curr = postorder[idx];
    idx--;

    struct node *n = new node(curr);

    if (start == end)
    {
        return n;
    }
    int pos = search(inorder, start, end, curr);
    n->r = buildTree(postorder, inorder, pos + 1, end);
    n->l = buildTree(postorder, inorder, start, pos - 1);

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

    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    struct node *root = buildTree(postorder, inorder, 0, 4);
    printTree(root);
    cout << "\n";
    return 0;
}
