/*
Boundary Traversal of binary tree.
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Intuition:
To find the boundary traversal of a binary tree, we need to traverse the tree in three parts:

Traverse the left boundary (excluding leaf nodes).
Traverse all leaf nodes.
Traverse the right boundary (excluding leaf nodes), but in reverse order.

Approach:
Define a function isLeaf() to check if a given node is a leaf node.
Define three helper functions:
leftTree(): Traverse the left boundary of the tree (excluding leaf nodes) and store the nodes in a vector.
rightTree(): Traverse the right boundary of the tree (excluding leaf nodes) in reverse order and store the nodes in a vector.
leafNodes(): Traverse all leaf nodes of the tree and store them in a vector.
Initialize an empty vector ans to store the boundary traversal.
If the root is null, return an empty vector.
If the root is not a leaf node, include it in the result vector.
Call the three helper functions to construct the boundary traversal.
Return the final result vector.

Time Complexity:
The time complexity of traversing the entire tree is O(N), where N is the number of nodes in the tree.
Each traversal (left, right, and leaf nodes) takes O(N) time in the worst case.

Space Complexity:
The space complexity depends on the space used by the result vector and the recursion stack.
The result vector may store up to O(N) elements.
The recursion stack can go up to the height of the tree, which is O(log N) for a balanced binary tree and O(N) for a skewed binary tree.
Overall, the space complexity is O(N) considering the worst-case scenario.

Code
*/

bool isLeaf(Node *root)
    {
        if(root != nullptr && root->left== nullptr && root->right == nullptr)
        return true;
        else
        return false;
    }
void leftTree(Node *root, vector<int> &ans)
{
    Node *curr = root->left;
    
    while(curr){
    if(!isLeaf(curr))
        ans.push_back(curr->data);
    if(curr->left)
        curr = curr->left;
    else
        curr = curr->right;
    }
    
}
void rightTree(Node *root, vector<int> &ans)
{
    Node *curr = root->right;
    vector<int> vec;
    while(curr){
    if(!isLeaf(curr))
        vec.push_back(curr->data);
        
    if(curr->right)
        curr = curr->right;
    else
        curr = curr->left;
    }
    for(int i=vec.size()-1;i>=0;i--)
    ans.push_back(vec[i]);

}
void leafNodes(Node *root, vector<int> &ans)
{
    if(isLeaf(root)){
    ans.push_back(root->data);
    return;}
    if(root->left) leafNodes(root->left,ans);
    if(root->right) leafNodes(root->right,ans);
}
class Solution {
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(!root)
        return ans;
        if(!isLeaf(root)) 
        ans.push_back(root->data);
        leftTree(root,ans);
        leafNodes(root,ans);
        rightTree(root,ans);
        return ans;
    }
};
