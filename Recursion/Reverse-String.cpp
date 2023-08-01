#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 void reverseString(string s,int ind)
 {
    if(ind==0)
     {
        cout<<s[ind];
        return ;
     }

     cout<<s[ind]; // It will print in reverse order
     reverseString(s,ind-1);
    //  cout<<s[ind]; // It will print in original order only
 }

int main()
{
  string s;
  cin>>s;

reverseString(s,s.length()-1);

  return 0;
}