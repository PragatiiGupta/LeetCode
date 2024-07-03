/**
226. Invert Binary Tree
Given the root of a binary tree, invert the tree, and return its root.
Intuition
The goal of inverting a binary tree is to swap the left and right children of every node in the tree. This means that for each node, its left child becomes its right child, and its right child becomes its left child. By recursively applying this process to each node, we can invert the entire tree.

Approach
Base Case:
If the current node (root) is NULL, return NULL. This stops the recursion for leaf nodes.
Swap Children:
Swap the left and right children of the current node.
Recursive Calls:
Recursively call invertTree on the left child (which was originally the right child).
Recursively call invertTree on the right child (which was originally the left child).
Return the Root:
Finally, return the root of the tree.

Time Complexity
O(N): Each node in the tree is visited exactly once. Therefore, the time complexity is linear with respect to the number of nodes in the tree, where N is the total number of nodes.
Space Complexity
O(H): The space complexity is determined by the recursion stack. In the worst case, the depth of the recursion stack is equal to the height of the tree. For a skewed tree (like a linked list), this could be O(N). For a balanced tree, the height is O(log N).

Code 
*/
TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp;
        if(root == NULL)
        return NULL;
        temp = root -> left;
        root -> left  = root -> right;
        root -> right = temp;
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
