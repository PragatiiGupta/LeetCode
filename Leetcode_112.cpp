/**
112. Path Sum
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

Intuition
The goal is to determine if there exists a path from the root to any leaf in a binary tree such that the sum of the values along the path equals a given target sum. The problem can be solved using a recursive approach, leveraging depth-first search (DFS). The intuition is to traverse the tree, decrementing the target sum by the value of the current node, and checking if we reach a leaf node with the remaining sum equal to the node's value.

Approach
Base Case:
If the current node is NULL, return false. This means there is no path through this node.
Leaf Node Check:
If the current node is a leaf node (both left and right children are NULL), check if the node's value equals the remaining sum. If it does, return true.
Recursive Case:
Subtract the current node's value from the target sum.
Recursively call hasPathSum on the left child with the updated sum.
Recursively call hasPathSum on the right child with the updated sum.
Return:
Return true if either the left or right subtree has a path that meets the required sum.

Time Complexity
O(N): Each node is visited exactly once, where N is the number of nodes in the tree. This is because we traverse the entire tree in the worst case.
Space Complexity
O(H): The space used by the recursion stack. H is the height of the tree. In the worst case, for a skewed tree (like a linked list), this could be O(N). For a balanced tree, it would be O(log N).

Code
*/
bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
        return 0;
        if(root->left == NULL && root->right == NULL)
        return targetSum == root->val;
        targetSum -= root->val;
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);  
    }
