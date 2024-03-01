/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Intuition
My first thoughts on how to solve this problem are to iterate through the array and check whether it is monotonic increasing or monotonic decreasing. We can do this by comparing adjacent elements in the array.

Approach
I will use two boolean variables, increasing and decreasing, to track whether the array is monotonic increasing or monotonic decreasing. We will iterate through the array once and update these flags accordingly. If either flag is true at the end of the iteration, we will return true, indicating that the array is monotonic.

Complexity
Time complexity: O(n), where n is the number of elements in the array. We iterate through the array once.
Space complexity: O(1), because we only use a constant amount of extra space for storing the boolean flags increasing and decreasing. We do not use any additional data structures that grow with the size of the input.

Code 
  */
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                increasing = false;
            } else if (nums[i] < nums[i + 1]) {
                decreasing = false;
            }
        }

        return increasing || decreasing;
    }
};
