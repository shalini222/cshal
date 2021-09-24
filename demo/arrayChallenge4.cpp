#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mx = -1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx && a[i + 1] < a[i])
        {
            count++;
            mx = a[i];
        }
    }
    cout << mx;
    return 0;
}