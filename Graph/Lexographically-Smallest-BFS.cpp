#include <bits/stdc++.h>
using namespace std;

// Function to print the smallest lexicographically
// BFS path starting from 1
void printLexoSmall(vector<int> adj[], int n)
{
	// Visited array
	bool vis[n + 1];
	memset(vis, 0, sizeof vis);

	// Minimum Heap
	priority_queue<int, vector<int>, greater<int> > Q;

	// First one visited
	vis[1] = true;
	Q.push(1);

	// Iterate till all nodes are visited
	while (!Q.empty()) {

		// Get the top element
		int now = Q.top();

		// Pop the element
		Q.pop();

		// Print the current node
		cout << now << " ";

		// Find adjacent nodes
		for (auto p : adj[now]) {

			// If not visited
			if (!vis[p]) {

				// Push
				Q.push(p);

				// Mark as visited
				vis[p] = true;
			}
		}
	}
}

// Function to insert edges in the graph
void insertEdges(int u, int v, vector<int> adj[])
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Driver Code
int main()
{
	int n = 5, m = 5;
	vector<int> adj[n + 1];

	// Insert edges
	insertEdges(1, 4, adj);
	insertEdges(3, 4, adj);
	insertEdges(5, 4, adj);
	insertEdges(3, 2, adj);
	insertEdges(1, 5, adj);

	// Function call
	printLexoSmall(adj, n);

	return 0;
}
