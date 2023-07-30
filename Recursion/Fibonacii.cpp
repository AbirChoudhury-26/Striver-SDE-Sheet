#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 int fibonacii(int n)
 {
    if(n==0)
     return 0;
    else if(n==1)
     return 1;

    return fibonacii(n-1)+fibonacii(n-2);

 }
int main()
{
  
  int n;
  cin>>n;
  int fabi=fibonacii(n);

    for(int i=0;i<n;i++)
     cout<<fibonacii(i)<<" ";
     
  return 0;
}