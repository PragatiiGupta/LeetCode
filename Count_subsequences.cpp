/**
Find count of total number of subsequences with sum equal to the given sum.
Given an array arr[] of length N and a number K, the task is to find the count of the subsequences of the array whose sum of elements is K

Examples:  
Input: arr[] = {1, 2, 3, 4}, K = 5 
Output: 
2

Intuition:
To count the number of subsequences of an array whose sum equals a given target sum, we can use a recursive approach. At each step, we have two choices: either include the current element in the subsequence or exclude it. By considering all possible combinations of these choices, we can count the number of subsequences whose sum equals the target sum.

Approach:
We define a recursive function countSubsequences that takes the array, the current index, a vector to store the current subsequence, the target sum, the current sum of the subsequence, and the current count as arguments.
At each recursive call, we have two choices:
Include the current element in the subsequence: We add the current element to the vector and update the current sum, then make a recursive call with the next index.
Exclude the current element from the subsequence: We do not add the current element to the vector and make a recursive call with the next index.
When we reach the end of the array, if the current sum equals the target sum, we increment the count.
We continue this process until we reach the end of the array.
Finally, we return the count of subsequences whose sum equals the target sum.

Time Complexity:
Let n be the length of the input array.
Since each element has two choices (include or exclude), there are 2^n possible subsequences.
Therefore, the total time complexity is O(2^n).

Space Complexity:
The space complexity is O(n) due to the space used by the recursion stack and the auxiliary vector to store each subsequence.
Overall, this approach efficiently counts the number of subsequences of the array whose sum equals the target sum, with a time complexity exponential in the length of the input array.

Code
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countSubsequences(int arr[],int n, int ind, int k,int s, int c )
{
    if(ind == n) 
    {
        if(s == k){
        c++;
        }
        return c;
    }
    s = s+arr[ind];
    c = countSubsequences(arr,n,ind+1,k,s,c);
    s = s-arr[ind];
    c = countSubsequences(arr,n,ind+1,k,s,c);
    return c;
}
int main()
{
    int arr[] = {5, 12, 3, 17, 1, 18, 15, 3, 17};
    int length = 9, k = 6;
    cout << countSubsequences(arr, length,0, k ,0,0);
    return 0;
}
