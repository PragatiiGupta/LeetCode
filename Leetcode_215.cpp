/**
215. Kth Largest element in an array.
Given an integer array nums and an integer k, return the kth largest element in the array.Can you solve it without sorting?
Explanation:
Initialize Priority Queue:
This initializes a max heap, where the largest element is always at the top.
Push All Elements into the Priority Queue:
This loop inserts all elements from the nums vector into the priority queue.
Remove the Largest Elements k-1 Times:
This loop removes the top (largest) element from the priority queue k-1 times. After this loop, the k-th largest element will be at the top of the priority queue.
Return the k-th Largest Element:
This retrieves and returns the top element of the priority queue, which is the k-th largest element.

Complexity Analysis:
Time Complexity:
Inserting each element into the priority queue takes O(logn) time. For n elements, this is O(nlogn).
Popping the top element k-1 times takes O(klogn) time.
Overall, the time complexity is O(nlogn+klogn)=O(nlogn) since k≤n.

Space Complexity:
The space complexity is O(n) due to the space required to store the elements in the priority queue.
Code 
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i : nums) {
            pq.push(i);
        }
        while(--k) {
            pq.pop();
        }
        int ans = pq.top();
        return ans;
    }
};
