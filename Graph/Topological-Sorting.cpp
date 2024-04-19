
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
void topologicalSortUtil(int v, vector<vector<int> >& adj,vector<bool>& visited,stack<int>& Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Push current vertex to stack which stores the result
    Stack.push(v);
}

// Function to perform Topological Sort
void topologicalSort(vector<vector<int> >& adj, int V)
{
    stack<int> Stack; // Stack to store the result
    vector<bool> visited(V, false);

    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Print contents of stack
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{

    // Number of nodes
    int V = 4;

    // Edges
    vector<vector<int> > edges
        = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };

    // Graph represented as an adjacency list
    vector<vector<int> > adj(V);

    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, V);

    return 0;
}
