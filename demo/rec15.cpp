//tiling games

//kinda same as fibonacci

#include <bits/stdc++.h>
using namespace std;

int tiling(int n)
{
    if (n == -1)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }

    return tiling(n - 1) + tiling(n - 2);
}

int main()
{

    cout << tiling(4);

    return 0;
}