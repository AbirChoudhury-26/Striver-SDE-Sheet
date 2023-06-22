#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knapsackfill( vector<int>&wt,vector<int>&val, vector<vector<int>>&dp,int ind,int W)
{
  if(ind==0)
  {
    if(wt[0]<=W)
     return val[0];
    else
     return 0;
  }

   if(dp[ind][W]!=-1)
    return dp[ind][W];

   int notTake= 0+ knapsackfill(wt,val,dp,ind-1,W);

    int take=INT_MIN;
     if(wt[ind]<=W)
      take= val[ind]+ knapsackfill(wt,val,dp,ind-1,W-wt[ind]);

return dp[ind][W]=max(take,notTake);
}

int knapsack(vector<int>&wt,vector<int>&val,int n,int W)
{
    vector<vector<int>> dp(n,vector<int>(W+1,-1));

     return knapsackfill(wt,val,dp,n-1,W);
}
int main()
{
  vector<int> wt = {1,2,4,5};
  vector<int> val = {5,4,8,6};
  int W=5;
  
  int n = wt.size();
  cout<<knapsack(wt,val,n,W);
  return 0;
}