/**
209. Minimum Size subarray sum.
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray 
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Explanation
Initialization:
sum keeps track of the current window sum.
j is the starting index of the current window.
res is initialized to INT_MAX to ensure any found subarray length will be smaller.
Main Loop:
Traverse through the array with i.
Add nums[i] to sum.
Inner While Loop:
Check if the current sum is greater than or equal to the target.
If true, update res with the minimum of the current subarray length (i - j + 1) and res.
Subtract nums[j] from sum and increment j to shrink the window from the left.
Final Return:
If res was not updated (still INT_MAX), it means no valid subarray was found, so return 0.
Otherwise, return res.

Complexity Analysis
Time Complexity: O(n)
Each element is added and removed from the sum at most once, resulting in a linear time complexity.
Space Complexity: O(1)
Only a fixed amount of extra space is used, irrespective of the input size.
This approach efficiently finds the minimal length of a contiguous subarray whose sum is at least the target value.

Code
*/
int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int j = 0;
    int res = INT_MAX;  // Initialize res to the maximum possible value

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        
        // Shrink the window from the left as long as the sum is greater than or equal to target
        while (sum >= target) {
            res = min(res, i - j + 1);
            sum -= nums[j++];
        }
    }
    
    // If res was not updated, return 0
    return res == INT_MAX ? 0 : res;
}
