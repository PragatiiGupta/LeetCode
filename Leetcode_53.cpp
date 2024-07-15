/**
53. Maximum Subarray(kadane's algoithm)
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Explanation:
Initialization:
curr_sum is initialized to the first element of the array.
global_sum is also initialized to the first element of the array.
Iteration:
The loop starts from the second element (i = 1).
For each element, curr_sum is updated to the maximum of the current element or the sum of curr_sum and the current element.
If curr_sum is greater than global_sum, update global_sum.
Return:
After iterating through the array, global_sum will contain the maximum subarray sum.

Complexity Analysis:
Time Complexity: O(n) since it iterates through the array only once.
Space Complexity: O(1) since it uses a constant amount of extra space.

Code
*/
int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int curr_sum=nums[0],global_sum=nums[0];
        int size = nums.size();
        for(int i=1;i<size;i++)
        {
            curr_sum = max(nums[i],curr_sum+nums[i]);
            if(curr_sum > global_sum)
                global_sum = curr_sum;
        }
        return global_sum;
    }
