#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>maxSumCombination(vector<int> &a,vector<int> &b, int n, int k)
{
  sort(a.begin(),a.end(),greater<int>());
  sort(b.begin(),b.end(),greater<int>());

   priority_queue<pair<int,pair<int,int>>>q;
    set<pair<int,int>>s;
     vector<int>ans;

     q.push({a[0]+b[0],{0,0}});
     s.insert({0,0});

      for(int c=0;c<k;c++)
      {
        pair<int,pair<int,int>>p=q.top();
        q.pop();
         ans.push_back(p.first);

        int i=p.second.first;
        int j=p.second.second;

          if(s.find({i+1,j})==s.end())
          {
            q.push({a[i+1]+b[j],{i+1,j}});
            s.insert({i+1,j});
          }

           if(s.find({i,j+1})==s.end())
          {
            q.push({a[i]+b[j+1],{i,j+1}});
            s.insert({i,j+1});
          }
      }
      return ans;

}

 int main()
 {
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
     for(int i=0;i<n;i++)
      cin>>a[i];
    for(int j=0;j<n;j++)
     cin>>b[j];

     vector<int>ans=maxSumCombination(a,b,n,k);
     for(int i=0;i<k;i++)
      cout<<ans[i]<<" ";
 }