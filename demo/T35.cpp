#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{
    int isReq = 1;
    long sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (sum + arr[i] > mid)
        {
            isReq++;
            sum = arr[i];

            if (isReq > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }

    return true;
}

//
int minpgallocation(int arr[], int n, int m)
{

    long sum = 0;
    if (n < m)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    int start = 0;
    int end = sum;
    int ans = INT_MAX;

    while (start <= end)
    {

        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(mid, ans);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    cout << "The min pages are " << minpgallocation(arr, n, m) << endl;
    return 0;
}
