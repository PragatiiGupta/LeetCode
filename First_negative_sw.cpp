/**
First negative integer in every window of size k.
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Intuition and Approach
The goal is to find the first negative integer in every subarray (window) of size k for a given array. Using a deque (double-ended queue) allows us to efficiently manage the indices of negative numbers within the current window, ensuring that we always have the oldest negative number at the front of the deque.

Here’s the step-by-step intuition and approach:
Initialization:
Create an empty deque dq to store indices of negative numbers.
Create a vector ans to store the result.
Processing the First Window:

Traverse the first k elements of the array.
If an element is negative, add its index to the deque.
After processing the first k elements, the front of the deque will contain the index of the first negative integer in this window. Append this element to ans.
Sliding the Window:

For each subsequent element in the array (from index k to n-1):
Remove indices from the front of the deque if they are out of the current window (i.e., if dq.front() <= i - k).
If the current element is negative, add its index to the back of the deque.
Append the first negative integer of the current window to ans. If the deque is empty, append 0.
  
Time and Space Complexity
Time Complexity:
Each element is processed exactly once (either added to the deque or removed from the deque).
Each operation (adding or removing from the deque) is O(1) because deque operations at both ends are O(1).
Thus, the overall time complexity is O(n), where n is the number of elements in the array.

Space Complexity:
The space complexity is O(k) for storing the indices in the deque because, at most, we store indices of k elements (in the worst case when all elements in the window are negative).
The result vector ans will store n-k+1 elements (one for each window), but this is considered output space and does not contribute to the auxiliary space complexity.

Code
*/
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
                                                 
    vector<long long> ans;
    deque<long long int> dq;
    for (long long int i = 0; i < k; ++i) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }
    if (!dq.empty()) {
        ans.push_back(arr[dq.front()]);
    } else {
        ans.push_back(0);
    }
    for (long long int i = k; i < n; ++i) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        if (arr[i] < 0) {
            dq.push_back(i);
        }
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}
