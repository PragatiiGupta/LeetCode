/*
Level order traversal

Intuition:
Level-order traversal is a method to visit all nodes of a binary tree level by level, from left to right. The traversal starts at the root node and visits nodes at each level, one level at a time, before moving on to the next level. It is also known as breadth-first traversal.

Approach:
Using Queue: We can use a queue data structure to perform level-order traversal. We start by pushing the root node into the queue.
Iteration: While the queue is not empty, we repeatedly dequeue a node from the front of the queue, visit it, and enqueue its children (if any).
Recording Nodes: As we dequeue each node, we record its value in a vector.
Continue Until Queue is Empty: We continue this process until the queue becomes empty, ensuring that we visit all nodes level by level.

Time Complexity:
In the worst-case scenario, where the binary tree is completely unbalanced (skewed), the time complexity of level-order traversal is O(n), where n is the number of nodes in the binary tree. This is because we need to visit each node once.
Since we visit each node once and perform constant-time operations (enqueueing and dequeueing from the queue), the time complexity remains O(n).

Space Complexity:
The space complexity of the level-order traversal algorithm is O(w), where w is the maximum width of the binary tree (i.e., the maximum number of nodes at any level).
In the worst-case scenario, the queue will store all nodes at the last level of the binary tree. Hence, the maximum space required is proportional to the maximum width of the tree.
In a balanced binary tree, the maximum width is typically O(n/2) or O(n), where n is the number of nodes.
In the worst case, where the binary tree is a complete binary tree, the maximum width is reached, and the space complexity is O(n).
Level order traversal
Given a root of a binary tree with n nodes, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Code
*/

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      vector<int> ans;
      queue<Node*> q;
      q.push(root);
      if(root == NULL)
      return ans;
      while(!q.empty())
      {
          int size = q.size();
          for(int i=0;i<size;i++)
          {
            Node* temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
          }
          
      }
      return ans;
    }
};
