/*
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

Intuition
The intuition behind this problem is to use two pointers, i and j, starting from the beginning and end of the array, respectively, and swap elements to move even numbers to the beginning and odd numbers to the end of the array.

Approach
The approach involves initializing two pointers, i and j, at the start and end of the array, respectively. We iterate through the array using these pointers, swapping elements whenever necessary to ensure that even numbers are moved to the beginning and odd numbers are moved to the end. We continue this process until i crosses j.

Complexity
Time complexity: The time complexity of this approach is O(n), where n is the number of elements in the array. This is because we iterate through the array once, and each iteration involves constant-time operations.
Space complexity: The space complexity is O(1) because we use only a constant amount of extra space for storing the two pointers i and j. We do not use any additional data structures that grow with the size of the input.

  */

Code
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            if (nums[i] % 2 == 0) {
                cout << nums[i];
                i++;

            } else if (nums[j] % 2 == 0) {
                swap(nums[i], nums[j]);
                cout << nums[i] << nums[j];
                i++;
                j--;
            }
            if(nums[j] % 2 != 0)
            j--;
        }
        return nums;
    }
};
