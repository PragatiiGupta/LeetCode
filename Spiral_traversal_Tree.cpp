/*
ZigZag Tree Traversal
Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

Intuition:
The goal is to perform a zigzag traversal of a binary tree, alternating between left-to-right and right-to-left at each level.

Approach:
Breadth-First Search (BFS): We use a BFS traversal technique to traverse the tree level by level.
Queue for Level Order Traversal: We use a queue to perform level-order traversal of the tree. At each level, we process the nodes and alternate the direction of traversal based on the level's parity.
Vector to Store Nodes at Each Level: We use a vector to store the nodes at each level. For even levels (0-indexed), we add the nodes from left to right, and for odd levels, we add them from right to left.
Concatenate Levels: After processing all nodes at a level, we concatenate the nodes to the result vector to maintain the zigzag traversal order.

Time Complexity:
The time complexity of the algorithm is O(n), where n is the number of nodes in the binary tree. This is because we visit each node once during the BFS traversal.

Space Complexity:
The space complexity of the algorithm is O(n), where n is the number of nodes in the binary tree. This space is used for the queue data structure to perform BFS traversal and the result vector to store the zigzag traversal order.
Additionally, if considering the output space, the space required to store the final zigzag traversal order is also O(n), where n is the number of nodes in the binary tree.

Summary:
The algorithm efficiently performs a zigzag traversal of the binary tree by using BFS traversal and alternating the direction of traversal at each level. It has a time complexity of O(n) and a space complexity of O(n).

Code
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	queue<Node*>q;
    	q.push(root);
    	int leftToRight = 1;
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    vector<int> level;
    	    for(int i=0;i<size;i++)
    	    {
    	        Node* temp = q.front();
    	        q.pop();
    	        if(leftToRight) 
    	        level.push_back(temp->data);
    	        else if(!leftToRight)
    	        level.insert(level.begin(),temp->data);
    	        if(temp->left)
    	        q.push(temp->left);
    	        if(temp->right)
    	        q.push(temp->right);
    	    }
    	    leftToRight = !leftToRight;
    	    ans.insert(ans.end(),level.begin(),level.end());
    	}
    	return ans;
    }
};
