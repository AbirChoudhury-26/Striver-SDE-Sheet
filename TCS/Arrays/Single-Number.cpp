#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
cin>>n;
 vector<int>nums(n);
  for(int i=0;i<n;i++)
   cin>>nums[i];

unordered_map<int,int>single;
 for(auto it:nums)
   single[it]++;
 for(auto it:single)
 {
     if(it.second==1)
      {
        cout<<it.first<<endl;
        break;
      }
 }
  return 0;
}