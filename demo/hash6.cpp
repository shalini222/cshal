#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{

    if (p1.second == p2.second)
    {
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

void printFreqA(int arr[], int n, int k)
{

    unordered_map<int, int> um;

    for (int i = 0; i < n; i++)
    {
        um[arr[i]]++;
    }

    vector<pair<int, int>> freq(um.begin(), um.end());

    sort(freq.begin(), freq.end(), compare);

    for (int i = 0; i < k; i++)
    {
        cout << freq[i].first << " ";
    }
}

int main()
{

    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = 8;
    int k = 2;
    printFreqA(arr, n, k);
    return 0;
}

// int arr[] = {};