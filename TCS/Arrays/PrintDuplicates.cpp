#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
   set<int>s;
   for(int i=0;i<n;i++)
    cin>>v[i];

   vector<int>ans;
   for(int i=0;i<n;i++)
   {
    if(s.find(v[i])!=s.end())
      ans.push_back(v[i]);
    s.insert(v[i]);
   }

   sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
     cout<<ans[i]<<" ";
    
   
  return 0;
}