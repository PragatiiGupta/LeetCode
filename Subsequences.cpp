/**
Generating all possible Subsequences using Recursion including the empty one.

Given an array. The task is to generate and print all of the possible subsequences of the given array using recursion.

Examples: 

Input : [1, 2, 3]
Output : [3], [2], [2, 3], [1], [1, 3], [1, 2], [1, 2, 3], []

Input : [1, 2]
Output : [2], [1], [1, 2], []
 
Intuition:
To generate all subsequences of an array, we can use a recursive approach. At each step, we have two choices: either include the current element in the subsequence or exclude it. By considering all possible combinations of these choices, we can generate all possible subsequences.

Approach:

We define a recursive function printSubsequences that takes the array, the current index, a vector to store the current subsequence, and the length of the array as arguments.
At each recursive call, we have two choices:
Include the current element in the subsequence: We add the current element to the vector and make a recursive call with the next index.
Exclude the current element from the subsequence: We do not add the current element to the vector and make a recursive call with the next index.
We continue this process until we reach the end of the array (i.e., the current index becomes equal to the length of the array).
When we reach the end of the array, we print the elements in the vector, which represents a valid subsequence.

Time Complexity:
Let n be the length of the input array.
Since each element has two choices (include or exclude), there are 2^n possible subsequences.
For each subsequence, printing it takes O(n) time.
Therefore, the total time complexity is O(2^n.n)

Space Complexity:
The space complexity is O(n) due to the space used by the recursion stack and the auxiliary vector to store each subsequence.
Overall, this approach generates all possible subsequences of the array efficiently, with a time complexity exponential in the length of the input array.

Code:
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSubsequences(int arr[], int ind, vector<int> &v, int n)
{
    if(ind == n)
    {
        for(auto it : v)
        cout << it << " ";
        cout << endl;
        return;
    }
    v.push_back(arr[ind]);
    printSubsequences(arr,ind+1,v,n);
    v.pop_back();
    
    printSubsequences(arr,ind+1,v,n);
}
int main()
{
    int arr[]={1, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    printSubsequences(arr, 0, v, n);
 
    return 0;
}
