#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int n;
 cin>>n;

 int temp=n,sum=0;
 while(temp>0){
    int n=temp%10;
    sum+=n*n*n;
    temp/=10;
 }
 if(sum==n)
  cout<<"Armstrong Number"<<endl;
else
 cout<<"Not a Armstrong Number"<<endl;

  return 0;
}