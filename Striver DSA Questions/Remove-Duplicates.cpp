#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,j=0;
    cin>>n;
    vector<int>v(n),res(n,0);
     for(int i=0;i<n;i++)
      cin>>v[i];
    
    set<int>s;
    for(int i=0;i<n;i++)
     s.insert(v[i]);
    
  for(auto it:s)
   res[j++]=it;

 for(auto it:res)
   cout<<it<<" ";
   
} 
