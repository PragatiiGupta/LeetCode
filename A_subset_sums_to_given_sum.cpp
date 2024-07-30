/*
Given an array of integers, find any one subset that sums up to a given target sum.

Intuition
We need to find a subset of the given array whose elements sum up to a specified target sum. This can be solved using a backtracking approach where we recursively explore subsets and track the sum of their elements. If we find a subset that meets the criteria, we stop further exploration.

Approach
Initialize Variables: Create an empty subset and start with the first element.
Recursive Function: Create a recursive function that:
Adds the current element to the subset and updates the current sum.
Checks if the current subset's sum equals the target sum. If it does, print the subset and return true.
Recursively calls itself to include or exclude the next elements.
Backtracking: Remove the last added element (backtrack) and explore the next possibilities.
Termination: If a valid subset is found, terminate further exploration.
Time Complexity
The time complexity is O(2^n) because each element has two possibilities (include or exclude), resulting in 2^n subsets.

Space Complexity
The space complexity is O(n) for the recursive stack and subset storage.

Code
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
    bool generate(vector<int>&vec, vector<int>&sub, int sum, int k, int st, int n)
    {
        if(st == n ){
            if(sum == k){
           for(auto i : sub){
            cout << i << " ";
           }
            cout << endl;
            return true;
            }
                return false;
        }
        
        sub.push_back(vec[st]);
        k += vec[st];
        if(generate(vec,sub,sum,k,st+1,n)) return true;
        k -= vec[st];
        sub.pop_back();
        
        if(generate(vec,sub,sum,k,st+1,n)) return true;
        return false;
        
    }
int main() {
    vector<int>vec = {1,2,1};
    int sum = 2, n=3;
    vector<int>sub;
    generate(vec,sub,sum, 0,0,n);
}
