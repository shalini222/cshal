//lcs with 3 strings by dp

#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int dp[N][N][N];

int lcs(string &s1, string &s2, string &s3, int i, int j, int k)
{

    if (i == 0 || j == 0 || k == 0)
    {
        return 0;
    }

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
    {
        dp[i][j][k] = 1 + lcs(s1, s2, s3, i - 1, j - 1, k - 1);
    }
    else
    {
        int l = lcs(s1, s2, s3, i - 1, j, k);
        int r = lcs(s1, s2, s3, i, j - 1, k);
        int q = lcs(s1, s2, s3, i, j, k - 1);
        dp[i][j][k] = max({l, r, q});
    }
    return dp[i][j][k];
}

int main()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }

    string s1, s2, s3;

    cin >> s1 >> s2 >> s3;

    cout << lcs(s1, s2, s3, s1.size(), s2.size(), s3.size());
    return 0;
}
