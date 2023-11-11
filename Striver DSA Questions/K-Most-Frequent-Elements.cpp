#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// bool comp(pair<int,int>&a,const pair<int,int>&b)
// {
//     return (a.second<b.second);
// }
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    map<int,int>mp;
    vector<pair<int,int>>p;
     for(int i=0;i<n;i++)
      {
        cin>>v[i];
        p.push_back(make_pair(v[i],++mp[v[i]]));
      }
      
      for(int i=0;i<n;i++)
       cout<<p[i].first<<" "<<p[i].second<<endl;
}