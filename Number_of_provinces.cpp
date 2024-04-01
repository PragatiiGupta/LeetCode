/**
Number of Provinces
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.
Intuition:
The problem is asking to find the number of provinces in a given graph, where a province is defined as a group of connected nodes. This is a classic problem of finding connected components in a graph.

Approach:
Construct Adjacency List: First, construct the adjacency list representation of the graph from the given adjacency matrix. This will help in traversing the graph efficiently.
Depth-First Search (DFS): Use Depth-First Search to traverse the graph and mark visited nodes. Each time a new DFS traversal starts, it indicates the beginning of a new province. Count the number of such DFS traversals to find the total number of provinces in the graph.
Counting Provinces: Initialize a count variable to 0. For each unvisited node in the graph, perform a DFS traversal starting from that node. Increment the count each time a new DFS traversal begins. The final count will represent the number of provinces in the graph.

Time Complexity Analysis:
Constructing the adjacency list takes O(V^2) time, where V is the number of vertices in the graph.
Performing DFS traversal takes O(V + E) time, where E is the number of edges in the graph.
Since we're performing DFS on each unvisited node, the overall time complexity is O(V + E), where V is the number of vertices and E is the number of edges.
Space Complexity Analysis:
The adjacency list requires O(V + E) space to store the graph representation.
The visited array requires O(V) space.
Other variables like count, i, j, etc., require constant space.
Thus, the overall space complexity is O(V + E), where V is the number of vertices and E is the number of edges.
Code */
void dfs(vector<int>adjLst[], int node, int vis[])
{
    vis[node] = 1;
    for(auto it: adjLst[node])
    {
        if(!vis[it])
        dfs(adjLst, it, vis);
    }
}
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLst[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i!=j && adj[i][j] == 1)
                {
                adjLst[i].push_back(j);
                adjLst[j].push_back(i);
                }
            }
        }
        int vis[V] = {0};
        int cnt = 0;
        for (int i = 0; i < V; i++)
            if (!vis[i]) {
                cnt++;
                dfs(adjLst, i, vis);
            }
        return cnt;
    }
};
