//min jump by dp

// 1 3 5 8 9 2 6 7 6 8 9

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> jump(n, inf);

    if (arr[0] == 0)
    {
        cout << "Inf" << inf << endl;
        return 0;
    }
    jump[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + arr[j]))
            {
                jump[i] = min(jump[i], 1 + jump[j]);
            }
        }
    }

    cout << jump[n - 1];

    return 0;
}