/**
Remove loop in Linked List.
Given a linked list of N nodes such that it may contain a loop.
Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

Intuition:
The problem of detecting and removing a loop in a linked list can be effectively solved using Floyd’s Cycle-Finding Algorithm (also known as the Tortoise and Hare Algorithm). The intuition behind this algorithm is that if you have two pointers moving at different speeds through the list, they will eventually meet if there is a cycle. Once a cycle is detected, you can determine the starting node of the cycle and remove the loop.

Approach:
Detect Loop:
Use two pointers, slow and fast.
Initialize both pointers to the head of the list.
Move slow one step at a time, and fast two steps at a time.
If slow and fast meet, a loop is detected.
If fast or fast->next becomes NULL, there is no loop.
Find the Start of the Loop:
Reset slow to the head of the list.
Move both slow and fast one step at a time.
They will meet at the start of the loop.
Handle Special Case (Loop at Head):
If the loop starts at the head, traverse to find the last node of the loop to correctly remove it.
Remove the Loop:
Once you find the node just before the start of the loop, set its next pointer to NULL.

Time Complexity:
O(n): The algorithm consists of two main parts: detecting the loop and finding the start of the loop. Each part takes linear time relative to the number of nodes in the list. Therefore, the overall time complexity is linear.
Space Complexity:
O(1): The algorithm uses a constant amount of extra space regardless of the size of the linked list. Only a few pointer variables are used.

Code:
*/
void removeLoop(Node* head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *slow = head, *fast = head;

    // Detect loop using Floyd's Cycle-Finding Algorithm
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, there is a loop
        if (slow == fast)
            break;
    }
    // If no loop is detected, return
    if (slow != fast)
        return;

    // Reset slow to head
    slow = head;
    // Special case: If slow meets fast at the head of the list
    if (slow == fast)
    {
        // Find the node before the start of the loop (last node in the loop)
        while (fast->next != slow)
            fast = fast->next;
    }
    else
    {
        // Move both pointers at the same pace
        // They will meet at the start of the loop
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    // Remove loop by setting the next pointer of the last node to NULL
    fast->next = NULL;
}
