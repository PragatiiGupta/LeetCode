/**
Intersection Point in Y Shaped Linked Lists.
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Intuition
Length Calculation: By calculating the lengths, we know how much one list is ahead of the other.
Alignment: By advancing the pointer of the longer list by the difference in lengths, we ensure both pointers traverse the same number of nodes to reach the intersection point.
Simultaneous Traversal: If there is an intersection, both pointers will meet at the intersection point. If there is no intersection, both will reach the end (NULL) together.

Time and Space Complexity

Time Complexity: O(n + m), where n and m are the lengths of the two lists.
Space Complexity: O(1), as no additional space is used beyond the pointers and variables needed.

Code
*/
int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
int intersectPoint(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    // Align the start of both lists
    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }    
    // Traverse both lists together to find the intersection point
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }    
    return -1; // No intersection found
}
