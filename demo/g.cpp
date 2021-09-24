#include <iostream>
using namespace std;

int main()
{
    int i = 0, j = 1, k = 2;
    int m;
    m = i++ + ++i + ++j + j-- + k--;

    cout << i << "" << endl;
    cout << j << "" << endl;
    cout << k << "" << endl;
    cout << m << "" << endl;
    return 0;
}
