#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
  cin>>n;
  int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];

    int sum=0;

     for(int i=0;i<n;i++)
     {
         if(a[i]==8)
          sum+=5;
        else if(a[i]%2==0)
         sum+=1;
        else 
         sum+=3;
     }

     cout<<sum<<endl;
  return 0;
}