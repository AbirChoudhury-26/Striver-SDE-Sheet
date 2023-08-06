#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  char str[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  string s;
  cin>>s;
  string ans="";
  int n=s.length();

  for(int i=0;i<n;i++)
  {
    int x;
    if(islower(s[i]))
       x=s[i]- 'a';
    else
       x=s[i]- 'A';

    x+=13;
    x=x%26;
    // cout<<x<<" ";
 char z;
  if(islower(s[i]))
     z='a'+x;
  else
     z='A'+x;
    // cout<<endl;
    // cout<< z<<" ";
    ans+=z;
  }
//   cout<<endl;

  cout<<ans<<"";
  return 0;
}