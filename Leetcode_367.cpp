/*
Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

Intuition
To determine if a given number is a perfect square, we can calculate its square root and check if it's an integer.

Approach
Calculate the square root of the given number.
Check if the square root is an integer by comparing it with its integer value.
If the square root is an integer, return true; otherwise, return false.

Complexity
Time complexity: The time complexity of calculating the square root using sqrt() function is typically O(1) since it's an efficient mathematical operation. Therefore, the overall time complexity of the solution is O(1).
Space complexity: The space complexity is also O(1) since we're using only a constant amount of extra space for storing the square root value.

Code
*/

#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num) {
        // Calculate the square root of num
        double squareRoot = sqrt(num);

        // Check if the square root is an integer
        if (squareRoot == static_cast<int>(squareRoot)) {
            return true;
        } else {
            return false;
        }
    }
};
