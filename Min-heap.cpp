#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        while (q--)
        {
            priority_queue<int, vector<int>, greater<int>> pq;
            int n, x;
            cin >> n;

            if (n == 0)
            {
                cin >> x;
                pq.push(x);
            }
            else if (n == 1)
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
}