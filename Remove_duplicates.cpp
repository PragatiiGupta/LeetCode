/**
Remove duplicates from an unsorted linked list
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.
Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4

Intuition
The problem is to remove duplicates from an unsorted linked list. To achieve this efficiently, we can use a hash map to track the elements we have already encountered. By doing so, we can ensure that we only traverse the list once, making the operation efficient.

Approach
If the linked list is empty (head == NULL), return the head immediately.
Initialize a pointer first to traverse the list and a pointer prev to keep track of the previous node.
Use an unordered_map to store the data values of the nodes that we have encountered.
Iterate through the linked list using the first pointer.
For each node, check if its data value is already present in the map:
If the value is not in the map, add it to the map, move prev to point to the current node, and advance first to the next node.
If the value is in the map, it means the node is a duplicate. Adjust prev->next to skip this node, delete the current node, and move first to prev->next without advancing prev.
Returning the Modified List.

Time Complexity
O(n): The algorithm traverses each node exactly once. The insertion and lookup operations in an unordered_map have an average time complexity of O(1). Therefore, the overall time complexity is linear in the number of nodes.

Space Complexity
O(n): The unordered_map stores each unique value from the linked list. In the worst case, where all nodes have unique values, the map will store n entries, leading to a space complexity proportional to the number of nodes.

Code
*/
#include <unordered_map>
class Solution {
public:
    Node* removeDuplicates(Node* head) {
        if (head == NULL) return head;

        Node* first = head;
        Node* prev = NULL;
        std::unordered_map<int, bool> mp;
        while (first != NULL) {
            if (mp.find(first->data) == mp.end()) {
                mp[first->data] = true;
                prev = first; // Update prev only when first node is not a duplicate
                first = first->next;
            } else {
                prev->next = first->next;
                delete first;
                first = prev->next;
            }
        }
        return head;
    }
};
