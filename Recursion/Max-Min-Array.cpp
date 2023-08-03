#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

int findmax(vector<int>vec,int start,int end)
{
   if(start==end)
    return vec[start];

    int mid=(start+end)/2;
    int max1=findmax(vec,start,mid);
    int max2=findmax(vec,mid+1,end);
   
    return max(max1,max2);
}


int findmin(vector<int>vec,int start,int end)
{
    if(start==end)
    return vec[start];

    int mid=(start+end)/2;
    int min1=findmin(vec,start,mid);
    int min2=findmin(vec,mid+1,end);
   
    return min(min1,min2);
}


int main()
{
  int n;
   cin>>n;
   vector<int>vec(n);

    for(int i=0;i<n;i++)
     cin>>vec[i];

    int maxi=findmax(vec,0,n-1);
    int mini=findmin(vec,0,n-1);

    cout<<maxi<<" "<<mini<<endl;

  return 0;
}