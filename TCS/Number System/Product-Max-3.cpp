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

    sort(v.begin(),v.end());
     int one=v[n-1]*v[n-2]*v[n-3];
     int second=v[n-1]*v[0]*v[1];

     cout<<max(one,second);
  return 0;
}