#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool dfs(int node,int vis[],int pathvis[],vector<int>adj[])
{
  vis[node]=1;
  pathvis[node]=1;

   for(auto it:adj[node])
   {
     if(!vis[it])
     {
         if(dfs(it,vis,pathvis,adj)==true)
          return true;
     }
     else if(pathvis[it]) 
      return true;
   }

   pathvis[node]=0;
    return false;
}


bool isCyclicDFS(int V,vector<int>adj[])
{
    int vis[V]={0};
    int pathvis[V]={0};

     for(int i=0;i<V;i++)
     { 
        if(!vis[i])
         {
             if(dfs(i,vis,pathvis,adj)==true) 
              return true;
         }
     }

     return false;
}
 
int main()
{
   vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;

    bool ans=isCyclicDFS(V,adj);
      if(ans==true)
      cout<<"Cyclic Graph"<<endl;
    else 
     cout<<"Not a Cyclic Graph"<<endl;
      
  return 0;
}