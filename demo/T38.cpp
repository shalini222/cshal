#include <bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int left, int right, int n)
{

    int mid = left + (right - left) / 2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
    {
        return mid;
    }

    if (mid > 0 && arr[mid - 1] > arr[mid])
    {
        return findPeak(arr, left, mid - 1, n);
    }

    else
    {
        return findPeak(arr, mid + 1, right, n);
    }
}

int main()
{
    int arr[] = {0, 6, 8, 5, 7, 9};
    int n = 6;
    cout << findPeak(arr, 0, n - 1, n);
    return 0;
}