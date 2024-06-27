/**
128. Longest consecutive sequence in O(n).
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
Explanation
Initialization:
hash is an unordered set initialized with all elements from nums.
Check if nums is empty and return 0 if true.
Iteration:
Iterate through each element in hash.
If the current element is the start of a sequence (itr - 1 is not in hash), initialize the streak and current number.
Use a while loop to find the length of the sequence by checking for consecutive numbers.
Update max_streak if the current streak is longer.
Time Complexity
The algorithm runs in O(n) time complexity because each number is processed at most twice (once in the for loop and once in the while loop).
Space Complexity
The space complexity is O(n) for storing the elements in the unordered set.
Code
*/

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    
    unordered_set<int> hash(nums.begin(), nums.end());
    int max_streak = 0;
    
    for (auto num : hash) {
        // Check if it is the start of a sequence
        if (hash.find(num - 1) == hash.end()) {
            int current_num = num;
            int streak = 1;
            
            // Count the length of the sequence
            while (hash.find(current_num + 1) != hash.end()) {
                current_num += 1;
                streak += 1;
            }       
            max_streak = max(max_streak, streak);
        }
    }
    
    return max_streak;
}
