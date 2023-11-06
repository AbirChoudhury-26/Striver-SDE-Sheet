#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cowsPossible(vector<int>v,int n,int cows,int minDist)
{

 int cowPlaced=v[0],count=1;
   for(int i=1;i<n;i++)
   {
     if(v[i]-cowPlaced>=minDist)
     {
        count++;
        cowPlaced=v[i];
     }
   }
   if(count==cows)
    return true;
    else
     return false;
}
int main()
{
    int n,cows;
    cin>>n>>cows;
     vector<int>v(n);
      for(int i=0;i<n;i++)
       cin>>v[i];
    
    sort(v.begin(),v.end());
    
    int low=1,high=v[n-1]-v[0];

     while(low<=high)
     {
        int mid=(high+low)/2;
        if(cowsPossible(v,n,cows,mid))
         low=mid+1;
        else
         high=mid-1;
     }
     cout<<"Minimum Distance is:"<<high<<endl;
}