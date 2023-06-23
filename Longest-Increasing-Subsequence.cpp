#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int getans(int arr[],int n,vector<vector<int>>&dp,int ind,int prev)
{
   if(ind==n)
    return 0;

  if(dp[ind][prev+1]!=-1)
   return dp[ind][prev+1];

  int notTake= 0+ getans(arr,n,dp,ind+1,prev);
  int take=0;
   if(prev==-1 || arr[ind]>arr[prev])
    take=1+getans(arr,n,dp,ind+1,ind);

  return dp[ind][prev]=max(take,notTake);
}

int longestIncreasingSubsequence(int arr[],int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return getans(arr,n,dp,0,-1);

;}
int main()
{
  int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);


    int ans=longestIncreasingSubsequence(arr,n);
    cout<<"Lebgth is: "<<ans;
  return 0;  
}