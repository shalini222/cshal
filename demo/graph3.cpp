#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
vector<int> adj[N];
bool vis[N];

void dfs(int node)
{

    // preorder

    vis[node] = 1;
    // cout << node << " ";

    //inorder

    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (vis[*it])
            ;
        else
        {
            dfs(*it);
        }
    }
    cout << node << " ";
}

int main()
{

    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
}