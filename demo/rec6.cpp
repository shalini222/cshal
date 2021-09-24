//towerofHanoi

#include <bits/stdc++.h>
using namespace std;

void towerofhanoi(int n, char src, char des, char helper)
{
    if (n == 0)
    {
        return;
    }

    towerofhanoi(n - 1, src, helper, des);
    cout << " move from " << src << " to " << des << endl;
    towerofhanoi(n - 1, helper, des, src);
}

int main()
{

    towerofhanoi(3, 'A', 'B', 'C');
    return 0;
}
