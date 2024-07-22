/**
Level of Nodes in Graph
Given an integer x and an undirected acyclic graph with v nodes, labeled from 0 to v-1, and e edges, return the level of node labeled as x.
Level is the minimum number of edges you must travel from the node 0 to some target.
If there doesn't exists such a node that is labeled as x, return -1.

Intuition
The intuition behind using Breadth-First Search (BFS) to find the level of a target node in a graph is based on the properties of BFS. BFS explores nodes level by level, starting from the source node. This means that the first time we encounter the target node, we have reached it via the shortest path in terms of the number of edges. Therefore, the level at which we find the target node in the BFS traversal corresponds to the shortest path length from the source node to the target node.

Approach
Initialization:
Initialize a queue that will store pairs of integers, where each pair consists of a node and its level.
Initialize a vector to keep track of visited nodes to avoid processing the same node multiple times.
Start by pushing the source node (usually node 0) with level 0 into the queue and mark it as visited.
BFS Traversal:
While the queue is not empty:
Dequeue the front element from the queue. This gives the current node and its level.
If the current node is the target node, return its level as the result.
Otherwise, for each adjacent node of the current node:
If the adjacent node has not been visited, enqueue it with the level incremented by 1 and mark it as visited.
Completion:
If the queue is exhausted and the target node has not been found, return -1 indicating that the target node is not reachable from the source node.

Time Complexity
Initialization: Initializing the queue and the visited vector takes O(V), where V is the number of vertices.
BFS Traversal:
Each node is enqueued and dequeued at most once, leading to O(V) operations.
For each node, all its adjacent nodes are explored. Summing up across all nodes, this results in O(E) operations, where E is the number of edges.
Therefore, the overall time complexity is O(V + E).

Space Complexity
Queue: In the worst case, the queue can hold all the nodes, leading to O(V) space.
Visited Vector: This requires O(V) space.
Overall, the space complexity is O(V).

Code
*/
int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int,int>>q;
	    q.push({0,0});
	    vector<bool>vis(V,false);
	    vis[0] = 1;
	    while(!q.empty())
	    {
	        int temp = q.front().first;
	        int level = q.front().second;
	        q.pop();
	        if(temp == X)
	        return level;

	        for(auto it : adj[temp])
	        {
	            if(!vis[it]){
	                q.push({it,level+1});
	                vis[it] = true;}
	        }
	    }
	    return -1;
	}
