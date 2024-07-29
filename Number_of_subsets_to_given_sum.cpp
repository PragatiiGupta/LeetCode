/**
Given an array of integers, write a function to find the number of subsets whose sum equals a given target value. Implement this function using recursion and return the count directly from the recursive function.

Intuition:
To solve this problem, we need to explore all possible subsets of the given array and check if their sum equals the target value. A recursive approach can be employed to either include or exclude each element of the array in the subset and keep track of the current sum. This time, instead of using an external count variable, we return the count directly from the recursive calls.

Approach:
Base Case: If we reach the end of the array (st == n), we check if the current sum equals the target sum (sum). If it does, we return 1 indicating a valid subset. Otherwise, return 0.
Recursive Case: For each element in the array, we have two choices:
Include the current element in the subset and update the current sum.
Exclude the current element from the subset and keep the current sum unchanged.
Recursive Function: Call the recursive function for both the above choices and return the sum of valid subsets from both recursive calls.

Space Complexity:
The space complexity is O(n) for the recursion stack, where nn is the length of the input array. This occurs because the maximum depth of the recursion tree is n, and the subset vector sub can hold up to nn elements. Additionally, the vec array and the count variable consume space, but this is O(n) and O(1) respectively, making the overall space complexity dominated by the recursion stack, which is O(n).
Code
*/
#include <iostream>
#include <vector>
using namespace std;

int generate(vector<int>& vec, vector<int>& sub, int sum, int k, int st, int n) {
    if (st == n) {
        if (sum == k) {
            return 1;
        }
        return 0;
    } 
    // Include vec[st] in the subset
    sub.push_back(vec[st]);
    k += vec[st];
    int left = generate(vec, sub, sum, k, st + 1, n);
    // Exclude vec[st] from the subset
    k -= vec[st];
    sub.pop_back();
    int right = generate(vec, sub, sum, k, st + 1, n);
    return left+right;
}

int main() {
    vector<int> vec = {1, 2, 1};
    int sum = 2;
    vector<int> sub;
    cout << generate(vec, sub,sum, 0, 0, vec.size()); 
    return 0;
}
