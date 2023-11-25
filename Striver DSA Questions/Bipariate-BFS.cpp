#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isBiparitate(int V, vector<int> adj[])
{
    queue<int>q;
    q.push(0);   /// 0 Means we have pushed  an Initial Colour 0 
    int color[V]={-1};
       while(!q.empty())
       {
         int node=q.front();
          q.pop();
            for(auto it:adj[node])
            {
                // if adjacent node are not coloured
                if(color[it]==-1)
                 {
                    color[it]=!color[node];
                 }
                 else if(color[it]==color[node])  // if adjacent color of node is same or not
                 {
                    return false;
                 }
                
            }
       } 

        return true;

}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main()
{
  vector<int> adj[4];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    bool ans = isBiparitate(4, adj);
    if(ans==false)
     cout<<"Not a BiParitate"<<endl;
    else
     cout<<"It's Biparitate"<<endl;
    return 0;
  return 0;
}