/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Intuition
The intuition behind solving this problem is to recursively traverse both trees and compare their corresponding nodes at each level to determine if they are the same.

Approach
The approach involves implementing a recursive function that traverses the trees. At each level, the function compares the values of the nodes and recursively calls itself for the left and right subtrees of both trees. The function returns true if the values of the current nodes are equal and if the recursive calls for both left and right subtrees return true, indicating that the trees are the same.

Complexity
Time complexity:
In the worst case, where both trees have n nodes and are identical, the algorithm visits each node once. Therefore, the time complexity is O(n), where n is the total number of nodes in the input trees.
Space complexity:
The space complexity is also O(n) in the worst case, where n is the total number of nodes in the input trees. This is because the recursive function calls occupy space on the call stack proportional to the height of the trees, which can be at most O(n) for a skewed tree.

Code
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if (p->val != q->val) return false;

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return left && right;
    }
};
