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
    
    int count=0,maxi=0;
     for(int i=0;i<n;i++)
     {
       if(v[i]==1)
        count++;
    else 
     count=0;

     maxi=max(count,maxi);
     }
      cout<<maxi<<endl;
 }