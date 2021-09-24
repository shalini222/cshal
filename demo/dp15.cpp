//ugly numbers by dp

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int c2(0), c3(0), c5(0);

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});

        if (dp[i] == 2 * dp[c2])
        {
            c2++;
        }
        if (dp[i] == 3 * dp[c3])
        {
            c3++;
        }
        if (dp[i] == 5 * dp[c5])
        {
            c5++;
        }
    }

    cout << dp[n - 1];
}