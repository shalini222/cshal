#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void dnfsort(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr, low, mid);
            low++;
            mid++;
        }
        if (arr[mid] == 1)
        {
            mid++;
        }
        if (arr[mid] == 2)
        {
            swap(arr, mid, high);
            high--;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    int n = 9;
    dnfsort(arr, n);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}