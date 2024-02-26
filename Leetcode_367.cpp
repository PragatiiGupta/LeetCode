/*
Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself. Inbuilt functions like sqrt must not be used.

Intuition
To determine if a given number is a perfect square, we can iterate from 1 to the square root of the number and check if the square of any integer equals the given number.

Approach
Iterate from 1 to the square root of the given number.
Check if the square of the current integer equals the given number.
If a perfect square is found, return true; otherwise, return false.

Complexity
Time complexity: The time complexity is O(sqrt(num)), where num is the given number. We iterate up to the square root of num.
Space complexity: The space complexity is O(1) since we're using only a constant amount of extra space.

Code
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        // Iterate from 1 to the square root of num
        for (long long i = 1; i * i <= num; ++i) {
            // Check if the square of current integer equals num
            if (i * i == num) {
                return true; // Found a perfect square
            }
        }
        return false; // No perfect square found
    }
};

