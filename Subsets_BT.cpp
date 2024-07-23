/**
Generate all subsets for the given array(Power sets).
Intuition:
The goal is to generate all possible subsets (also known as the power set) of a given set of integers. This can be done using a recursive backtracking approach. The idea is to explore all possible combinations of the elements in the set, including the empty set.

Approach:
Recursive Function: Define a recursive function generate that takes the current subset, the starting index, and the original vector.
Base Case: Start with an empty subset and push it to the result.
Loop Through Elements: For each element in the vector starting from the current index:
Add the current element to the subset.
Recursively call the generate function with the next index.
Backtrack by removing the last element added to the subset.
Main Function: Initialize the required data structures and call the recursive function starting with index 0.

Time Complexity:
Recursive Calls: Each element has two choices: either to be included in the subset or not, leading to 2^n subsets.
Adding to Result: Each subset (average size n/2) is added to the result, which takes O(n) time.
Total Complexity: O(n * 2^n).
Space Complexity:
Auxiliary Space (Call Stack): The maximum depth of the recursion tree is O(n).
Result Storage: Storing all subsets requires O(n * 2^n) space.
Total Complexity: O(n * 2^n) for the result storage plus O(n) for the recursion stack, which is dominated by O(n * 2^n).
Summary:
This approach efficiently generates all subsets of a given set using recursion and backtracking, with a time and space complexity of O(n * 2^n). 
The recursive function explores all possible combinations by including or excluding each element in the subset.

Code
*/

#include <bits/stdc++.h>
using namespace std;

void generate(vector<int>& vec, vector<int>& subset, vector<vector<int>>& res, int index) {
    res.push_back(subset);  
    for (int i = index; i < vec.size(); i++) { 
        subset.push_back(vec[i]); 
        generate(vec, subset, res, i + 1); 
        subset.pop_back();  
    }
}

int main() {
    vector<int> vec = {1, 2, 3};
    vector<int> subset;
    vector<vector<int>> res;
    generate(vec, subset, res, 0); 
    for (auto it : res) {
        for (auto ti : it) {
            cout << ti << " ";
        }
        cout << endl;
    }
    return 0;
}
