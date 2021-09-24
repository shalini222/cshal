//Sliding max windows LC.239
#include <bits/stdc++.h>

using namespace std;

void getMax(int arr[], int n, int k)
{

    std::deque<int> Qi(k);
    int i;
    for (i = 0; i < k; i++)
    {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])

            Qi.pop_back();

        Qi.push_front(i);
    }

    for (; i < n; i++)
    {
        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && Qi.front() <= i - k)

            Qi.pop_front();

        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])

            Qi.pop_back();

        Qi.push_back(i);
    }
    cout << arr[Qi.front()];
}
int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    getMax(arr, n, k);
    //cout << endl;
    return 0;
}