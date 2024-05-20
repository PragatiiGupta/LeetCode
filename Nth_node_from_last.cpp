/**
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.
Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end is 8.  

Intuition
The problem is to find the nth node from the end of a singly linked list. A straightforward approach would involve two passes through the list: one to count the total number of nodes and another to find the nth node from the end. However, we can optimize this to a single pass using two pointers.

Approach
The optimized approach uses two pointers, first and second. The idea is to move the first pointer n steps ahead initially. Then, both pointers are moved one step at a time until first reaches the end of the list. At this point, second will be pointing to the nth node from the end.

Time Complexity
O(n): The algorithm traverses the list at most twice (once to move first n steps ahead and once to move both pointers until first reaches the end).
Space Complexity
O(1): Only a constant amount of extra space is used, regardless of the size of the input list, for the two pointers first and second.

Explanation
Initialization: We start by pointing both first and second to the head of the list.
Advancing the First Pointer: By moving the first pointer n steps ahead, we create a gap of n nodes between first and second. If n is larger than the length of the list, we return -1 because the nth node from the end doesn't exist.
Moving Both Pointers: By moving both pointers one step at a time until first reaches the end, we ensure that second is n nodes behind first. Thus, when first reaches the end, second is at the desired position.
Return Result: Finally, we return the data of the node that second is pointing to, which is the nth node from the end.

Code*/
class Solution {
public:
    int getNthFromLast(Node *head, int n) {
        Node *first = head, *second = head;
        // Move the first pointer n steps ahead
        while (n--) {
            if (first == NULL)
                return -1; // If n is larger than the length of the list
            first = first->next;
        }
        // Move both pointers until the first pointer reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        return second->data;
    }
};
