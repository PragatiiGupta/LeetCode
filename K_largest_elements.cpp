/**
k largest elements.
Given an array arr of n positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

Intuition
The goal is to find the k largest elements from an array. Using a max-heap (priority queue in C++), we can efficiently keep track of the largest elements. The max-heap property ensures that the largest element is always at the top, allowing us to easily extract the k largest elements.

Approach
Initialize a Max-Heap:
Use a priority queue (priority_queue<int> pq) to create a max-heap, where the largest element is always at the top.
Push All Elements into the Max-Heap:
Iterate through the array and push each element into the priority queue. This ensures that the largest element will always be at the top of the heap.
Extract the k Largest Elements:
Pop the top element from the priority queue k times. Each time, the top element (which is the largest remaining element) is added to the result vector.
Return the Result:
The result vector will contain the k largest elements from the array.

Time Complexity
Pushing Elements into the Priority Queue:
Each push operation takes O(log n) time because the heap needs to be rebalanced after each insertion.
For n elements, this results in O(n log n) time complexity.
Extracting the k Largest Elements:
Each pop operation also takes O(log n) time because the heap needs to be rebalanced after each removal.
For k elements, this results in O(k log n) time complexity.
Total Time Complexity:
O(n log n + k log n), which simplifies to O(n log n) since k is typically much smaller than n.
Space Complexity
Space Used by the Priority Queue:
The priority queue will store n elements, resulting in O(n) space complexity.
Space Used by the Result Vector:
The result vector will store k elements, which is O(k) space complexity.
Total Space Complexity:
O(n) because the dominant term is the space required to store all elements in the priority queue.

Code
*/
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int>pq;
	    vector<int> ans;
	    for(int i=0;i<n;i++)
	    {
	        pq.push(arr[i]);
	    }
	    for(int i=0;i<k;i++){
              ans.push_back(pq.top());
		pq.pop();
		}
		return ans;
		}
