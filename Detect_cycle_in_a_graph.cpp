/*
Detect cycle in a directed graph

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Intuition:
The problem is to detect cycles in a directed graph. A cycle exists in a graph if there is a path that starts and ends at the same vertex, traversing through different vertices in between.

Approach:
Depth-First Search (DFS): We can use a depth-first search algorithm to traverse the graph. During the traversal, we maintain two arrays:
vis[]: To keep track of visited vertices.
state[]: To keep track of the state of each vertex during traversal. Here, state[i] = 1 indicates that the vertex i is part of the current DFS traversal path.
We start DFS traversal from each unvisited vertex. During traversal:
We mark the current vertex as visited and part of the current DFS path.
For each adjacent vertex of the current vertex:
If the adjacent vertex is not visited, we recursively call DFS on it.
If the adjacent vertex is already visited and is part of the current DFS path, then a cycle exists.
After completing the DFS traversal, if we find any cycle, we return true; otherwise, we return false.

Time Complexity:
The time complexity of the DFS algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph.
In the worst case, each vertex and edge will be visited once during DFS traversal.

Space Complexity:
The space complexity is O(V), where V is the number of vertices in the graph.
Additional space is required for the vis[] and state[] arrays to keep track of visited vertices and vertices in the current DFS path.

Code
*/

    bool dfs(int node, int vis[], int state[], vector<int> adj[])
    {
        vis[node] = 1;
        state[node] = 1;
        for(auto it: adj[node]){
        if(!vis[it] && dfs(it,vis,state,adj))
            return true;
        else if(state[it])
            return true;
        }
        state[node] = 0;
        return false;
            
    }
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int state[V] = {0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && dfs(i,vis,state,adj))
                return true;
        }
        return false;
    }
};
