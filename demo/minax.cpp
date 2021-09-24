#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int long long mx = 0;
    int long long mn = 0;

    for (int i = 0; i < n / 2; i++)
    {
        mx += a[i + n / 2] - a[i];
        mn += a[2 * i + 1] - a[2 * i];
    }

    cout << mx << " " << mn << endl;
}