//

#include <bits/stdc++.h>
using namespace std;

string replacedouble(string s)
{

    if (s.length() == 0)
    {
        return " ";
    }

    char ch = s[0];
    string rem = replacedouble(s.substr(1));

    if (ch == s[1])
    {
        return rem;
    }
    else
    {
        return (ch + rem);
    }
}

int main()
{
    cout << replacedouble("aaabbbccdddee");
    return 0;
}