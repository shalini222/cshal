#include <bits/stdc++.h>
using namespace std;

bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &stack)
{

    stack[src] = true;

    if (!visited[src])
    {
        visited[src] = true;
        for (auto i : adj[src])
        {
            if (visited[i])
            {
                return true;
            }
            if (!visited[i] && iscycle(i, adj, visited, stack))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    bool cycle = false;
    vector<bool> stack(n, 0);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {

        if (!visited[i] && iscycle(i, adj, visited, stack))
        {
            cycle = true;
        }
    }

    if (cycle)
    {
        cout << "cycle is present";
    }
    else
    {
        cout << "cycle is not present";
    }
}