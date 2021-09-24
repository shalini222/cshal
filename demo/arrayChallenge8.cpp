//max circular subarray sum

#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n)
{

    int curr_sum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        if (curr_sum < 0)
        {
            curr_sum = 0;
        }

        maxSum = max(maxSum, curr_sum);
    }

    return maxSum;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int wrap = 0;
    int nonwrap;
    nonwrap = kadane(arr, n);

    int totalsum = 0;

    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];

        arr[i] = -arr[i];
        wrap = totalsum + kadane(arr, n);
    }

    cout << max(wrap, nonwrap) << endl;
}
