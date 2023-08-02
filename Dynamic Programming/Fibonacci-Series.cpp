#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int dpFibonacii(int  n,vector<int>&dp)
{
     if(n<=1)
      return n;

    if(dp[n]!=-1)
     return dp[n];

    return dp[n]=dpFibonacii(n-1,dp)+dpFibonacii(n-2,dp);
}
int main()
{
  int n;
   cin>>n;
  vector<int>dp(n+1,-1);
  cout<<dpFibonacii(n,dp);
  return 0;
}