#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int reverseNumber(int n)
{
   int ans=0;
   while(n>0)
   {
     int temp=n%10;
     ans=ans*10+temp;
     n/=10;
   }
   return ans;
}


int main()
{
  int n;
  cin>>n;

  int temp=0;
  while(n>0)
  {
    int digit=n%10;
     if(digit==0)
      digit=5;

    temp=temp*10+digit;

    n/=10;
  }

  cout<<reverseNumber(temp);
  return 0;
}