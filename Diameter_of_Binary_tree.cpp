/*
Diameter of a Binary Tree
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

Intuition:
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root node. We need to compute the diameter of the binary tree.

Approach:
Recursive Depth Calculation: We can recursively calculate the depth of each subtree starting from the root. At each node, we calculate the depth of the left and right subtrees.
Update Maximum Diameter: While calculating the depth of each subtree, we also update the maximum diameter encountered so far. The diameter passing through the current node is given by the sum of heights of the left and right subtrees plus one (for the current node).
Recursion Termination: We terminate the recursion when we reach a leaf node, where the depth of the subtree is 0.

Time Complexity:
The time complexity of the algorithm is O(n), where n is the number of nodes in the binary tree. This is because we visit each node once during the recursive traversal to calculate the depth of each subtree and update the maximum diameter.

Space Complexity:
The space complexity of the algorithm is O(h), where h is the height of the binary tree. This is because the recursive calls occupy space on the call stack, which is proportional to the height of the tree.
In the worst-case scenario, where the tree is highly unbalanced (skewed), the space complexity can be O(n). However, in balanced trees, the space complexity is typically O(log n), where n is the number of nodes.

Code
*/
    int util(Node* root, int &maxi)
    {
        if(!root)
            return 0;
        int lh = util(root->left,maxi);
        int rh = util(root->right,maxi);
        maxi = max(lh+rh,maxi);
        return 1 + max(lh,rh);
    }
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int maxi = 0;
        util(root, maxi);
        return maxi+1;
    }
};

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
