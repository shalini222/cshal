//balanced_parenthesis
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{

    int n = s.size();

    stack<char> st;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if (c == '(' or c == '{' or c == '[')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {

                ans = false;
                break;
            }
        }
        else if (c == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {

                ans = false;
                break;
            }
        }
        else if (c == ']')
        {

            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {

                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    else
    {
        return ans;
    }
}

int main()
{
    string exp = "[{)}]";
    if (isValid(exp))
    {
        cout << "Valid String" << endl;
    }
    else
    {
        cout << "Invalid String" << endl;
    }
}
