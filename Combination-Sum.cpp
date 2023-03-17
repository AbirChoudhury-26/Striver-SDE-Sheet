#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recursionCombination(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds)
{
if(ind==arr.size())
 {
     if(target==0)
      ans.push_back((ds));
    return ;
 }

 if(arr[ind]<=target)
 {
  ds.push_back(arr[ind]);
   recursionCombination(ind,target-arr[ind],arr,ans,ds);
  ds.pop_back();
 }
  recursionCombination(ind+1,target,arr,ans,ds);

}
vector<vector<int>>combinationSum(vector<int>&candidate,int target)
{
    vector<vector<int>>ans;
    vector<int>ds;
       recursionCombination(0,target,candidate,ans,ds);
return ans;
}
int main()
{
    int n,target;
    cin>>n>>target;
      vector<int>v(n);
       for(int i=0;i<n;i++ )
        cin>>v[i];
  vector<vector<int>>ans=  combinationSum(v,target);
     for(int i=0;i<ans.size();i++)
     {
       for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
      cout<<endl;
     }

}