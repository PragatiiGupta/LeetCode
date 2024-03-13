/*
Check if all leaves are at same level
Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

Intuition:
The problem requires determining whether a binary tree is complete or not. A binary tree is complete if all levels are completely filled except possibly for the last level, which should be filled from left to right. We can perform a level-order traversal (BFS) and keep track of the level at which the first leaf node is encountered. If any node appears after encountering a leaf node, the tree is not complete.

Approach:
Implement a function to check if a given node is a leaf node (has no left and right children).
Perform a level-order traversal (BFS) of the binary tree.
Keep track of the level at which the first leaf node is encountered. If any node appears after encountering a leaf node, the tree is not complete.
If the last level is reached and no nodes appear after encountering a leaf node, the tree is complete.

Time Complexity:
The time complexity of the level-order traversal is O(n), where n is the number of nodes in the binary tree.
Each node is processed once, and the traversal stops as soon as a leaf node is encountered.
Therefore, the overall time complexity is O(n).

Space Complexity:
The space complexity is O(w), where w is the maximum width of the binary tree (the maximum number of nodes at any level).
In the worst case, the queue used for level-order traversal may contain all nodes at the last level, resulting in O(n) space complexity.
In the best case (a complete binary tree), the width of the tree is smaller, resulting in lower space complexity.
Additionally, space is required for other variables such as ans, level, and flag, but they occupy constant space and do not contribute significantly to the overall space complexity.
Code
*/
    bool isLeaf(Node *curr){
        if(!curr->left && !curr->right) return 1;
        return 0;
    }
    bool check(Node *root)
    {
        //Your code here
        queue<Node *> q;
        q.push(root);
        int ans, level = 0;
        bool flag = 0;
        if(isLeaf(root)) return 1;
        while(!q.empty()){
            level++;
            int size = q.size();
            for(int i = 0;i<size;i++){
                Node *temp = q.front();
                q.pop();
                
                if(!flag && isLeaf(temp)){
                    ans = level;
                    flag = 1;
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        if(ans == level) return 1;
        return 0;
    }
};
