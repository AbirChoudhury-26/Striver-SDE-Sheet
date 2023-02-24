#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Normal Approach
    int n,sum,n1,n2;
    cin>>n>>sum;
    //  vector<int>v(n),store(n),res;

    //   for(int i=0;i<n;i++)
    //    cin>>v[i];
    //  store=v;

    // sort(store.begin(),store.end());
    //  int l=0,r=store.size()-1;
    //   while(l<r)
    //   {
    //      if(store[l]+store[r]==sum)
    //      {
    //       n1=store[l];
    //       n2=store[r];
    //        break;
    //      }
    //      else if(store[l]+store[r]< sum)
    //       l++;
    //     else
    //      r--;
    //   }
    //    for(int i=0;i<v.size();i++)
    //    {
    //      if(n1==v[i])
    //        res.push_back(i);
    //     else if(n2==v[i])
    //      res.push_back(i);
    //    }
    //   for(auto it:res)
    //    cout<<it<<" ";


  // Map Method

  unordered_map<int,int>mp;
  vector<int>nums(n),res;
     for(int i=0;i<n;i++)
      cin>>nums[i];

   for(int i=0;i<n;i++)
   {
     if(mp.find(sum-nums[i])!=mp.end())
     {
       res.push_back(i);
       res.push_back(mp[sum-nums[i]]);
     }
     mp[nums[i]]=i;
   }
    for(auto it:res)
    {
     cout<<it<<" ";
     cout<<endl;
    }

}