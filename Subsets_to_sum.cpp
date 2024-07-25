/**
Given an array of integers, find all possible subsets that sum up to a given target sum.
Intuition
We need to find all subsets of the given array whose elements sum up to a specified target sum. This can be solved using a backtracking approach, where we recursively explore all possible subsets and track the sum of their elements.

Approach
Initialize Variables: Create an empty subset and start with the first element.
Recursive Function: Create a recursive function that:
Adds the current element to the subset.
Checks if the current subset's sum equals the target sum.
Recursively calls itself to include or exclude the next elements.
Backtracking: Remove the last added element (backtrack) and explore the next possibilities.
Print Subset: If a subset's sum matches the target, print it.
Time Complexity
The time complexity is O(2^n) because each element has two possibilities (include or exclude), resulting in 2^n subsets.

Space Complexity
The space complexity is O(n) for the recursive stack and subset storage.

Code
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
    void generate(vector<int>&vec, vector<int>&sub, int sum, int k, int st, int n)
    {
        if(st == n ){
            if(sum == k){
           for(auto i : sub){
            cout << i ;}
            cout << endl;
            }
                return;
        }     
        sub.push_back(vec[st]);
        k += vec[st];
        generate(vec,sub,sum,k,st+1,n);
        k -= vec[st];
        sub.pop_back();
        
        generate(vec,sub,sum,k,st+1,n);
        
    }
int main() {
    vector<int>vec = {1,2,1};
    int sum = 2, n=3;
    vector<int>sub;
    generate(vec,sub,sum, 0,0,n);
}
