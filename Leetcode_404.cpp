/*
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Intuition
The problem requires calculating the sum of left leaves in a binary tree. Our intuition is to traverse the tree recursively and identify left leaves along the way.

Approach
We will implement a recursive approach to traverse the binary tree. At each node, we will check if it is a left leaf. If so, we will add its value to the sum. We will continue this process for the left and right subtrees until all nodes have been visited.

Complexity
Time complexity: O(n), where n is the number of nodes in the binary tree. We need to visit each node once.
Space complexity: O(h), where h is the height of the binary tree. The space complexity is determined by the recursion depth, which is equal to the height of the tree.
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        utilSum(root,sum,false);
        return sum;
    }
    void utilSum(TreeNode* root, int &sum, bool isleft)
    {
        if (root == nullptr)
        return;

        if(!root->left && !root->right && isleft){
        sum += root->val;
        return;
        }
        utilSum(root->left,sum,true);
        utilSum(root->right,sum,false);

    }
};
