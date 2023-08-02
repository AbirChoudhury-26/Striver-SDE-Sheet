#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// We need to calculate minimum energy of frog jump between any two indexex ,such that it has 1/2 jump option
int frogJump(int ind,vector<int>height, vector<int>&dp)
{
    if(ind==0)
     return 0;

    if(dp[ind]!=-1)
     return dp[ind];
    int l= frogJump(ind-1,height,dp)+abs(height[ind]-height[ind-1]);

     // 
     int r=INT_MAX;
     if(ind>1)
      r=frogJump(ind-2,height,dp)+abs(height[ind]-height[ind-2]);

    return dp[ind]=min(l,r);
}
int main()
{
    int n;
    cin>>n;
    vector<int>height(n);
     
     for(int i=0;i<n;i++)
      cin>>height[i];

    vector<int>dp(n+1,-1);

cout<<frogJump(n-1,height,dp);
  return 0;
} 