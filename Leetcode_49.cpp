/**
49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Intuition
Anagrams are words that have the same characters with the same frequency, but in different orders. By sorting each word, all anagrams will become identical strings. These identical strings can then be used as keys in a map to group the original words.

Approach
Sort each word: For each word in the input list, sort the characters. This sorted word will act as a unique key for all anagrams.
Use a map: Use an unordered_map where the key is the sorted word and the value is a list of original words that match this sorted word.
Group the anagrams: Iterate over the map and collect the grouped anagrams.

Time Complexity
Sorting each word: O(mlogm) where mm is the length of the word.
Total sorting for all words: O(n⋅mlogm) where n is the number of words.
Inserting into the map and iterating over it: O(n).
Space Complexity
The space used by the map: O(n⋅m) for storing the words and the keys.

Code 
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>>mp;
       vector<vector<string>>ans;
       for(string s : strs)
       {
        string index = s;
        sort(index.begin(),index.end());
        mp[index].push_back(s);
       }
       for(auto it: mp)
       {
        ans.push_back(it.second);
       }
       return ans;
    }
