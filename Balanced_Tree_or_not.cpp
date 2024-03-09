/*
Check for Balanced Tree
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

Intuition:
A binary tree is considered balanced if the heights of its left and right subtrees differ by at most 1, and each subtree is also balanced. We can determine the balance of each subtree recursively and check if the overall tree is balanced.

Approach:
Recursive Depth Calculation: We can recursively calculate the depth of each subtree starting from the root. At each node, we calculate the depth of the left and right subtrees.
Check Balance: After calculating the depth of each subtree, we compare the heights of the left and right subtrees at each node. If the difference in heights is greater than 1, the tree is unbalanced.
Recursion Termination: We terminate the recursion when we reach a leaf node, where the depth of the subtree is 0.

Time Complexity:
The time complexity of the algorithm is O(n), where n is the number of nodes in the binary tree. This is because we visit each node once during the recursive traversal to calculate the depth of each subtree.

Space Complexity:
The space complexity of the algorithm is O(h), where h is the height of the binary tree. This is because the recursive calls occupy space on the call stack, which is proportional to the height of the tree.
In the worst-case scenario, where the tree is highly unbalanced (skewed), the space complexity can be O(n). However, in balanced trees, the space complexity is typically O(log n), where n is the number of nodes.
Code

*/

    int util(Node *root)
    {
        if(!root)
        return 0;
        int left = util(root->left);
        int right = util(root->right);
        
        if(left == -1 || right == -1)
        return -1;
        
        if(abs(right-left) > 1)
        return -1;
        
        return max(left,right)+1;
    }
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return util(root) != -1;
        
    }
};
