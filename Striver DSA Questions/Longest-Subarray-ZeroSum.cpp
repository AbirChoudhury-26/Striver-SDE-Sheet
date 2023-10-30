#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int n;
     cin>>n;
      vector<int>v(n);
for(int i=0;i<n;i++)
  cin>>v[i];

unordered_map<int,int>mp;
 int sum=0,maxi=0;
  for(int i=0;i<n;i++)
  {
    sum+=v[i];

     if(sum==0)
      maxi=i+1;
     else{
         if(mp.find(sum)!=mp.end())
         {
           maxi=max(maxi,i-mp[sum]);
         } 
         else
          mp[sum]=i;
      }
  }

   cout<<maxi<<endl;
 }