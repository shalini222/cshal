//bit manipulation 2

#include <bits/stdc++.h>
using namespace std;
bool poweroftwo(int n)
{
    if (n == 0)
    {
        return false;
    }

    if ((n & n - 1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << poweroftwo(7);
}