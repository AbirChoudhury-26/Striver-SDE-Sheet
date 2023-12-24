#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int price[3]={7,10,4},k=100,ans=0;
  map<int,int>mp; 
  for(int i=0;i<3;i++)
   mp[price[i]]=i+1;

   // sort(mp.begin(),mp.end());
   for(auto it:mp)
    cout<<it.first<<" "<<it.second<<endl;

   vector<pair<int,int>>vp;
        for(int i=0;i<3;i++)
          vp.push_back({price[i],i+1});
          
         int ans=0;
         
         sort(vp.begin(),vp.end());
         
         for(auto it:vp)
         {
             int val=it.first;
             int ind=it.second;
             
             int acRem=k/val;
             int curr_val=val*min(acRem,ind);
             if(curr_val<=k)
             {
                 k-=curr_val;
                 ans+=min(acRem,ind);
             }
         }
    cout<<ans;

  return 0;
}