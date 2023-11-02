#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int main()
 {
    int k;
    cin>>k;
    vector<int>v;
    while(k--)
    {
       int n;
       cin>>n;
        vector<int>m(n);
         for(int i=0;i<n;i++)
          {
            cin>>m[i];
             v.push_back(m[i]);
          }
    }
    sort(v.begin(),v.end());
      for(auto it:v)
       cout<<it<<" ";
 }