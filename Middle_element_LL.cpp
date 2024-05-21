/**
Finding middle element in a linked list
Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.

Intuition
To find the middle of a singly linked list, we can use the "tortoise and hare" approach. This approach involves two pointers: one that moves one step at a time (the tortoise) and another that moves two steps at a time (the hare). When the hare reaches the end of the list, the tortoise will be at the middle.

Approach
Initialize two pointers, first and second, both pointing to the head of the list.
Move the second pointer two steps at a time and the first pointer one step at a time.
When the second pointer reaches the end (or the node before the end if the list has an even number of nodes), the first pointer will be at the middle.

Explanation
Initialization: Both first and second pointers start at the head of the list.
Traversal:
The first pointer moves one step at a time.
The second pointer moves two steps at a time.
Loop Condition: The loop continues as long as second and second->next are not NULL. This ensures that we correctly handle lists with both even and odd lengths.
Middle Element: When the second pointer reaches the end (or the node before the end), the first pointer will be at the middle of the list.

Time Complexity
O(n): The algorithm traverses the list once, making it linear in the number of nodes n.

Space Complexity
O(1): Only a constant amount of extra space is used for the two pointers.
Edge Cases
If the list is empty, the function returns -1.
If the list has only one element, the function returns the data of the head.
If the list has two elements, the function correctly identifies the second element as the middle for even-length lists.
This approach ensures that we find the middle element efficiently with a single pass through the list and minimal space usage.
Code
*/
int getMiddle(Node *head) {
    if (head == NULL) {
        return -1;  // List is empty
    }
    Node *first = head, *second = head;
    while (second != NULL && second->next != NULL) {
        first = first->next;
        second = second->next->next;
    }
    return first->data;  // The first pointer is now at the middle
}
