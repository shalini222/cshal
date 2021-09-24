#include <bits/stdc++.h>
using namespace std;

priority_queue<double, vector<double>> pqmax;
priority_queue<double, vector<double>, greater<double>> pqmin;

double insert(double x)
{

    if (pqmax.size() == pqmin.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x);
            return 0;
        }

        if (x > pqmax.top())
        {
            pqmax.push(x);
        }
        else
        {
            pqmin.push(x);
        }
    }
    else
    {

        if (pqmax.size() > pqmin.size())
        {
            if (x <= pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                float temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else
        {
            if (x <= pqmin.top())
            {
                pqmax.push(x);
            }
            else
            {
                float temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian()
{
    if (pqmax.size() == pqmin.size())
    {
        return ((pqmax.top() + pqmin.top()) / 2.0);
    }
    if (pqmax.size() > pqmin.size())
    {
        return pqmax.top();
    }
    else
    {
        return pqmin.top();
    }
}

int main()
{

    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;
    return 0;
}