/**
First non-repeating character in a stream.
Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

Explanation
Initialization:
charFrequency (unordered map) to store the frequency of each character.
charQueue (queue) to maintain the order of characters as they appear.
result (string) to store the result.
Iterate through the input string:
For each character c in the input, update its frequency in charFrequency.
Push the character into charQueue.
Check the front of the queue:
If the frequency of the character at the front of the queue is more than 1, it means this character is no longer unique, so pop it from the queue.
If the frequency is 1, this character is currently the first unique character, so append it to the result string.
If the queue is empty after checking, append # to the result to denote no unique character so far.

Time Complexity
Processing each character: O(1)O(1) for map operations (average case) and queue operations.
Overall time complexity: O(N)O(N), where NN is the length of the input string.
Space Complexity
Map and queue storage: O(M)O(M), where MM is the number of unique characters in the string.

Code
*/
string FirstNonRepeating(string A) {
    map<char, int> mp;
    queue<char> q;
    string B;
    for (char c : A) {
        mp[c]++;
        q.push(c);
        while (!q.empty()) {
            if (mp[q.front()] > 1) {
                q.pop();
            } else {
                B.push_back(q.front());
                break;
            }
        }
        if (q.empty()) {
            B.push_back('#');  // No unique character so far
        }
    }
    return B;
}
