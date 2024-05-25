/**
Delete a Node in Single Linked List.
Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Intuition:
The function needs to handle deleting a node at a specific position in a singly linked list. Special attention is needed for edge cases, such as deleting the head node or handling invalid positions.

Approach:
If the list is empty, return the list as is.
If the node to delete is the head (x == 1), adjust the head pointer.
Traverse the List:
Traverse the list while decrementing x until the node just before the target node is found.
Maintain a prev pointer to keep track of the node before curr.
Delete the Node:
Adjust the next pointer of the prev node to point to the node after curr.
Delete curr to free the memory.
Return the updated head of the list.

Time Complexity: O(n)
In the worst case, the function needs to traverse the entire list, where n is the number of nodes.
Space Complexity: O(1)
The function uses a constant amount of extra space for pointers (curr and prev).

Example Walkthrough
For a linked list 1 -> 2 -> 3 -> 4 and x = 3 (1-based position):

Initial State:
List: 1 -> 2 -> 3 -> 4
x is 3.
Traverse to the Node:
After first iteration: curr is at 2, prev is at 1.
After second iteration: curr is at 3, prev is at 2.
Delete the Node:
Adjust prev->next to skip curr (3) and point to curr->next (4).
Delete curr (3).
Final State:
List: 1 -> 2 -> 4.

Code
*/
Node* deleteNode(Node *head,int x)
{
    if(head == NULL)
    return head;
    Node *curr = head, *prev = NULL;
    if(x==1)
    {
        head = curr->next;
        delete curr;
        return head;
    }
    while(--x && curr != NULL)
    {
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = curr -> next;
    delete curr;
    return head; 
}
