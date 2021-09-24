#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 3;
vector<vector<int>> g[N];
int cost = 0;
vector<int> dis(N), parent(N);
vector<bool> vis(N);
const int INF = 1e9;

void primMST(int source)
{

    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
    }
    set<vector<int>> s;
    dis[source] = 0;
    s.insert({0, source});

    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << endl;
        cost += w;

        for (auto it : g[x[1]])
        {
            if (vis[it[0]])
                continue;
            if (dis[it[0]] > it[1])
            {
                s.erase({dis[it[0]], it[0]});
                dis[it[0]] = it[1];
                s.insert({dis[it[0]], it[0]});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    primMST(0);
    cout << cost;
}
