#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void getmax(vector<int>num,int l,int r,vector<int>&ans)
{
    int maxi=INT_MIN;
     for(int i=l;i<=r;i++)
      maxi=max(maxi,num[i]);
    ans.push_back(maxi);
}

 int main()
{
    // Normal Approach 

    int n,k;
    cin>>n>>k;
    vector<int>v(n);
     for(int i=0;i<n;i++)
      cin>>v[i];
    
    int left=0,right=0,i,j;
     vector<int>ans;
      while(right<k-1)
       right++;
    while(right<v.size())
    {
         getmax(v,left,right,ans);
         left++;
         right++;
    }
       for(auto it:ans)
        cout<<it<<" ";
    
        
}
