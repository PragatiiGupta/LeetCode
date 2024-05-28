/**
Given a linked list of 0s, 1s and 2s, sort it.
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Intuition
The problem requires segregating nodes in a linked list based on their values. Essentially, we need to rearrange the linked list such that all nodes with the same value are grouped together. This can be efficiently achieved using a map to count occurrences of each value and then reconstructing the linked list based on these counts.

Approach
Traverse the linked list and use a map (or dictionary) to count the occurrences of each distinct value.
Traverse the map, and for each key-value pair, set the values of the linked list nodes according to the counts stored in the map.
If the linked list is empty (head == NULL), return the head as it is.
Initialize an empty map mp.
Traverse the linked list with a pointer curr and count each node's value by incrementing the corresponding entry in the map.
Reset the pointer curr to the head of the linked list.
Iterate through each key-value pair in the map.
For each key (value in the list) and its count, update the nodes' values in the linked list sequentially.
Return the head of the modified linked list.

Time Complexity
Counting Values: The first traversal of the linked list takes O(n) time, where n is the number of nodes in the linked list.
Reconstructing the List: The second traversal, updating the linked list based on the map, also takes O(n) time.
Total Time Complexity: O(n) + O(n) = O(n)

Space Complexity
Map Storage: The map stores counts of unique values. In the worst case, if all values are unique, it takes O(k) space, where k is the number of unique values in the linked list.
Pointer Storage: A constant amount of space is used for pointers curr, head, and iterators.
Total Space Complexity: O(k)

Code
*/
Node* segregate(Node *head) {
    if (head == NULL)
        return head;

    map<int, int> mp;
    Node *curr = head;

    // Count occurrences of each value
    while (curr != NULL) {
        mp[curr->data]++;
        curr = curr->next;
    }

    curr = head;

    // Reconstruct the list using the counts
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        int value = it->first;
        int count = it->second;
        while (count--) {
            curr->data = value;
            curr = curr->next;
        }
    }

    return head;
}
