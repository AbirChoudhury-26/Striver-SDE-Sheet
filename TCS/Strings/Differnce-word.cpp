#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  string s,t;
  cin>>s>>t;
  map<char,int>mp;
   for(auto it:s)
    mp[it]++;

    for(auto it1:t)
    {
         if(mp.find(it1)==mp.end())
          {
            cout<<it1<<endl;
            break;
          }
          
    }
  return 0;
}