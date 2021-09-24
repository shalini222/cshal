#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;

void color(int u, int curr)
{
    if (col[u] != -1 && col[u] != curr)
    {
        bipart = false;
        return;
    }

    col[u] = curr;
    vis[u] = true;
    for (auto i : adj[u])
    {
        if (vis[i])
        {
            color(i, curr xor 1);
        }
    }
}

int main()
{
    bipart = true;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, 0);
    col = vector<int>(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {

        if (!vis[i])
        {
            color(i, 0);
        }
    }

    if (bipart)
    {
        cout << "the graph is biparted";
    }
    else
    {
        cout << "the graph is not biparted ";
    }
}