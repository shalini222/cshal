#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> comp;

int get_comp(int idx)
{

    if (vis[idx])
        return 0;
    vis[idx] = true;
    int ans = 1;

    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            ans += get_comp(i);
            vis[i] = true;
        }
    }

    return ans;
}

int main()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, 0);
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
            comp.push_back(get_comp(i));
        }
    }

    // for (auto i : comp)
    // {
    //     cout << i << " ";
    // }+

    long long int ans = 0;
    for (auto i : comp)
    {
        ans += i * (n - i);
    }

    cout << ans / 2 << " ";
}