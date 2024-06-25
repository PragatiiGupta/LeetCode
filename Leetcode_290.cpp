/**
290. Word Pattern
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Explanation
Splitting the String into Words:
Use stringstream to break the string s into individual words and store them in a vector called words.
Pattern and Words Length Check:
If the number of words does not match the length of the pattern, return false.
Mapping Characters to Words:
Iterate through the pattern using an index.
For each character in the pattern, check if it has already been mapped to a word. If so, ensure it maps to the current word. If not, add the mapping.
Mapping Words to Characters:
Similarly, check if the word has already been mapped to a character. If so, ensure it maps to the current character. If not, add the mapping.
Return Result:
If all checks pass, return true.

Complexity Analysis
Time Complexity: O(n)
Splitting the string and processing each word/character pair takes linear time relative to the length of the input string and pattern.
Space Complexity: O(n)
The additional space is used for the maps and the vector of words, both of which depend on the length of the input string.
This approach ensures that each character in the pattern maps uniquely to a word in the string and vice versa, satisfying the problem constraints.

Code
*/
bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word){
        words.push_back(word);}
        if(words.size() != pattern.size())
        return false;
        for(int i=0;i<pattern.size();i++)
        {
            if(mp1.find(pattern[i]) != mp1.end())
            {
                if(mp1[pattern[i]] != words[i])
                return false;
            }
            else
            mp1[pattern[i]] = words[i];

            if(mp2.find(words[i]) != mp2.end())
            {
                if(mp2[words[i]] != pattern[i])
                return false;
            }
            else
            mp2[words[i]] = pattern[i];
        }
        return true;
    }
