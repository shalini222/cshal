#include <bits/stdc++.h>
using namespace std;

struct node
{

    int key;
    struct node *l;
    struct node *r;

    node(int val)
    {

        key = val;
        l = NULL;
        r = NULL;
    }
};

void getverticaldis(node *root, int hdis, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }

    m[hdis].push_back(root->key);
    getverticaldis(root->l, hdis - 1, m);
    getverticaldis(root->r, hdis + 1, m);
}

int main()
{
    struct node *root = new node(10);
    root->l = new node(7);
    root->r = new node(4);

    root->l->l = new node(3);
    root->l->r = new node(11);

    root->r->l = new node(14);
    root->r->r = new node(6);

    map<int, vector<int>> m;
    int hdis = 0;

    getverticaldis(root, hdis, m);

    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << " " << endl;
        }
    }
    return 0;
}
