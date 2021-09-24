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

void leftview(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout << curr->data << " ";

                if (curr->l != NULL)
                {
                    q.push(curr->l);
                }
                if (curr->r != NULL)
                {
                    q.push(curr->r);
                }
            }
        }
    }
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

    leftview(root);

    return 0;
}

//     1
// /      \
// 2      3
// /  \  /\
// 4  5  6  7
