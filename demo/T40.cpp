#include <bits/stdc++.h>
using namespace std;

int smallestSumsubarr(int arr[], int n, int x)
{

    int sum = 0;
    int ans = n + 1;
    int start = 0;
    int end = 0;

    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }

        while (sum > x && start < n)
        {
            if (end - start < ans)
            {
                ans = end - start;
            }
            sum -= arr[start++];
        }
    }

    return ans;
}

int main()
{

    int arr[] = {1, 4, 45, 6, 10, 19};
    int n = 6;
    int x = 51;
    int minL = smallestSumsubarr(arr, n, x);

    if (minL == n + 1)
    {
        cout << "fuck Off" << endl;
    }
    else
    {
        cout << "min length of sub array is " << minL << endl;
        return 0;
    }
};