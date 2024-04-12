/**
Print adjacency list
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

Intuition:
The goal is to construct the adjacency list representation of a graph given its number of vertices V and a list of edges edges. Each edge is represented as a pair of integers, where the first integer is the source vertex and the second integer is the destination vertex.

Approach:
Initialize Adjacency List: Initialize an empty adjacency list, where each vertex i has an associated vector containing the vertices it is adjacent to.
Iterate Through Edges: Iterate through each edge (u, v) in the edges vector.
Add Edge to Adjacency List: For each edge (u, v), add vertex v to the adjacency list of vertex u and vertex u to the adjacency list of vertex v. (For undirected graphs. If the graph is directed, only add v to the adjacency list of u.)
Return Adjacency List: Return the constructed adjacency list.
Time Complexity:
The time complexity of constructing the adjacency list depends on the number of edges in the graph.
In the worst case, each edge needs to be processed once, resulting in a time complexity of O(E), where E is the number of edges in the graph.

Space Complexity:
The space complexity is determined by the size of the adjacency list.
We need to store the adjacency list for each vertex, which requires O(V) space.
Additionally, we need space to store the input list of edges, which also requires O(E) space.
Thus, the overall space complexity is O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Code
*/

class Solution {
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>& edges) {
        vector<vector<int>> adjList(V);
        for (const auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u); 
        }
        
        return adjList;
    }
};
