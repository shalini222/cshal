//check palindrome

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char arr[n + 1];
    cin >> arr;

    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "fuck off" << endl;
    }
}