//threesum

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> a(n);
    for (auto &i : a)

        cin >> i;

    bool found = false;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int low = i + 1;
        int high = n - 1;

        while (low < high)
        {
            int res = a[i] + a[low] + a[high];
            if (res == t)
            {
                found = true;
            }
            if (res < t)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    if (found)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    //return 0;
}