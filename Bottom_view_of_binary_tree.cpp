/*
Bottom View of Binary Tree
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

Intuition:
The bottom view of a binary tree is defined as the set of nodes visible when the tree is viewed from the bottom. To find the bottom view, we need to determine the nodes that are visible at each vertical level (horizontal distance) from the root. We can use a map to store the last node encountered at each vertical level while performing a level-order traversal of the tree.

Approach:
Perform a level-order traversal of the binary tree using a queue.
For each node encountered during the traversal, keep track of its horizontal distance from the root.
Use a map to store the last node encountered at each horizontal distance.
After traversing the entire tree, extract the nodes from the map to construct the bottom view of the tree.

Time Complexity:
Traversal: We perform a level-order traversal of the binary tree, visiting each node once. The time complexity of this traversal is O(N), where N is the number of nodes in the tree.
Map Operations: Inserting and accessing elements in the map take O(log N) time on average. Since we insert and access elements for each node, the total time complexity for map operations is also O(N * log N).
Therefore, the overall time complexity is O(N * log N).

Space Complexity:
Queue: We use a queue to perform level-order traversal, which can contain at most all the nodes at the deepest level of the tree. Hence, the space complexity for the queue is O(N).
Map: The map stores the last node encountered at each horizontal distance. In the worst case, the map can contain at most one entry for each horizontal distance. Therefore, the space complexity for the map is also O(N).
Overall, the space complexity is O(N) due to the queue and map.

Code
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto it = q.front().first;
            int t = q.front().second;
            q.pop();
            mp[t] = it->data;
            if(it->left)
            q.push({it->left,t-1});
            if(it->right)
            q.push({it->right,t+1});
        }
        for(auto it:mp)
        ans.push_back(it.second);
        
        return ans;
    }
};
