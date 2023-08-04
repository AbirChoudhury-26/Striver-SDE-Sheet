#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
bool sortByVal(const pair<char,int>&a,const pair<char,int>&b)
{
    return a.second<b.second;
}
int main()
{
  string s;
  cin>>s;

  map<char,int>mp;
  vector<pair<char,int>>vec;

  for(int i=0;i<s.length();i++)
   mp[s[i]]=i;

   for(auto it=mp.begin();it!=mp.end();it++)
    vec.push_back({it->first,it->second});

sort(vec.begin(),vec.end(),sortByVal);

string temp="";
for(int i=0;i<vec.size();i++)
 temp+=vec[i].first;

cout<<temp;
  return 0;
}