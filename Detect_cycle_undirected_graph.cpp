/*
Detect cycle in an undirected graph
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Intuition:
The intuition behind this algorithm is to perform a breadth-first search (BFS) traversal of the graph and check for the presence of a back edge while traversing. A back edge from a node u to one of its ancestors in the BFS tree indicates the presence of a cycle in the graph.

Approach:
Breadth-First Search (BFS): We start BFS traversal from each unvisited node in the graph.
Queue: We maintain a queue to keep track of nodes to be visited next.
Visited Array: We maintain a visited array to mark nodes that have been visited during the BFS traversal.
Parent Array: We keep track of the parent node of each node to identify back edges.

Time Complexity:
BFS Traversal: In the worst-case scenario, we may visit each node and edge once, resulting in a time complexity of O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Detecting Cycle: For each node, we perform BFS traversal once. Therefore, the overall time complexity for detecting cycles in the entire graph is also O(V + E).

Space Complexity:
Visited Array: We use a visited array of size V to keep track of visited nodes, resulting in O(V) space complexity.
Queue: We use a queue to store nodes during BFS traversal. In the worst case, the queue may contain all the vertices of the graph, resulting in O(V) space complexity.
Parent Array: We use a parent array to keep track of parent nodes, which also requires O(V) space.
Total Space Complexity: O(V) + O(V) + O(V) ≈ O(V), where V is the number of vertices in the graph.
Overall, the cycle detection algorithm using BFS in an undirected graph has a time complexity of O(V + E) and a space complexity of O(V).

Code */
  
private:
    bool detectCycle(int src, int V, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    q.push({it,node});
                    vis[it] = 1;
                }
                else if( parent != it)
                {
                    return 1;
                }
            }
        }
        return 0; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detectCycle(i,V,adj,vis))
                return true;
            }
        }
        return false;
    }
