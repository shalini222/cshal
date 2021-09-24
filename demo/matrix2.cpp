//matrix spiral traversal

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int row_start = 0;
    int row_end = n - 1;
    int col_start = 0;
    int col_end = m - 1;

    while (row_start <= row_end && col_start <= col_end)
    {

        for (int col = col_start; col <= col_end; col++)
        {
            cout << arr[row_start][col] << " ";
        }
        row_start++;

        for (int row = row_start; row <= row_end; row++)
        {
            cout << arr[row][col_end] << " ";
        }
        col_end--;

        if (row_start <= row_end)
        {
            for (int col = col_end; col >= col_start; col--)
            {
                cout << arr[row_end][col] << " ";
            }
            row_end--;
        }

        if (col_start <= col_end)
        {
            for (int row = row_end; row >= row_start; row--)
            {
                cout << arr[row][col_start] << " ";
            }
            col_start++;
        }
    }
}
// 1 5 7 9 10 11
// 6 10 12 13 20 21
// 9 25 29 30 32 41
// 15 55 69 63 68 70
// 40 70 79 81 95 105
