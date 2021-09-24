//missing smallest positive number

#include <bits/stdc++.h>
using namespace std;

int mspn(int arr[], int n)
{

    bool presence[n + 1] = {false};

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            presence[arr[i]] = true;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (!presence[i])
        {
            return i;
        }
    }
    return n + 1;
}

int main()
{
    int arr[] = {0, 2, 10, -10, -30};
    int n = 5;
    cout << mspn(arr, n);
    return 0;
}