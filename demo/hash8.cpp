//first repeating element

#include <bits/stdc++.h>
using namespace std;

void firstrepeatingele(int arr[], int n)
{

    int min = -1;

    set<int> myset;

    for (int i = n - 1; i >= 0; i--)
    {
        if (myset.find(arr[i]) != myset.end())
        {
            min = i;
        }
        else
        {
            myset.insert(arr[i]);
        }
    }
    if (min != -1)
    {
        cout << "the first repeatuing element is " << arr[min] << " it's index is " << min << endl;
    }
    else
    {
        cout << "fuck off";
    }
}

int main()
{
    int arr[] = {1, 5, 3, 7, 3, 5, 6};
    int n = 7;
    firstrepeatingele(arr, n);
    return 0;
}