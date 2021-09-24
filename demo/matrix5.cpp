//matrix search

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
    int target;
    cin >> target;
    int r = 0;
    int c = m - 1;
    bool flag = false;
    while (r < n && c >= 0)
    {
        if (arr[r][c] == target)
        {
            flag = true;
        }
        if (arr[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    if (flag == true)
    {
        cout << "element is found";
    }
    else
    {
        cout << "element is not found";
    }
}