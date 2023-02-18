#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int main()
 {
    int n,watertrap=0;
    cin>>n;
    vector<int>h(n);
      for(int i=0;i<n;i++)
       cin>>h[i];
   int prefix[n],suffix[n];

   prefix[0]=h[0],suffix[n-1]=h[n-1];

   for(int i=1;i<n;i++)
    prefix[i]=max(h[i],prefix[i-1]);
   for(int i=n-2;i>=0;i--)
    suffix[i]=max(h[i],suffix[i+1]);

  for(int i=0;i<n;i++)
   watertrap+=min(prefix[i],suffix[i])-h[i];
cout<<watertrap<<endl;
 }