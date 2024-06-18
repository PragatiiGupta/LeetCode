/**
Check if frequencies can be equal.
Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

Intuition
The problem requires checking if it is possible to remove at most one character from a string such that all remaining characters have the same frequency. The key insight is to analyze the frequency distribution of characters in the string. If there are only one or two distinct frequencies, it might be possible to balance them by removing one character.
Approach
Count Frequencies:
Use an unordered map to count the frequency of each character in the string.
Count Frequency of Frequencies:
Use another unordered map to count how often each frequency occurs.
Analyze Frequency Patterns:
If there is only one distinct frequency, the string is already balanced, so return true.
If there are more than two distinct frequencies, it’s impossible to balance by removing just one character, so return false.
If there are exactly two distinct frequencies, check if:
One frequency is 1 and it occurs only once (meaning we can remove one character with this frequency).
The higher frequency can be reduced by one to match the lower frequency (meaning we can remove one character to balance the frequencies).

Time Complexity
Building the frequency map: O(n), where nn is the length of the string.
Building the frequency count map: O(d), where dd is the number of distinct characters in the string (which is at most 26 for lowercase alphabetic characters).
Analyzing the frequency patterns: O(1), as we are only checking a fixed number of conditions (since there are at most two distinct frequencies).

Space Complexity
Frequency map: O(d), where dd is the number of distinct characters (at most 26).
Frequency count map: O(d).
Overall space complexity: O(d), which simplifies to O(1)for a fixed number of lowercase alphabetic characters.

Code
*/
bool sameFreq(string s)
	{
	       unordered_map<char, int> freqMap;
    unordered_map<int, int> freqCountMap;
    for (char c : s) {
        freqMap[c]++;
    }
    for (auto &entry : freqMap) {
        freqCountMap[entry.second]++;
    }
    if (freqCountMap.size() == 1) {
        return true;
    }
    if (freqCountMap.size() > 2) {
        return false;
    }
    auto it1 = freqCountMap.begin();
    auto it2 = next(it1);
    int freq1 = it1->first;
    int count1 = it1->second;
    int freq2 = it2->first;
    int count2 = it2->second;
    if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
        return true;
    }
    if ((abs(freq1 - freq2) == 1) && ((count1 == 1 && freq1 > freq2) || (count2 == 1 && freq2 > freq1))) {
        return true;
    }
    return false;
}
