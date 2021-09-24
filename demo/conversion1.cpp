#include <iostream>
using namespace std;

int conversion1(int n)
{
    int z = 0;
    int x = 1;
    while (n > 0) //binary to decimal
    {
        int y = n % 10;
        z += y * x;
        x *= 2;
        n /= 10;
    }
    return z;
}

int main()
{

    int n;
    cin >> n;

    int ans = conversion1(n);
    cout << ans << endl;

    return 0;
}