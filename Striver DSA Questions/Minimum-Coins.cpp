#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v;
    cin >> v;
    vector<int> ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    for (int i = 8; i >= 0; i--)
    {
        while (v >= coins[i])
        {
            v -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    cout<<"Minimum number of coins required is :"<<ans.size()<<endl;
     for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<" ";
}
