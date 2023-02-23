#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>start(n),end(n);
    vector<pair<int,int>>meeting;
     for(int i=0;i<n;i++)
      cin>>start[i];
     for(int i=0;i<n;i++)
      cin>>end[i];
    
    for(int i=0;i<n;i++)
        meeting.push_back({end[i],start[i]});

    sort(meeting.begin(),meeting.end());
    int count=1,prev=meeting[0].first;
     vector<int>res;

     res.push_back(1);

      for(int i=1;i<n;i++)
      {
         if(prev<meeting[i].second)
         {
          count++;
          prev=meeting[i].first;
          res.push_back(i+1);
         }
      }
       cout<<count<<endl;
        for(auto it:res)
         cout<<it<<" ";


}