
/*
What is Topological Sorting:

Topological sorting is a dependency problem in which completion of one task depends
upon the completion of several other tasks whose order can vary

*/

// Algorithm:

/*

Create a graph with n vertices and m-directed edges.
Initialize a stack and a visited array of size n.
For each unvisited vertex in the graph, do the following:
Call the DFS function with the vertex as the parameter.
In the DFS function, mark the vertex as visited and recursively call the DFS function for all unvisited neighbors of the vertex.
Once all the neighbors have been visited, push the vertex onto the stack.
After all, vertices have been visited, pop elements from the stack and append them to the output list until the stack is empty.
The resulting list is the topologically sorted order of the graph.

*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and topological sorting
void topologicalSortUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v])
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Push current vertex to stack which stores the result
    Stack.push(v);
}

// Function to perform Topological Sort
void topologicalSort(vector<vector<int>> &adj, int V)
{
    stack<int> Stack; // Stack to store the result
    vector<bool> visited(V, false);

    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Print contents of stack
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{

    // Number of nodes
    int V = 4;

    // Edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 1}, {3, 2}};

    // Graph represented as an adjacency list
    vector<vector<int>> adj(V);

    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, V);

    return 0;
}

// Using BFS:

#include <iostream>

#include <list>

#include <queue>

using namespace std;

// Class to represent a graph

class Graph
{

    int V; // No. of vertices

    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V); // Constructor

    void addEdge(int v, int w); // Function to add an edge to graph

    void topologicalSort(); // prints a Topological Sort of the complete graph
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

// Function to perform Topological Sort

void Graph::topologicalSort()
{

    // Create a vector to store in-degree of all vertices

    vector<int> in_degree(V, 0);

    // Traverse adjacency lists to fill in_degree of vertices

    for (int v = 0; v < V; ++v)
    {

        for (auto const &w : adj[v])

            in_degree[w]++;
    }

    // Create a queue and enqueue all vertices with in-degree 0

    queue<int> q;

    for (int i = 0; i < V; ++i)
    {

        if (in_degree[i] == 0)

            q.push(i);
    }

    // Initialize count of visited vertices

    int count = 0;

    // Create a vector to store topological order

    vector<int> top_order;

    // One by one dequeue vertices from queue and enqueue

    // adjacent vertices if in-degree of adjacent becomes 0

    while (!q.empty())
    {

        // Extract front of queue (or perform dequeue)
        // and add it to topological order

        int u = q.front();

        q.pop();

        top_order.push_back(u);

        // Iterate through all its neighbouring nodes

        // of dequeued node u and decrease their in-degree

        // by 1

        list<int>::iterator itr;

        for (itr = adj[u].begin(); itr != adj[u].end(); ++itr)

            // If in-degree becomes zero, add it to queue

            if (in_degree[*itr] == 0)

                q.push(*itr);

        count++;
    }

    // Check if there was a cycle

    if (count != V)
    {
        cout << "Graph contains cycle\n";
        return;
    }

    // Print topological order

    for (int i : top_order)

        cout << i << " ";
}

// Driver code

int main()
{

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Following is a Topological Sort of the given graph\n";
    g.topologicalSort();

    return 0;
}