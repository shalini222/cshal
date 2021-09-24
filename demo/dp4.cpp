//knapsack 0-1 by dp

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int wt[N], val[N];
int dp[N][N];

int knapsack(int n, int w)
{
    if (n <= 0)
    {
        return 0;
    }
    if (w <= 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] > w)
    {
        dp[n][w] = knapsack(n - 1, w);
    }

    else
    {
        dp[n][w] = max(knapsack(n - 1, w), knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);
    }
    return dp[n][w];
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int w;
    cin >> w;

    cout << knapsack(n, w) << endl;
}