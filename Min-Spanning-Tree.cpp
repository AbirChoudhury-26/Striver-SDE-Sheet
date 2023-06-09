// Using Prims Algorithm

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int spanningtree(int V,vector<vector<int>>adj[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // Priority based on Small Values & less weight;

    vector<int>vis(V,0);

   // {wt,node}
pq.push({0,0});

int sum=0;  // Sum with total  Minimum weight values

 while(!pq.empty())
 {
  auto it=pq.top();
  pq.pop();

   int node=it.second;
   int weight=it.first;

    if(vis[node]==1)  // To check if node is alreday visisted or not
     continue;

    vis[node]=1;

     sum+=weight;
      
      for(auto it:adj[node])
      {
        int adjnode=it[0];
        int edw=it[1];
         if(!vis[adjnode])
          pq.push({edw,adjnode});
      }
 }

return sum;

}
int main()
{

int V=5;
vector<vector<int>>edges={{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

vector<vector<int>>adj[V];

for(auto it:edges)
{
     vector<int>temp(2);
     temp[0]=it[1];
     temp[1]=it[2];
     adj[it[0]].push_back(temp);

     temp[0]=it[0];
     temp[1]=it[2];

     adj[it[1]].push_back(temp);
}


int sum=spanningtree(V,adj);
cout<<sum<<endl;
  return 0;
}