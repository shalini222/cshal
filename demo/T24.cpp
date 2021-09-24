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

struct node *inorderSucc(struct node *root)
{

    node *curr = root;
    while (curr && curr->l != NULL)
    {
        curr = curr->l;
    }

    return curr;
}

struct node *delBST(struct node *&root, int key)
{

    if (key < root->data)
    {
        root->l = delBST(root->l, key);
    }
    else if (key > root->data)
    {
        root->r = delBST(root->r, key);
    }
    else
    {
        if (root->l == NULL)
        {
            node *temp = root->r;
            free(root);
            return temp;
        }
        else if (root->r == NULL)
        {
            node *temp = root->l;
            free(root);
            return temp;
        }

        node *temp = inorderSucc(root);
        root->data = temp->data;
        root->r = delBST(root->r, temp->data);
    }
    return root;
}

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

int main()
{

    struct node *root = new node(4);
    root->l = new node(2);
    root->r = new node(5);

    root->l->l = new node(1);
    root->l->r = new node(3);

    //root->r->l = new node(6);
    root->r->r = new node(6);
    inorder(root);
    cout << endl;
    root = delBST(root, 5);
    inorder(root);
    cout << endl;

    return 0;
}