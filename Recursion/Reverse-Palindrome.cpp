#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
bool isPalidromeString(string s,int start,int end)
{
   if(start>=end)
    return true;

   if(s[start]!=s[end])
    return false;

isPalidromeString(s,start+1,end-1);
}
int main()
{
  string s;
  cin>>s;
  bool ans=isPalidromeString(s,0,s.length()-1);

 if(ans)
  cout<<"YES"<<endl;
else 
 cout<<"NO"<<endl;
  return 0;
}