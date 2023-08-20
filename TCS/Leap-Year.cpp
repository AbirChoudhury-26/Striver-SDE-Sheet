#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
  cin>>n;
   if((n%400==0) || (n%4==0 && n%100!=0))
    cout<<"Leap Year"<<endl;
   else 
    cout<<"Not a Leap year"<<endl;
  return 0;
}