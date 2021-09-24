//subarray with given sum

#include <bits/stdc++.h>
using namespace std;

int swgs(int arr[], int n, int sum)
{

    int curr_sum = arr[0];
    int start = 0;
    int i;

    for (i = 1; i < n; i++)
    {

        while (curr_sum > sum && start < i - 1)
        {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == sum)
        {
            cout << "the index starts from " << start << " to " << i - 1;
            return 1;
        }

        if (i < n)
        {
            curr_sum += arr[i];
        }
    }

    cout << "fuck you";
    return 0;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = 8;
    int sum = 23;
    swgs(arr, n, sum);
    return 0;
}
