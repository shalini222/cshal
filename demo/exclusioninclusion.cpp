#include <bits/stdc++.h>
using namespace std;

void divisible(int n, int a, int b)
{
    int c1 = n / a;
    int c2 = n / b;

    int c3 = n / (a * b);

    int res = c1 + c2 - c3;
    cout << res << endl;
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    divisible(n, a, b);
    return 0;
}