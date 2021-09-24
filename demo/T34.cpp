#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int m, int arr[], int n, int k)
{

    int pos = arr[0], ele = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= m)
        {
            pos = arr[i];
            ele++;
        }
        if (ele == k)
        {
            return true;
        }
    }

    return false;
}

int maxDis(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int res = -1;
    int l = 1;
    int r = arr[n - 1];

    while (l < r)
    {
        int m = (l + r) / 2;
        if (isFeasible(m, arr, n, k))
        {
            res = max(res, m);
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 8, 4, 9};
    int n = 5;
    int k = 3;
    cout << " the dist is : " << maxDis(arr, n, k);
    return 0;
}
