//optimal game stradegy

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int dp[N][N];
int a[N];

int coin(int i, int j)
{

    if (i == j)
    {
        return a[i];
    }

    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int l = a[i] + min(coin(i + 1, j - 1), coin(i + 2, j));
    int r = a[j] + min(coin(i, j - 2), coin(i + 1, j + 1));

    dp[i][j] = max(i, r);

    return dp[i][j];
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
        cin >> a[i];
    }

    cout << coin(0, n - 1);
}