#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

bool isCyclicBFS(int V,vector<int>adj[])
{
   // Perfrom top sort & check if size is equal to No . of elements, then it is DAG else it must be a Cylic 

    int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

        int cnt = 0;

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (cnt == V) return false;
		return true;

}

int main()
{
  vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
	int V = 6;

    bool ans= isCyclicBFS(6,adj);
     if(ans==true)
      cout<<"Cyclic Graph"<<endl;
    else 
     cout<<"Not a Cyclic Graph"<<endl;
  return 0;
}