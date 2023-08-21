#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            ans.push_back(n / i);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}