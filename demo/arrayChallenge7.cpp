//max subarray sum

//kadane algo

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int curr_sum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        curr_sum += a[i];

        if (curr_sum < 0)
        {
            curr_sum = 0;
        }

        maxSum = max(maxSum, curr_sum);
    }

    cout << maxSum << endl;
}