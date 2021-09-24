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

    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(a[i]);
    }

    int ans = 0;
    while (minh.size() > 1)
    {
        int e1 = minh.top();
        minh.pop();
        int e2 = minh.top();
        minh.pop();
        ans += e1 + e2;
        minh.push(e1 + e2);
    }
    cout << ans << endl;
    return 0;
}