#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "kojuffvcecrdffiojnuubytxxdddfffnnnuybtgxxddsssssvvbjbnufff";
    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    char ans = 'a';
    int maxF = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxF)
        {
            maxF = freq[i];
            ans = 'a' + i;
        }
    }

    cout << maxF << " " << ans << endl;
}
