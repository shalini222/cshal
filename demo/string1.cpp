#include <bits/stdc++.h>
using namespace std;

//basics1

int main()
{
    string s = "ugfrecxazwwesdctvbgyuhjnsxdcfgv";

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
}
