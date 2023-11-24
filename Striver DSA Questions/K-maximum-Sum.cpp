#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int main()
 {
    int n,k;
     cin>>n>>k;
     vector<int>a(n),b(n);
      for(int i=0;i<n;i++)
       cin>>a[i];
     for(int j=0;j<n;j++)
      cin>>b[j];

 sort(a.begin(),a.end(),greater<int>());
 sort(b.begin(),b.end(),greater<int>());

 for(int i=0;i<k;i++)
 {
  cout<<a[i]+b[i]<<" ";
 }


 }