/**
Remove Nth Node From End of List

Intuition
The problem asks to remove the nth node from the end of a singly-linked list and return the head of the modified list. To solve this problem, we can use the two-pointer technique. We can maintain two pointers, one slow and one fast, initially pointing to the head of the list. We move the fast pointer n steps ahead. Then, we move both pointers simultaneously until the fast pointer reaches the end of the list. At this point, the slow pointer will be pointing to the node just before the node to be deleted. We can then adjust the pointers to remove the nth node from the end.

Approach
Initialize two pointers, slow and fast, pointing to the head of the list.
Move the fast pointer n steps ahead.
Iterate through the list while moving both pointers simultaneously until the fast pointer reaches the end of the list.
At this point, the slow pointer will be pointing to the node just before the node to be deleted.
Adjust the pointers to remove the nth node from the end.
Return the head of the modified list.

Complexity
Time complexity: O(n)O(n), where n is the number of nodes in the linked list. We traverse the list once.
Space complexity: O(1)O(1), we use constant extra space.

Code
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         auto slow = head;
    auto fast = head;
    while (n--)
      fast = fast->next;
    if (!fast)
      return head->next;
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
    }
};
