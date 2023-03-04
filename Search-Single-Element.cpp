#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int main()
 {
    int n;
     cin>>n;
      vector<int>v(n);
       for(int i=0;i<n;i++)
        cin>>v[i];
    int low=0,high=v.size()-2;
     while(low<=high)
     {
        int mid=(low+high)/2;
         if(v[mid]==v[mid^1])
          low=mid+1;
        else
         high=mid-1;
     }
      cout<<v[low]<<endl;
 }