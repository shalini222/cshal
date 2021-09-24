//dikstrj

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dis(n + 1, INF);
    vector<vector<pair<int, int>>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int source;
    cin >> source;

    set<pair<int, int>> s;
    dis[source] = 0;
    s.insert({0, source});

    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : g[x.second])
        {
            if (dis[it.first] > dis[x.second] + it.second)
            {
                s.erase({dis[it.first], it.first});
                dis[it.first] = dis[x.second] + it.second;
                s.insert({dis[it.first], it.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] < INF)
        {
            cout << dis[i] << " ";
        }
        else
        {
            cout << -1 << endl;
        }
    }
}