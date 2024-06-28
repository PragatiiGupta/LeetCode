/**
104. Maximum depth of a Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Intuition
The intuition behind finding the maximum depth (or height) of a binary tree using a recursive approach is based on the idea that the depth of a node is equal to the greater depth of its two subtrees plus one. This is because the depth of a tree is the longest path from the root to a leaf node. By recursively calculating the depth of the left and right subtrees and taking the maximum of these two values, we can determine the depth of the entire tree.

Approach
Base Case: If the current node is NULL, the depth is 0 because there are no nodes in the tree.
Recursive Case:
Recursively calculate the depth of the left subtree.
Recursively calculate the depth of the right subtree.
The depth of the current node is the maximum of the depths of the left and right subtrees plus one.
Return: The depth of the tree is returned from the root node.
Start from the root node.
If the root is NULL, return 0.
Recursively call the function on the left child to get the left subtree depth.
Recursively call the function on the right child to get the right subtree depth.
The depth of the current node is 1 + max(left subtree depth, right subtree depth).
Return the depth of the current node.

Time Complexity
O(N): Each node is visited exactly once, where N is the number of nodes in the tree.
Space Complexity
O(H): In the worst case, the height of the tree determines the space used by the recursion stack. In the worst case, for a skewed tree, this could be O(N). For a balanced tree, it would be O(log N).

Code
*/
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;
        int lHeight = maxDepth(root->left);
        int rHeight = maxDepth(root->right);
        return max(lHeight, rHeight)+1;
    }
