//subsetswithascii codes

//substrings

#include <bits/stdc++.h>
using namespace std;

void subset(string s, string ans)
{

    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    int code = ch;

    subset(ros, ans);
    subset(ros, ans + ch);
    subset(ros, ans + (to_string(code)));
}

int main()
{

    subset("AB", " ");
    return 0;
}