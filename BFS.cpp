#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

vector<int>bfsGraph(int V,vector<int>adj[])
{
 int vis[V]={0};

 vis[0]=1;
  queue<int>q;
   q.push(0);

    vector<int>ans;

     while(!q.empty())
     {
         int node=q.front();
         q.pop();

         ans.push_back(node);
          for(auto it:adj[node])
          {
             if(!vis[it])
              {
                vis[it]=1;
                q.push(it);
              }
          }
     }

     return ans;
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
   

   vector<int>ans=bfsGraph(5,adj);

     for(auto it:ans)
      cout<<it<<" ";
      
  return 0;
}