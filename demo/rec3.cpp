//print first and last occuerences

#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int i, int key)
{

    if (i == n)
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }

    firstOcc(arr, n, i + 1, key);
}

int lastOcc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    int rA = lastOcc(arr, n, i + 1, key);
    if (rA != -1)
    {
        return rA;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 6, 8, 2, 4, 7, 2, 3};
    int n = 8;

    // cout << firstOcc(arr, n, 0, 2);
    cout << lastOcc(arr, n, 0, 2);

    return 0;
}
