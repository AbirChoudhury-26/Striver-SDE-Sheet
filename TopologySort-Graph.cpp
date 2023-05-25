#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
vector<int>topological(int n,vector<int>adj[])
{ 
queue<int>q;
vector<int>indegree(n,0);

 for(int i=0;i<n;i++)
  {
    for(auto it:adj[i])
     indegree[it]++;
  }

  for(int i=0;i<n;i++)
   {
     if(indegree[i]==0)
      q.push(i);
   }

 vector<int>topo;
   while(!q.empty())
   {
     int node=q.front();
     q.pop();
     topo.push_back(node);
    for(auto it:adj[node])
    {
       indegree[it]--;
        if(indegree[it]==0)
         q.push(it);
    }
 
   }

   return topo;
}
int main()
{
  
  vector<int> adj[6];

  // Created Adjacency list- Directed Graph
    	adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

 vector<int>ans=topological(6,adj);
   for(auto it:ans)
    cout<<it<<" ";

    
  return 0;
}