//biggest number from string
//basics2

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "895641";

    sort(s.begin(), s.end(), greater<int>());

    cout << s << endl;
}
