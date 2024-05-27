/**
Delete without head pointer
You are given a node del_node of a Singly Linked List where you have to delete a value of the given node from the linked list but you are not given the head of the list.

Intuition
The goal of the deleteNode function is to delete a node in a singly linked list when only that node is given and not the head of the list. The challenge is that we don't have direct access to the previous node, making the standard approach of adjusting the previous node's next pointer impractical. Instead, we can simulate the deletion by copying the data from the next node to the current node and then bypassing and deleting the next node.

Approach
Ensure that the given node (del_node) is not NULL and that it is not the last node in the list (del_node->next != NULL). This method relies on the existence of a next node.
Copy the data from the next node (del_node->next) into the current node (del_node). This effectively makes the current node a duplicate of the next node.
Set the next pointer of the current node to point to the node after the next node (del_node->next->next). This bypasses the next node, removing it from the list.
Delete the next node (del_node->next) to free up memory.

Time Complexity: O(1)
The function performs a constant amount of work, regardless of the size of the list. It involves copying data and adjusting a few pointers, which are all constant-time operations.

Space Complexity: O(1)
The function uses a constant amount of extra space. It only requires a few additional pointers, which do not depend on the size of the list.
Code
*/
void deleteNode(Node *del_node)
{
    // Check if the node to be deleted is not the last node
    if (del_node == NULL || del_node->next == NULL) {
        return;
    }
    // Copy data from the next node to the current node
    Node *temp = del_node->next;
    del_node->data = temp->data;
    del_node->next = temp->next;
    
    // Delete the next node
    delete temp;
}
