#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 bool detectCycle(vector<int>adj[],int vis[],int start)
 {
  vis[start]=1;

   queue<pair<int,int>>q;
   q.push({start,-1});

    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;

         q.pop();
          for(auto it:adj[node])
          {
             if(!vis[it])
              {
                vis[it]=1;
                q.push({it,node});
              }
              else if(parent!=it)   // Point where another path has reached the same pount where this node has reached.
               return true ;        // Therefore , Cyclic Loop Condition is formed
          }
    }
   return false;

 }

 bool isCycle(int V,vector<int>adj[])
 {
     int vis[V]={0};

      for(int i=0;i<V;i++)
      {
        if(detectCycle(adj,vis,i))
         return true;
      }

      return false;

 }
int main()
{
  vector<int>adj[6] = {{1,2},{2,3},{4,5},{5,6},{6,4},{7,8}};
   bool ans=isCycle(9,adj);
     if(ans==true)
      cout<<"Cyclic Loop is formed"<<endl;
    else
     cout<<"Not a Cycle"<<endl;
  return 0;
}