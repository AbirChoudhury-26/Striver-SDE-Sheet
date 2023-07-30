#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

int sumofdigits(int n)
{

   if(n>=1 && n<=9)
     return n;
    return (n%10)+sumofdigits(n/10);
}
int main()
{
  int n;
  cin>>n;

  int sum=sumofdigits(n);
  cout<<sum;
  return 0;
}