/**
222. Count complete tree nodes.
Given the root of a complete binary tree, return the number of the nodes in the tree.
Design an algorithm that runs in less than O(n) time complexity.

Intuition
The goal is to count the number of nodes in a binary tree. This can be achieved by recursively traversing the tree and counting each node. The idea is simple: the total number of nodes is the count of nodes in the left subtree plus the count of nodes in the right subtree plus one (for the root node itself).

Approach
Base Case:
If the current node is NULL, return 0. This means there are no nodes in this subtree.
Recursive Case:
Recursively call countNodes on the left child.
Recursively call countNodes on the right child.
Add the results of the two recursive calls and add 1 (for the current node).

Time Complexity
O(N): Each node is visited exactly once, where N is the number of nodes in the tree. This is because we traverse the entire tree.
Space Complexity
O(H): The space used by the recursion stack. H is the height of the tree. In the worst case, for a skewed tree (like a linked list), this could be O(N). For a balanced tree, it would be O(log N).
Code
*/

int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
