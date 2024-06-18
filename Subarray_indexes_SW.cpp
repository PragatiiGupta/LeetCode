/**
Find Indexes of a subarray with given sum.
Given an unsorted array A of size N that contains only non negative integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.
In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.
Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Intuition and Approach
Initialization:
start is the starting index of the current subarray.
currentSum keeps track of the sum of the current subarray.
ans will store the result.
Iterate through the array:
Add the current element to currentSum.
If currentSum exceeds the target sum s, increment start to reduce the sum until it is less than or equal to s.
If currentSum equals s, store the 1-based indices of the subarray and return ans.
Handle cases where no subarray is found:
If no subarray is found that adds up to s, return [-1].
  
Time and Space Complexity
Time Complexity: O(n) because each element is added and removed from the currentSum at most once.
Space Complexity: O(1) excluding the space used to store the result. The space used for the result is O(1) as well since it will always contain either two indices or a single -1.

Code
*/
 vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
       int st=0;
       vector<int> ans;
       long long sum=0;
       for(int end=0;end<n;end++){
          sum += arr[end];
          while(sum > s && end > st){
              sum -= arr[st];
              st = st + 1;
          }
          
          if(sum == s)
          {
              ans.push_back(st+1);
              ans.push_back(end+1);
              return ans;
          }
    }
    ans.push_back(-1);
    return ans;
    }
