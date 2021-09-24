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

int sumatk(struct node *root, int k)
{

    if (root == NULL)
    {
        return -1;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        struct node *n = q.front();
        q.pop();
        if (n != NULL)
        {
            if (level == k)
            {
                sum += n->data;
            }
            if (n->l != NULL)
            {
                q.push(n->l);
            }
            if (n->r != NULL)
            {
                q.push(n->r);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
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

    cout << sumatk(root, 2);

    return 0;
}
