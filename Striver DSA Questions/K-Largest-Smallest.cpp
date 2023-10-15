#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 // Using Min and Max Heap Concept

 int main()
 {
    int n,k;
    cin>>n>>k;
     vector<int>v(n);
      for(int i=0;i<n;i++)
       cin>>v[i];
 
    priority_queue<int>k_large;  // By default Priority quue folows Max heap,i.e Largest to smallest
      for(int i=0;i<n;i++)
       k_large.push(v[i]);
    
    int f=k-1;
    while(f>0)
    {
        k_large.pop();
        f--;
    }
   
   priority_queue<int,vector<int>,greater<int>>k_small;
      for(int i=0;i<n;i++)
       k_small.push(v[i]);

   int t=k-1;
    while(t>0)
    {
        k_small.pop();
        t--;
    }
    
    cout<<"Greater - "<<k_large.top()<<endl;
    cout<<"Smallest -"<<k_small.top()<<endl;
     
 }