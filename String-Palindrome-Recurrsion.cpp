#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool palindromeCheck(int i,string s,int n)
{
   if(i>=n/2)
    return true;
   
   if(s[i]!=s[n-i-1])
    return false;
   return palindromeCheck(i+1,s,n);
}
int main()
{
    string s;
    cin>>s;
   bool ans= palindromeCheck(0,s,s.length());
     if(ans)
      cout<<"String is palindrome"<<endl;
    else 
    cout<<"String ,Not a Palindrome"<<endl;
}