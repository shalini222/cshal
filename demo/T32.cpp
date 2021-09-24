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

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void check(node *root, node **f, node **m, node **l, node **p)
{
    if (root == NULL)
    {
        return;
    }
    check(root->l, f, m, l, p);

    if (*p && root->data < (*p)->data)
    {
        if (!f)
        {
            *f = *p;
            *m = root;
        }
        else
        {
            *l = root;
        }
    }
    *p = root;
    check(root->r, f, m, l, p);
}

void recoverBST(node *root)
{
    if (root == NULL)
    {
        return;
    }
    node *f, *m, *l, *p;
    f = NULL;
    m = NULL;
    l = NULL;
    p = NULL;

    check(root, &f, &m, &l, &p);

    if (f && l)
    {

        swap(&(f->data), &(l->data));
    }

    else if (f && m)
    {
        swap(&(f->data), &(m->data));
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
    cout << endl;
}
int main()
{
    node *root = new node(6);
    root->l = new node(9);
    root->l = new node(3);
    root->l->l = new node(1);
    root->l->r = new node(4);
    root->r->r = new node(13);

    inorder(root);
    // cout << endl;
    // recoverBST(root);
    // inorder(root);
    // cout << endl;
    return 0;
}
