#include <bits/stdc++.h>
using namespace std;

int sumdivisiblebyk(vector<int> arr, int k)
{

    int sum = 0;
    pair<int, int> ans;

    bool found = false;

    for (int i = 0; i < k; i++)
    {
        sum = sum + arr[i];
    }

    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (found)
        {
            break;
        }
        sum = sum + arr[i] - arr[i - k];

        if (sum % 3 == 0)
        {
            ans = make_pair(i - k + 1, i);
            found = true;
        }
    }

    if (!found)
    {
        ans = make_pair(-1, 0);
    }
    if (ans.first == -1)
    {
        cout << "fuck Off";
    }
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k = 3;

    sumdivisiblebyk(arr, k);

    return 0;
}