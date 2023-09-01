#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   string s;
   char ansArray[17]="0123456789abcdef";
   int num;
   cin>>num;

   unsigned int ourNumber=num;
   while(ourNumber)
   {
    s+=ansArray[ourNumber%16];
    ourNumber/=16;
   }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
  return 0;
}