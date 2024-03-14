/*
Maximum path sum from any node

Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Intuition:
The problem asks to find the maximum path sum from any node in a binary tree. This means that we need to consider paths that start from any node, go down to its descendants (including the node itself), and sum the values along the path.

Approach:
Recursive Depth-First Traversal: We can use a recursive approach to traverse the binary tree in a depth-first manner.
Update Maximum Sum: At each node, we calculate the maximum path sum that includes the current node (by considering the sum of the left subtree, right subtree, and the current node's value). We update a global variable sum with the maximum path sum encountered so far.
Return Maximum Path Sum from Current Node: We return the maximum path sum that starts from the current node (either including only the current node or extending to its descendants).

Time Complexity:
The time complexity of the algorithm is O(n), where n is the number of nodes in the binary tree. This is because we visit each node once during the recursive traversal to calculate the maximum path sum.

Space Complexity:
The space complexity of the algorithm is O(h), where h is the height of the binary tree. This is because the recursive calls occupy space on the call stack, which is proportional to the height of the tree.
In the worst-case scenario, where the tree is highly unbalanced (skewed), the space complexity can be O(n). However, in balanced trees, the space complexity is typically O(log n), where n is the number of nodes.

Code
*/
    int utilSum(Node* root, int& sum)
    {
        if(root == NULL)
        return 0;
        int ls = max(0,utilSum(root->left,sum));
        int rs = max(0,utilSum(root->right, sum));
        sum = max(sum, ls+rs+root->data);
        return max(ls,rs)+root->data;
    }
class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
       int sum = INT_MIN;
       utilSum(root,sum);
       return sum;
    }
};
