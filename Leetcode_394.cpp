/**
394. Decode String
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

Explanation:
Avoiding Repeated String Concatenation:
By handling the number formation (k = k * 10 + (c - '0')), the digits are accumulated directly to form the full number before processing the enclosed string.
The currentString is built incrementally as we traverse the input string, and is only updated after processing a complete nested pattern.
Simplified Handling of Numbers:
The number is accumulated in a straightforward manner, making the code cleaner and avoiding the need for additional parsing logic.

Time and Space Complexity:
Time Complexity: O(N), where N is the length of the input string. Each character is processed once, and string operations (like appending) are handled efficiently.
Space Complexity: O(N), due to the use of stacks and additional strings to store intermediate results.

Code
*/
string decodeString(string s) {
    stack<int> numStack;  // Stack to store numbers
    stack<string> strStack;  // Stack to store strings
    string currentString = "";
    int k = 0;

    for (char c : s) {
        if (isdigit(c)) {
            k = k * 10 + (c - '0');  // Form the number k
        } else if (c == '[') {
            numStack.push(k);  // Push the number k to numStack
            strStack.push(currentString);  // Push the current string to strStack
            k = 0;  // Reset k
            currentString = "";  // Reset currentString
        } else if (c == ']') {
            int currentK = numStack.top();
            numStack.pop();
            string decodedString = strStack.top();
            strStack.pop();

            for (int i = 0; i < currentK; ++i) {
                decodedString += currentString;  // Append the current string currentK times
            }

            currentString = decodedString;  // Update currentString with decodedString
        } else {
            currentString += c;  // Append the current character to currentString
        }
    }

    return currentString;
}
