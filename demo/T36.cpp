#include <bits/stdc++.h>
using namespace std;

int findboards(int boards[], int n, int mid)
{
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (sum > mid)
        {
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}

int paint(int boards[], int n, int m)
{

    int totalLength = 0;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }

    int low = k;
    int high = totalLength;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int painters = findboards(boards, n, mid);
        if (painters <= m)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;
    cout << "min boards painters can paint: " << paint(boards, n, m) << endl;
    return 0;
}