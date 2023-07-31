#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

 int arraysum(int a[],int size)
 {
    if(size==0)
     return 0;
    else
    return a[size-1]+arraysum(a,size-1);
 }
int main()
{
  
  int n;
   cin>>n;
   int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    int sum=arraysum(a,5);

     cout<<sum<<endl;
  return 0;
}