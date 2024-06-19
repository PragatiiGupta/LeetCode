/**
Longest K unique characters substring
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.
Intuition
The problem is to find the length of the longest substring with exactly k distinct characters. The sliding window technique is particularly well-suited for this type of problem, as it allows us to efficiently expand and contract the window to maintain the desired property of the substring (in this case, having exactly k distinct characters).

Approach
Sliding Window Initialization:
Use two pointers (start and end) to represent the current window.
Use an unordered map (mp) to count the frequency of characters within the current window.
Expanding the Window:
Iterate over the string using the end pointer.
Add the current character to the map and update its frequency.
Contracting the Window:
If the number of distinct characters in the map exceeds k, increment the start pointer to reduce the window size until the number of distinct characters is at most k.
Update the frequencies of characters in the map and remove characters that are no longer in the current window.
Tracking the Maximum Length:
Whenever the map contains exactly k distinct characters, calculate the length of the current window and update the maximum length if this window is longer than previously found windows.
Return the Result:
If a valid substring is found, return its length. Otherwise, return -1.

Time Complexity
Expanding and Contracting the Window:
Each character in the string is processed at most twice (once when the end pointer expands the window, and once when the start pointer contracts the window).
This results in a linear time complexity of O(n), where n is the length of the string.
Updating the Map:
Each update operation on the unordered map (insertion, deletion, and lookup) takes O(1) on average.

Space Complexity
Space Used by the Map:
The unordered map can store up to k distinct characters at any time, resulting in a space complexity of O(k).

Code
*/
    int longestKSubstr(string s, int k) {
        int start = 0, maxLength = -1;
        unordered_map<char, int> mp;
    
        for (int end = 0; end < s.size(); ++end) {
            mp[s[end]]++;
            while (mp.size() > k) {
                mp[s[start]]--;
                if (mp[s[start]] == 0) {
                    mp.erase(s[start]);
                }
                start++;
            }
            if (mp.size() == k) {
                maxLength = max(maxLength, end - start + 1);
            }
        }
        
        return maxLength;
}
