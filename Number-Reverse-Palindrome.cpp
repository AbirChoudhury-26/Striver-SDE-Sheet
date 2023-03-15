#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverseNumber(int i,vector<int>&v,int n)
{
    if(i>=n/2)
     return;
    swap(v[i],v[n-i-1]);         // Inbuilt function in C++
    reverseNumber(i+1,v,n);
}
int main()
{
    int n;
     cin>>n;
      vector<int>v(n);
       for(int i=0;i<n;i++)
        cin>>v[i];
    reverseNumber(0,v,n);
     for(auto it:v)
      cout<<it<<" ";
      cout<<endl;
     
}