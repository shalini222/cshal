#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>> pqM;
    pqM.push(2);
    pqM.push(1);
    pqM.push(3);

    cout << pqM.top() << endl;
    pqM.pop();
    cout << pqM.top() << endl;

    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(2);
    pqm.push(1);
    pqm.push(3);

    cout << pqm.top() << endl;
    pqm.pop();
    cout << pqm.top() << endl;
}