#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int main()
 {
    int n,target;
     cin>>n>>target;
   vector<int>v(n);
      for(int i=0;i<n;i++)
       cin>>v[i];
  unordered_map<int,int>visited;
    int cpx=0;
     long long count=0;
     for(int i=0;i<n;i++)
     {
         cpx^=v[i];
          if(cpx==target) count++;
          int h=cpx^target;
           if(visited.find(h)!=visited.end())
            count=count+visited[h];
        visited[cpx]++;
     }
      cout<<count<<endl;
 }