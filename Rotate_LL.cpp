/**
Rotate a Linked List.
Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.
Approach:

First, the function calculates the length of the linked list using the findLen function.
It then adjusts the rotation value k to be within the range of the list length by taking the modulo k % length.
If after taking the modulo, k becomes zero, it means no rotation is needed, so it returns the original head.
Otherwise, it iterates to find the new tail of the rotated list. Then it sets the new head and tail pointers accordingly.
Finally, it breaks the original cycle by setting the old tail's next pointer to NULL and returns the new head.
Time Complexity:

Calculating the length of the linked list takes O(n) time, where n is the number of nodes in the list.
Taking the modulo operation and iterating to find the new tail both take O(n) time.
Overall, the time complexity is O(n).
Space Complexity:

The function uses a constant amount of extra space for storing pointers.
Therefore, the space complexity is O(1).

Code
*/

    int findLen(Node* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head -> next;
        }
        return len;
    }
    Node* rotate(Node* head, int k)
    {
        if(head == NULL or k==0)
        return head;
       int length = findLen(head);
       k = k % length;
       if(k==0)
       return head;
       Node *newTail=head;
       while(--k)
       {
         newTail = newTail -> next;
       }
       Node *newHead = newTail -> next;
       Node *oldTail = newTail;
       while(oldTail -> next != NULL)
       {
           oldTail = oldTail -> next;
       }
       oldTail -> next = head;
       newTail -> next = NULL;
       return newHead;
       
    }
