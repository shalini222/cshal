#include <bits/stdc++.h>
using namespace std;

int findKey(int arr[], int key, int start, int end)
{

    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if (key == arr[mid])
    {
        return mid;
    }

    if (arr[start] < arr[mid])
    {
        if (key > arr[start] && key < arr[mid])
        {
            return findKey(arr, key, start, mid - 1);
        }
        else
        {
            return findKey(arr, key, mid + 1, end);
        }
    }

    if (arr[end] > arr[mid])
    {
        if (key > arr[mid] && key < arr[end])
        {
            return findKey(arr, key, mid + 1, end);
        }
        else
        {
            return findKey(arr, key, start, mid - 1);
        }
    }
}

int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 4};
    int key = 8;
    int n = 8;
    int idx = findKey(arr, key, 0, n - 1);
    cout << "index of key is" << idx << endl;

    return 0;
}