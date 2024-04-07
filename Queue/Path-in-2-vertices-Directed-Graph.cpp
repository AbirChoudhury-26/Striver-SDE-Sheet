#include<iostream>
#include <list>
using namespace std;

/* Approach:
BFS Algorithm: 

The implementation below is using BFS.
Create a queue and a visited array initially filled with 0, of size V where V is a number of vertices.
Insert the starting node in the queue, i.e. push u in the queue and mark u as visited.
Run a loop until the queue is not empty.
Dequeue the front element of the queue. Iterate all its adjacent elements. If any of the adjacent elements is the destination return true. Push all the adjacent and unvisited vertices in the queue and mark them as visited.
Return false as the destination is not reached in BFS

*/


class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	bool isReachable(int s, int d); 
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(int s, int d)
{
	// Base case
	if (s == d)
	return true;

	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// it will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it visited
		// and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			// If this adjacent node is the destination node, then 
			// return true
			if (*i == d)
				return true;

			// Else, continue to do BFS
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	
	// If BFS is complete without visiting d
	return false;
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	int u = 1, v = 3;
	if(g.isReachable(u, v))
		cout<< "\n There is a path from " << u << " to " << v;
	else
		cout<< "\n There is no path from " << u << " to " << v;

	u = 3, v = 1;
	if(g.isReachable(u, v))
		cout<< "\n There is a path from " << u << " to " << v;
	else
		cout<< "\n There is no path from " << u << " to " << v;

	return 0;
}
