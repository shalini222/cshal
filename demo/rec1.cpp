// check if an array is sorted or not

#include <bits/stdc++.h>
using namespace std;

bool sortedarr(int arr[], int n)
{

    if (n == 1)
    {
        return true;
    }

    bool remainarr = sortedarr(arr + 1, n - 1);
    return (arr[0] < arr[1] && remainarr);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    if (sortedarr(arr, 5))
    {
        cout << "yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}