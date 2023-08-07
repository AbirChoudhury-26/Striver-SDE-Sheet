#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void performSwap(char &a ,char &b)
{
  char c=a;
  a=b;
  b=c;

}

int main()
{
  string s;
   cin>>s;
   int n=s.length();
    for(int i=0;i<n/2;i++)
     performSwap(s[i],s[n-1-i]);

    cout<<s<<endl;
  return 0;
}