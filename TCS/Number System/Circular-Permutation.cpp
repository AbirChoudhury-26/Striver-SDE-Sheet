#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
cin>>n;  
 int result=1;
 n=n-1;
  while(n>0)
   {
    result=result*n;
    n--;
   }
   cout<<result<<endl;
  return 0;
}