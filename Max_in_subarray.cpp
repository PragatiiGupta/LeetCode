/**
Maximum of all subarrays of size k
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Intuitive Approach
An intuitive approach to find the maximum of each subarray of size kk is to use a sliding window technique. In this approach, we iterate over each possible subarray, find its maximum, and store it. This can be implemented using nested loops.

Steps:
Iterate over the array with an outer loop to define the start of each subarray.
For each subarray, use an inner loop to find the maximum element within that subarray.
Store the maximum element in the result list.
Time Complexity
The time complexity of this intuitive approach is O(nk)O(nk):

The outer loop runs n - k + 1n−k+1 times, where nn is the length of the array.
The inner loop runs kk times for each iteration of the outer loop to find the maximum element in the subarray of size kk.
Thus, the overall time complexity is O(nk)O(nk).

Space Complexity
The space complexity of this approach is O(1)O(1) for the algorithm itself, but O(n - k + 1)O(n−k+1) for storing the results:

The algorithm only uses a few additional variables for tracking indices and the maximum value in the current subarray.
The result list requires O(n - k + 1)O(n−k+1) space to store the maximum of each subarray.
Code
*/
vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<pair<int,int>>pq;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            pq.push({arr[i],i});
            
            while(pq.top().second <= i-k )
            pq.pop();
            
            if(i >= k-1)
            ans.push_back(pq.top().first);
            
        }
        return ans;
        
    }
