// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check a number
// is Perfect Number or not
int isPerfect(int N)
{
    // Stores sum of divisors
    int sum = 1;

    // Find all divisors and add them
    for (int i = 2; i < sqrt(N); i++)
    {

        if (N % i == 0)
        {

            if (i == N / i)
            {

                sum += i;
            }
            else
            {

                sum += i + N / i;
            }
        }
    }

    // If sum of divisors
    // is equal to N
    if (sum == N && N != 1)
        return 1;

    return 0;
}

// Function to return maximum
// sum of a subarray of size K
int maxSum(int arr[], int N, int K)
{
    // If k is greater than N
    if (N < K)
    {

        cout << "Invalid";
        return -1;
    }

    // Compute sum of first window of size K
    int res = 0;
    for (int i = 0; i < K; i++)
    {

        res += arr[i];
    }

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window
    int curr_sum = res;
    for (int i = K; i < N; i++)
    {

        curr_sum += arr[i] - arr[i - K];
        res = max(res, curr_sum);
    }

    // return the answer
    return res;
}

// Function to find all the
// perfect numbers in the array
int max_PerfectNumbers(int arr[], int N, int K)
{
    // The given array is converted into binary array
    for (int i = 0; i < N; i++)
    {

        arr[i] = isPerfect(arr[i]) ? 1 : 0;
    }

    return maxSum(arr, N, K);
}

// Driver Code
int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int K = 4;
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << max_PerfectNumbers(arr, N, K);

    return 0;
}