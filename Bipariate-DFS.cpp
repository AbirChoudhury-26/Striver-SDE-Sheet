#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, int color[], vector<int> adj[])
{
    color[node] = col;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (dfs(it, !col, color, adj) == false)
                return false;
            else if (color[it] == col)
                return false;
        }
    }
    return true;
}

bool isBiparitate(int V, vector<int> adj[])
{
    int color[V] = {-1};

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
            if (dfs(i, 0, color, adj) == false)
             return false;
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
}