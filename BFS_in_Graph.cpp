/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.

Intuition:
The code aims to perform a breadth-first search (BFS) traversal of a graph represented using an adjacency list.

Approach:
Initialize an empty vector bfs to store the BFS traversal result.
Create a queue q and push the starting vertex (0) into it.
Initialize a boolean array vis of size V (number of vertices) to mark visited vertices. Mark the starting vertex as visited.
While the queue is not empty:
Pop a vertex node from the front of the queue.
Push node into the bfs vector to record its traversal order.
Iterate over all adjacent vertices of node:
If an adjacent vertex it is not visited:
Mark it as visited.
Push it into the queue.
Return the bfs vector containing the BFS traversal result.

Complexity:
Time complexity: O(V + E), where VV is the number of vertices and EE is the number of edges. In the worst case, each vertex and edge is visited once during the BFS traversal.
Space complexity: O(V) for the bfs vector and O(V) for the vis array, resulting in a total space complexity of O(V) due to the storage required for the BFS traversal. Additionally, the space complexity of the queue is O(V) in the worst case when all vertices are in the queue at once.

Code
*/
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        queue<int> q;
        q.push(0);
        int vis[V] = {0};
        vis[0] = 1;
        while(!q.size())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                vis[it] = 1;
                q.push(it);
                }
            }
        }
        return bfs;   
    }
