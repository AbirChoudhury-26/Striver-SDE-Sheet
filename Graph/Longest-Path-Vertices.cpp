/* Method-1 : Using DFS

We create undirected graph for given city map and do DFS from every city to find maximum length of cable. 
While traversing, we look for total cable length to reach the current city and if it’s adjacent city is not visited then call DFS for it 
But if all adjacent cities are visited for current node, then update the value of max_length if previous value of max_length is less than current value of total cable length. 

*/


#include<bits/stdc++.h>
using namespace std;

void DFS(vector< pair<int,int> > graph[], int src,
		int prev_len, int *max_len,
		vector <bool> &visited)
{
	// Mark the src node visited
	visited[src] = 1;

	// curr_len is for length of cable from src
	// city to its adjacent city
	int curr_len = 0;

	// Adjacent is pair type which stores
	// destination city and cable length
	pair < int, int > adjacent;

	// Traverse all adjacent
	for (int i=0; i<graph[src].size(); i++)
	{
		// Adjacent element
		adjacent = graph[src][i];

		// If node or city is not visited
		if (!visited[adjacent.first])
		{
			// Total length of cable from src city
			// to its adjacent
			curr_len = prev_len + adjacent.second;

			// Call DFS for adjacent city
			DFS(graph, adjacent.first, curr_len,
				max_len, visited);
		}

		// If total cable length till now greater than
		// previous length then update it
		if ((*max_len) < curr_len)
			*max_len = curr_len;

		// make curr_len = 0 for next adjacent
		curr_len = 0;
	}
}

// n is number of cities or nodes in graph
// cable_lines is total cable_lines among the cities
// or edges in graph
int longestCable(vector<pair<int,int> > graph[],int n)
{
	// maximum length of cable among the connected
	// cities
	int max_len = INT_MIN;

	// call DFS for each city to find maximum
	// length of cable
	for (int i=1; i<=n; i++)
	{
		// initialize visited array with 0
		vector< bool > visited(n+1, false);

		// Call DFS for src vertex i
		DFS(graph, i, 0, &max_len, visited);
	}

	return max_len;
}

// driver program to test the input
int main()
{
	// n is number of cities
	int n = 6;

	vector< pair<int,int> > graph[n+1];

	// create undirected graph
	// first edge
	graph[1].push_back(make_pair(2, 3));
	graph[2].push_back(make_pair(1, 3));

	// second edge
	graph[2].push_back(make_pair(3, 4));
	graph[3].push_back(make_pair(2, 4));

	// third edge
	graph[2].push_back(make_pair(6, 2));
	graph[6].push_back(make_pair(2, 2));

	// fourth edge
	graph[4].push_back(make_pair(6, 6));
	graph[6].push_back(make_pair(4, 6));

	// fifth edge
	graph[5].push_back(make_pair(6, 5));
	graph[6].push_back(make_pair(5, 5));

	cout << "Maximum length of cable = "
		<< longestCable(graph, n);

	return 0;
}

// Method 2 (Efficient : Works only if Graph is Directed):

/* 
We can solve above problem in O(V+E) time if the given graph is directed instead of undirected graph. 
Below are steps.

Create a distance array dist[] and initialize all entries of it as minus infinite 
Order all vertices in topological order. 
Do following for every vertex u in topological order. 
Do following for every adjacent vertex v of u 
……if (dist[v] < dist[u] + weight(u, v)) 
……..dist[v] = dist[u] + weight(u, v) 
Return maximum value from dist[] 

*/