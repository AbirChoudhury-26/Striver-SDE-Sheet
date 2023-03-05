#include<iostream>
#include<bits/stdc++.h>
 using namespace std;
  int main()
  {
    int n,m;
     cin>>n>>m;

    vector<int>v1(n),v2(m);
     for(int i=0;i<n;i++)
      cin>>v1[n];
    for(int i=0;i<m;i++)
     cin>>v2[m];
    
     int i=0,j=0,k=0;
    vector<int>finalArray(n+m);
     while(i<m && j<n){
        if(v1[i]<v2[j])
         finalArray.push_back(v1[i]);
        else
         finalArray.push_back(v2[j]);
     }

     if(i<m)
     {
        while(i<m)
         finalArray.push_back(v1[i]);
     }
     if(j<n)
     {
        while(j<n)
         finalArray.push_back(v2[j]);
     }
  }