/*
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.

Intuition:
DFS is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It starts at a selected node and explores as far as possible along each branch before backtracking.

Approach:
Implement a dfsUtil function that performs the DFS traversal recursively.
Mark the current node as visited and add it to the DFS traversal list.
Iterate over all adjacent nodes of the current node.
For each unvisited adjacent node, recursively call the dfsUtil function.

Time Complexity:
The time complexity of the DFS algorithm is O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph. This complexity arises because each vertex and edge are visited exactly once.

Space Complexity:
The space complexity of the DFS algorithm is O(V), where V is the number of vertices in the graph. This space is primarily used for maintaining the visited array, the call stack during recursion, and the resulting DFS traversal list. Since the DFS traversal list is part of the output, it contributes to the space complexity as well.
Code
*/
  private:
    void dfsUtil(int node, vector<int> adj[], int vis[], vector<int> &dfs)
    {
        vis[node] = 1;
        dfs.push_back(node);
        for(auto it: adj[node])
        {
            if(!vis[it])
            dfsUtil(it,adj,vis,dfs);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>dfs;
        int vis[V] = {0};
        vis[0] = 1;
        int start = 0;
        dfsUtil(start, adj,vis,dfs);
        return dfs;   
    }
