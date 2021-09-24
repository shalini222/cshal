//LIs by dp

//9
// 10 22 9 33 21 502 52 60 80

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int dp[N];

int lis(vector<int> &a, int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[n] > a[i])
        {
            dp[n] = max(dp[n], 1 + lis(a, i));
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << lis(a, n - 1);
}