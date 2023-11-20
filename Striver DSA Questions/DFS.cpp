#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void dfs(int node,vector<int>adj[],int vis[],vector<int>&ls)
{
  vis[node]=1;

   ls.push_back(node);

    for(auto it:adj[node])
    {
        if(!vis[it])
         dfs(it,adj,vis,ls);
    }
}

vector<int>dfsGraph(int V,vector<int>adj[])
{
    int vis[V]={0};
    int start=0;

    vector<int>ls;

     dfs(start,adj,vis,ls);

      return ls;
}

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
  vector<int>adj[6];
   addEdge(adj,0,1);
   addEdge(adj,1,2);
   addEdge(adj,1,3);
   addEdge(adj,0,4);
   

   vector<int>ans=dfsGraph(5,adj);

     for(auto it:ans)
      cout<<it<<" ";
      
      
  return 0;
}