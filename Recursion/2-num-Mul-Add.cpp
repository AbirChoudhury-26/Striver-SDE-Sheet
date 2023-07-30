#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int multiplyAdd(int x,int y)
{
    if(y==0)
     return 0;

    if(y>0)
     return x+multiplyAdd(x,y-1);
    else
     return -x +multiplyAdd(x,y+1);
}
int main()
{
  int n1,n2;
  cin>>n1>>n2;
   int ans=multiplyAdd(n1,n2);
   cout<<ans;
  return 0;
}