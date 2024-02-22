/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Intuition
The problem requires finding the bitwise AND of all numbers within the given range [left, right]. Our intuition is to find the common prefix of the binary representations of left and right, as this common prefix will be retained in the result of the bitwise AND operation for all numbers within the range.

Approach
We will iteratively right shift both left and right until they become equal, finding the common prefix of their binary representations. Then, we left shift left by the number of bits shifted in the process to obtain the result of the bitwise AND operation.

Complexity
Time complexity: O(log(max(left, right)))
The time complexity is dominated by the number of bits in the binary representation of the larger of left and right.
Space complexity: O(1)
The space complexity is constant as we are using a fixed amount of memory regardless of the input size.
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // Find the common prefix of left and right
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        // Shift left back to obtain the result
        return left << shift;
    }
};
