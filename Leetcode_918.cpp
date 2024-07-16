/**
918. Maximim sum circular subarray
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

Explanation:
Kadane's Algorithm: Finds the maximum subarray sum for non-circular subarrays.
Total Sum Calculation: Computes the sum of all elements in the array.
Inverted Array for Minimum Subarray Sum: By inverting the elements and applying Kadane's algorithm, we effectively find the minimum subarray sum of the original array.
Handling Edge Cases: If all elements are negative, max_circular will be zero. In this case, we return max_kadane since the circular subarray sum isn't valid.

Complexity:
Time Complexity: O(n), since we perform a constant number of passes over the array.
Space Complexity: O(1), since we use a fixed amount of extra space.

Code
*/
int maxSubarraySumCircular(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    auto kadane = [](const vector<int>& arr) {
        int max_global = arr[0], max_curr = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            max_curr = max(arr[i], arr[i] + max_curr);
            max_global = max(max_curr, max_global);
        }
        return max_global;
    };

    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int kadane_sum = kadane(nums);

    for (int& i : nums) {
        i = -i;
    }

    int inv_sum = kadane(nums);
    int cir_sum = total_sum + inv_sum;

    if (cir_sum == 0) {
        return kadane_sum; 
    }

    return max(kadane_sum, cir_sum);
}
