/**
Level of a Node in Binary Tree.
Given a Binary Tree and a target key you need to find the level of target key in the given Binary Tree.

Explanation:
Queue Initialization:
A queue is initialized to store nodes for BFS traversal.
The root node is pushed into the queue, and the initial level is set to 1.
BFS Traversal:
While the queue is not empty, the code processes each level of the tree.
For each node at the current level, it checks if the node's value matches the target.
If a match is found, the current level is returned.
Otherwise, the left and right children of the current node (if they exist) are added to the queue for processing at the next level.
Level Increment:
After processing all nodes at the current level, the level counter is incremented.
Return Statement:
If the target node is not found after processing all levels, the function returns 0.

Time and Space Complexity:
Time Complexity: O(n), where nn is the number of nodes in the tree. Each node is visited once.
Space Complexity: O(n), which accounts for the maximum number of nodes that can be stored in the queue at any given time. In the worst case (a completely balanced binary tree), 
this is proportional to the width of the tree, which is O(n) in the worst case (for a completely unbalanced tree like a linked list).

Code
*/
int getLevel(struct Node *node, int target)
    {
    	queue<struct Node*>q;
    	int level=1;
    	q.push(node);
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    for(int i=0;i<size;i++)
    	    {
    	        struct Node* temp = q.front();
    	        q.pop();
    	        if(temp->data == target)
    	            return level;
    	        else{
    	            if(temp->left)
    	                q.push(temp->left);
    	            if(temp->right)
    	                q.push(temp->right);
    	        }
    	    }
    	    level += 1;
    	}
    	return 0;
    }
