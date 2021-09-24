#include <bits/stdc++.h>
using namespace std;

void redundent(string s)
{
    bool ans = false;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '+' or c == '-' or c == '*' or c == '/')
        {
            st.push(c);
        }
        else if (c == '(')
        {
            st.push(c);
        }

        else if (c == ')')
        {
            if (st.top() == '(')
            {
                ans = true;
            }
            while (!st.empty() && st.top() != '(')
            {
                st.pop();
            }
            st.pop();
        }
    }
    cout << ans;
}

int main()
{
    string s;
    cin >> s;
    //    redeundent(s);
    redundent(s);
    return 0;
}