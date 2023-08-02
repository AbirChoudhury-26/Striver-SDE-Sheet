#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
//  Method-1 : Using Dynamic Programming


 // Subseqent element to pick or not pick so that no two adjacent are added .
//  int f(vector<int>&v,vector<int>&dp,int ind)
//  {
//   if(ind==0)
//    return v[ind];
//   if(ind<0)
//    return 0;

//    if(dp[ind]!=-1)
//     return dp[ind];

//     // Pick
//     int l=v[ind]+f(v,dp,ind-2);
//    // Not pick
//    int r=0+f(v,dp,ind-1);

//    return dp[ind]=max(l,r);

//  }
// int main()
// {
//     int n;
//     cin>>n;
//   vector<int>v(n);

//    for(int i=0;i<n;i++)
//     cin>>v[i];

//     vector<int>dp(n,-1);

//      cout<<f(v,dp,n-1);

//   return 0;
// }

//  Method -2 : Using Tabulation

int main()
{
    int n,ans;
    cin>>n;
  vector<int>v(n);

   for(int i=0;i<n;i++)
    cin>>v[i];

    vector<int>dp(n,-1);

     int prev=v[0];
     int prev2=0;

      for(int i=1;i<v.size();i++)
      {
        int take=v[i];
         if(i>1)
          take+=prev2;

        int nottake=0+prev;

         ans=max(take,nottake);
        prev2=prev;
        prev=ans;
      }

      cout<<ans;

  return 0;
}
