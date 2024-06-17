Longest substring with repeating characters.
Given a string s, find the length of the longest substring without repeating characters.

Explanation of the Code
Initialization:
ans is used to store the length of the longest substring without repeating characters.
st is the start index of the current window.
mp is an unordered map that stores the last occurrence index of each character.
Main Loop:
Iterate through the string using i as the current index.
For each character s[i]:
Check if the character has been seen before and if its last occurrence is within the current window. If so, move st to one position right of its previous occurrence.
Update the last occurrence index of the current character in the map.
Calculate the length of the current window (i - st + 1) and update ans with the maximum length found so far.
Final Return:
The function returns ans, which holds the length of the longest substring without repeating characters.

Complexity Analysis
Time Complexity: O(n)
Each character is processed at most twice (once when expanding the window and once when contracting it), resulting in linear time complexity.
Space Complexity: O(min(n, m))
The space complexity is proportional to the number of unique characters in the input string (min(n, m)), where m is the size of the character set.
Code
*/
    int lengthOfLongestSubstring(string s) {
        int ans=0,st=0;
        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= st)
            {
               st = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            ans = max(ans, i-st+1);
            
        }
        return ans;
    }
};
