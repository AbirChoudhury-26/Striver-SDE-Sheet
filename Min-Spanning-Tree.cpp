// Using Prims Algorithm

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int spanningtree(int v,vector<vector<int>>adj[])
{
    
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