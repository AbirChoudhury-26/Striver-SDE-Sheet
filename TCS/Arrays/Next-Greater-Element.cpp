#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n1, n2;
  cin >> n1 >> n2;

  vector<int> v1(n1), v2(n2);

  for (int i = 0; i < n1; i++)
    cin >> v1[i];
  for (int i = 0; i < n2; i++)
    cin >> v2[i];

  vector<int> v;

  unordered_map<int, int> mp;
  int ans = -1;
  for (int i = v2.size() - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < v2.size(); j++)
    {
      if (v2[j] > v2[i])
      {
        ans = v2[j];
        break;
      }
    }
    mp[v2[i]] = ans;
    ans = -1;
  }

    for(auto value:v1)
        {
            if(mp.find(value)!=mp.end()) 
            {
                auto it = mp.find(value);
                v.push_back(it->second);
            }
            else 
            {
                v.push_back(-1);
            }
        }

      for(auto it:v)
       cout<<it<<" ";

  return 0;
}