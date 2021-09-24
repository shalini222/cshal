#include <iostream>
#include <cmath>
#include <math.h>
#include <limits.h>
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

int maxpathSumUtil(struct node *root, int &ans)
{

    if (root == NULL)
    {
        return 0;
    }

    int left = maxpathSumUtil(root->l, ans);
    int right = maxpathSumUtil(root->r, ans);

    int maxNode = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, maxNode);
    int singleSumpath = max(root->data, max(root->data + left, root->data + right));
    return singleSumpath;
}

int maxpathSum(struct node *root)
{
    int ans = INT_MIN;
    maxpathSumUtil(root, ans);
    return ans;
}

int main()
{

    struct node *root = new node(1);
    root->l = new node(2);
    root->r = new node(3);

    root->l->l = new node(4);
    root->r->r = new node(5);
    cout << maxpathSum(root);
    return 0;
}

//code is fine