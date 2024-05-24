/**
Remove duplicate element from sorted Linked List
Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time. So we need to remove it once.

Explanation:
first starts at the head of the list.
second starts at the node following the head.
Continue the loop while second is not NULL.
If first->data is equal to second->data, we found a duplicate:
Set first->next to second->next to bypass the duplicate node.
Delete the duplicate node to free memory.
Update second to first->next to continue checking from the new next node.
If the data is not equal, move first and second pointers forward to continue checking the next pair of nodes.
After processing all nodes, return the modified list's head.

Time Complexity: O(n) where n is the number of nodes in the linked list. Each node is visited at most once.

Space Complexity: O(1). The algorithm uses a constant amount of extra space.
Code
*/
Node* removeDuplicates(Node* head) {
    if (head == NULL) return head; // Handle empty list

    Node* first = head;
    Node* second = head->next;

    while (second != NULL) { // Check `second` not `second->next`
        if (first->data == second->data) {
            first->next = second->next;
            delete second; // Free the memory of the duplicate node
            second = first->next; // Update `second` to `first->next`
        } else {
            first = second; // Move `first` to `second`
            second = second->next; // Move `second` to the next node
        }
    }
    return head;
}
       // Move prev to the current node
            curr = next;          // Move to the next node
        }
        head = prev;              // Update the head to the new front
        return head;
    }
};
