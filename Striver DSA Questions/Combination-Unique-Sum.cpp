#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recurCombination(int ind,vector<int>&arr,int target,vector<int>&ds,vector<vector<int>>&ans)
{
      if(target==0)
      {
        ans.push_back(ds);
         return;
      }
       for(int i=ind;i<arr.size();i++)
       {
         if(i>ind && arr[i]==arr[i-1]) continue;
          if(arr[i]>target)  break;
           ds.push_back(arr[i]);
            recurCombination(i+1,arr,target-arr[i],ds,ans);
            ds.pop_back();
       }
}
vector<vector<int>>uniqueSumCombination(vector<int>&v ,int target)
{
     sort(v.begin(),v.end());
    vector<vector<int>>ans;
    vector<int>ds;
     recurCombination(0,v,target,ds,ans);
      return ans;

}
int main()
{
    int n,target;
    cin>>n>>target;
     vector<int>v(n);
      for(int i=0;i<n;i++)
       cin>>v[i];
    vector<vector<int>>ans=uniqueSumCombination(v,target);
    cout<<"[";
     for(int i=0;i<ans.size();i++)
     {
        cout<<"[";
         for(int j=0;j<ans[i].size();j++)
          cout<<ans[i][j]<<" ";
        cout<<"]";
     }
     cout<<"]";
}