/**
Check if all nodes of Undirected Graph can be visited from given Node.
Given an undirected graph consisting of N nodes labeled from 0 to N – 1, which are represented by a 2D array arr[][], where arr[i] represents all the nodes that are connected to the ith node, the task is to find whether we can visit all the nodes from node X.

Explanation:
Initialization:
The queue q is initialized and the start node X is pushed into it.
A vis vector is initialized to keep track of visited nodes, with all values initially set to false.
BFS Traversal:
The queue is processed until it is empty.
For each node processed, all its adjacent nodes are checked. If an adjacent node has not been visited, it is marked as visited and pushed into the queue.
Check for Connectivity:
After BFS traversal, the vis vector is checked to see if all nodes have been visited.
If any node is found to be unvisited, the function returns false.
If all nodes are visited, the function returns true.

Complexity:
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
Space Complexity: O(V) for the vis vector and the queue used in BFS.

Code 
*/
bool traverseNode(vector<int>adj[], int V, int X)
{
    queue<int>q;
    q.push(X);
    vector<bool>vis(V,false);
    vis[X] = true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        return false;
    }
    return true;
}
