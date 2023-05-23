#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

bool dfs(int node,int vis[],vector<int>adj[],int parent)
{
 vis[node]=1;

  for(auto it:adj[node])
  {
     if(!vis[it])
     {
         if(dfs(it,vis,adj,node)==true)
          return true;
     }
     else if(it!=parent)
      return true;
  }


  return false;

}


bool isCycle(int V,vector<int>adj[])
{
     int vis[V]={0};
      for(int i=0;i<V;i++) 
       if(!vis[i])
       {
         if(dfs(i,vis,adj,-1)==true)
          return true;
       }
       return false;

}

int main()
{
  vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
bool ans=isCycle(4,adj);

if (ans)
        cout << "1\n";
    else
        cout << "0\n";

  return 0;
}