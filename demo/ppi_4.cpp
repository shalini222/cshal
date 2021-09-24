//infix to prefix

#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{

    if (c == '^')

        return 3;

    else if (c == '*' || c == '/')

        return 2;

    else if (c == '+' || c == '-')

        return 1;

    else

        return -1;
}

void infixToPretfix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            res += c;

        else if (c == ')')
            st.push(')');

        else if (c == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                char temp = st.top();
                st.pop();
                res += temp;
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                char temp = st.top();
                st.pop();
                res += temp;
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        char temp = st.top();
        st.pop();
        res += temp;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPretfix(exp);
    return 0;
}
