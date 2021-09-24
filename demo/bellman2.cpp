//
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    int s;
    cin >> s;
    vector<int> dis(n, inf);
    dis[s] = 0;

    for (int it = 0; it < n - 1; it++)
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dis[v] = min(dis[v], w + dis[u]);
        }
    }

    for (auto i : dis)
    {
        cout << i << " ";
    }
    cout << endl;
}