#include <bits/stdc++.h>
using namespace std;

int printofones(int num)
{
    int count = 0;
    while (num != 0)
    {
        int n = num & (num - 1);
        count++;
        num = n;
    }
    return count;
}

int main()
{
    cout << printofones(19) << endl;
}