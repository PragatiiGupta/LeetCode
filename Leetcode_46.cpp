/**
46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Explanation:
Function backtrack:
start represents the index from which we need to start generating permutations.
If start equals the size of nums, we have generated a complete permutation, so we add it to the result.
We iterate over each element starting from start to the end of the array, swapping the current element with the start element, calling backtrack recursively with the next starting index, and then swapping back to restore the original order (backtracking).
Function permute:

Initializes the result vector.
Calls the backtrack function starting with index 0.
Returns the result containing all permutations.
Time Complexity:
Recursive Calls: There are n! permutations for an array of length n.
Swapping and Copying: Each permutation requires O(n) time to generate and store in the result.
Total time complexity: O(n * n!)

Space Complexity:
Auxiliary Space (Call Stack): The maximum depth of the recursion tree is O(n).
Result Storage: Storing all permutations requires O(n * n!) space.
Total space complexity: O(n * n!) for the result storage plus O(n) for the recursion stack, which is dominated by O(n * n!).

Code
*/
class Solution {
private:
    void generate(vector<int>&nums, vector<vector<int>>&ans, int index)
    {
        if(index == nums.size()){
            ans.push_back(nums);
            return;}
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            generate(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        generate(nums,ans,0);
        return ans;
    }
};
