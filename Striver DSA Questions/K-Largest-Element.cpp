#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, q, m;
    cin >> n >> k>>q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    cout << v[k - 1] << endl;
    while (q--)
    {
        cout << "Enter the numbers you want to add in array: ";
        cin >> m;
        int a[m];
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end(), greater<int>());
        cout << v[k - 1] << endl;
    }

    return 0;
}
