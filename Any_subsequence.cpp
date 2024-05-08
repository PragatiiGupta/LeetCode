/** Find any of the subsequences with sum equal to the given sum.
Given an array arr[] of length N and a number K, the task is to find any of the subsequences of the array whose sum of elements is K

Examples:  
Input: arr[] = {1, 2, 3, 4}, K = 5 
Output: 
2 3 

Intuition:
To find a subsequence of an array whose sum equals a given target sum, we can use a recursive approach. At each step, we have two choices: either include the current element in the subsequence or exclude it. By considering all possible combinations of these choices, we can generate all possible subsequences and check if their sum equals the target sum.

Approach:
We define a recursive function countSubsequences that takes the array, the current index, a vector to store the current subsequence, the target sum, and the current sum of the subsequence as arguments.
At each recursive call, we have two choices:
Include the current element in the subsequence: We add the current element to the vector and update the current sum, then make a recursive call with the next index.
Exclude the current element from the subsequence: We do not add the current element to the vector and make a recursive call with the next index.
When we reach the end of the array, if the current sum equals the target sum, we print the elements in the vector, which represents a valid subsequence, and return true.
We continue this process until we reach the end of the array.
If no subsequence with the sum equal to the target sum is found, the function returns false.

Time Complexity:
Let nn be the length of the input array.
Since each element has two choices (include or exclude), there are 2^n possible subsequences.
For each subsequence, printing it takes O(n time.
Therefore, the total time complexity is O(2^n.n)

Space Complexity:
The space complexity is O(n) due to the space used by the recursion stack and the auxiliary vector to store each subsequence.
Code
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool countSubsequences(int arr[],int n,vector<int> &v, int ind, int k,int s )
{
    if(ind == n) 
    {
        if(s == k){
        for(auto it : v)
        cout << it << " ";
        cout << endl;
        return true;
        }
        return false;
    }
    v.push_back(arr[ind]);
    s = s+arr[ind];
    if(countSubsequences(arr,n,v,ind+1,k,s)) return true;
    s = s-arr[ind];
    v.pop_back();
    
    if(countSubsequences(arr,n,v,ind+1,k,s)) return true;
    return false;
}
int main()
{
    int arr[] = {5, 12, 3, 17, 1, 18, 15, 3, 17};
    int length = 9, k = 6;
    vector<int> v;
 
    countSubsequences(arr, length, v,0, k ,0);
    return 0;
}
