/*
Intuition:
The Lowest Common Ancestor (LCA) of two nodes n1 and n2 in a binary tree is the lowest node in the tree that has both n1 and n2 as descendants. We need to find this common ancestor efficiently.

Approach:
If the current node is null, return null, indicating that the LCA is not found.
Check if the current node is either n1 or n2. If so, return the current node.
Recur for the left and right subtrees to find the LCA in them.
If both left and right subtrees return non-null nodes, it means that the current node is the LCA. Return the current node.
If only one subtree returns a non-null node, it means that the LCA is in that subtree. Return that non-null node.
If both left and right subtrees return null nodes, return null, indicating that the LCA is not found.

Time Complexity:
In the worst-case scenario, we may visit every node in the binary tree once.
Hence, the time complexity is O(n), where n is the number of nodes in the binary tree.

Space Complexity:
The space complexity is O(h), where h is the height of the binary tree.
In the worst-case scenario, the space required is equal to the height of the tree, due to the recursion stack.

Code
*/
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if (!root)
            return nullptr;

        if (root->data == n1 || root->data == n2)
            return root;

        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);

        if (left && right)
            return root;

        // Otherwise, return the non-null node from left or right subtree.
        return (left != nullptr) ? left : right;
        
    }
};
