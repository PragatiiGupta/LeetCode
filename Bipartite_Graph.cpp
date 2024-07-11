/**
Bipartite Graph
Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
Here’s how the approach typically works:
Coloring Strategy: You start by assigning colors to nodes during BFS traversal. Typically, you use two colors (e.g., 0 and 1). Begin from any unvisited node, assign it one color (say 0), and then assign the opposite color (1) to all its neighbors.
BFS Traversal: Use BFS to ensure all nodes are visited. During traversal, for each node, check its neighbors. If a neighbor has not been colored, assign it the opposite color of the current node and add it to the BFS queue.
Check for Conflict: While assigning colors, if you find a neighbor that has already been colored with the same color as the current node, then the graph is not bipartite.
Completion Check: If BFS completes and all nodes are colored without conflicts (i.e., no two adjacent nodes have the same color), then the graph is bipartite.

This approach is efficient with a time complexity of O(V+E), where V is the number of vertices and EE is the number of edges. It ensures that each node and edge is processed once, making it suitable for determining bipartiteness even in large graphs.

Code
*/
	bool isBipartite(int V, vector<int>adj[]){
	    queue<int>q;
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i] == -1)
	        {
	            q.push(i);
	            color[i] = 0;
	        }
	        while(!q.empty())
	        {
	            int node = q.front();
	            q.pop();
	            for(int it : adj[node])
	            {
	                if(color[it] == -1)
	                {
	                    color[it] = 1 - color[node];
	                    q.push(it);
	                }
	                else if(color[it] == color[node])
	                    return false;
	            }
	        }
	    }
	    return true;
	}
