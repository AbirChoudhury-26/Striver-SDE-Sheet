#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subsetSumHelp(int ind, vector<int>&arr, vector<int>&ans, int n, int sum)
{
   if(ind==n)
    {
        ans.push_back(sum);
         return ;
    }

     subsetSumHelp(ind+1,arr,ans,n,sum+arr[ind]);
     subsetSumHelp(ind+1,arr,ans,n,sum);
}

vector<int>subsetsum(vector<int>v,int n)
{
 vector<int>ans;
  subsetSumHelp(0,v,ans,n,0);
   sort(ans.begin(),ans.end());
   return ans;
}

int main()
{
    int n;
    cin>>n;
     vector<int>v(n);
      for(int i=0;i<n;i++)
       cin>>v[i];
     vector<int>ans=subsetsum(v,v.size());

      cout<<"Sum of all subsets are:"<<endl;
       for(auto it:ans)
        cout<<it<<" ";

}