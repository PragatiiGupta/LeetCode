/**
Reverse a linked list
Given a linked list of N nodes. The task is to reverse this list.
Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.

Intuition
To reverse a singly linked list, we need to reverse the direction of its links. This can be done iteratively by using three pointers: prev, current, and next. The current pointer traverses the list, next keeps track of the next node, and prev keeps track of the reversed part of the list.

Approach
Initialize three pointers: prev to NULL, current to head, and next to NULL.
Traverse the list:
Store the next node of current in next.
Reverse the link by making the next of current point to prev.
Move prev to current and current to next.
After the loop, prev will point to the new head of the reversed list.
Update the head to prev.

Time Complexity
O(n): The algorithm traverses the list once, where n is the number of nodes.

Space Complexity
O(1): Only a constant amount of extra space is used for the three pointers.

Code
*/
class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        Node *prev = NULL, *next = NULL, *curr = head;
        while (curr != NULL)
        {
            next = curr->next;    // Store the next node
            curr->next = prev;    // Reverse the current node's pointer
            prev = curr;          // Move prev to the current node
            curr = next;          // Move to the next node
        }
        head = prev;              // Update the head to the new front
        return head;
    }
};
