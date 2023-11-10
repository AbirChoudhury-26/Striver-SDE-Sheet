#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fibonacii(int n)
{
  if(n<=1)
   return n;
 int last=fibonacii(n-1);
 int slast=fibonacii(n-2);
  return last+slast;
}

int main()
{
int n,i=0;
cin>>n;
 while(i<=n)
 {
     cout<<fibonacii(i)<<" ";
     i++;
 }
}