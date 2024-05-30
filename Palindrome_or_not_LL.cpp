/**
Check if Linked List is Palindrome.
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Intuition
To determine if a singly linked list is a palindrome, we need to compare its first half with its second half in reverse order. By reversing the second half of the list and then comparing it with the first half, we can check for a palindrome in an efficient manner without using extra space for another data structure like a vector.

Approach
Finding the Middle of the List:
Use two pointers, slow and fast. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end, the slow pointer will be at the middle of the list.
Reversing the Second Half:
Starting from the middle, reverse the second half of the linked list.
Comparing Both Halves:
Compare the nodes of the first half with the nodes of the reversed second half.
If all corresponding nodes match, the list is a palindrome.
To maintain the original structure of the list, you might want to reverse the second half again and reattach it. This step is optional and depends on whether the original list structure needs to be preserved.

Time Complexity
O(n): The algorithm traverses the list multiple times:
Once to find the middle of the list.
Once to reverse the second half of the list.
Once to compare the two halves.
Thus, the overall time complexity is linear, i.e., O(n).
Space Complexity
O(1): The algorithm uses a constant amount of extra space for pointer manipulation (i.e., slow, fast, prev, next, curr pointers). No additional data structures are used that grow with the size of the input list.
Code
*/
Node* reverseList(Node* head) {
    Node *prev = NULL, *next = NULL, *curr = head;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node *head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head, *fast = head;

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    Node *secondHalf = reverseList(slow);

    // Compare the first half and the reversed second half
    Node *firstHalf = head;
    Node *tempSecondHalf = secondHalf;
    while (tempSecondHalf != NULL) {
        if (firstHalf->data != tempSecondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        tempSecondHalf = tempSecondHalf->next;
    }

    // Optional: Restore the original list structure
    // reverseList(secondHalf);

    return true;
}
