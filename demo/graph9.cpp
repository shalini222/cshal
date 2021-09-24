//disjoint

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N);

void make(int v)
{

    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{

    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])

            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{

    for (int i = 0; i < N; i++)
    {
        make(i);
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
    }
    bool cycle = false;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            cycle = true;
        }
        else
        {
            union_set(u, v);
        }
    }
    if (cycle == true)
    {
        cout << "there is a cycle";
    }
    else
    {
        cout << "there is no cycle";
    }
}
