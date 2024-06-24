/**
101. Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Intuition
A tree is symmetric if the left subtree is a mirror image of the right subtree. This means that for every node in the left subtree, there should be a corresponding node in the right subtree with the same value and vice versa.

Approach
Base Case:
If both nodes being compared are NULL, return true.
If only one of the nodes is NULL, return false.
If the values of the two nodes are not equal, return false.
Recursive Case:
Recursively check if the left child of the left subtree is a mirror of the right child of the right subtree and if the right child of the left subtree is a mirror of the left child of the right subtree.

Time and Space Complexity
Time Complexity: O(N), where N is the number of nodes in the tree. Each node is visited exactly once.
Space Complexity: O(H), where H is the height of the tree. This accounts for the recursion stack. In the worst case (a completely unbalanced tree), the space complexity is O(N). In the best case (a completely balanced tree), the space complexity is O(log N).

Code
*/
bool isMirror(TreeNode* lefty, TreeNode* righty)
{
    if(lefty == NULL && righty == NULL)
    return true;
    if(lefty == NULL || righty == NULL)
    return false;
    if(lefty->val != righty->val)
    return false;
    return isMirror(lefty->left,righty->right)&&isMirror(lefty->right,righty->left);

}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        return true;
        return isMirror(root->left, root->right);
    }
};
