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

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
    //cout << endl;
}
void flattenBT(struct node *root)
{
    if (root == NULL || (root->l == NULL && root->r == NULL))
    {
        return;
    }

    flattenBT(root->l);

    if (root->l != NULL)
    {
        node *temp = root->r;
        root->r = root->l;
        root->l = NULL;

        node *t = root->r;
        while (t->r != NULL)
        {
            t = t->r;
        }
        t->r = temp;
    }

    flattenBT(root->r);
}
int main()
{

    struct node *root = new node(4);
    root->l = new node(9);
    root->r = new node(5);

    root->l->l = new node(1);
    root->l->r = new node(3);

    // root->r->l = new node();
    root->r->r = new node(6);
    //cout << disbtnodes(root, 4, 5);
    //inorder(root);
    flattenBT(root);
    inorder(root);
    return 0;
}
