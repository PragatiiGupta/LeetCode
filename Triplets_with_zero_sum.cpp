/**
Find triplets with zero sum.
Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 
Note: Return 1, if there is at least one triplet following the condition else return 0.

Intuition:
For every element check that there is a pair whose sum is equal to the negative value of that element.

Approach:
Sort the array in ascending order.
Start traversing the array from the beginning to the end.
For each index i in the array, create two variables j = i + 1 and k = n – 1, where n is the length of the array.
Run a loop until j is less than k.
Inside the loop, check if the sum of array[i], array[j], and array[k] is equal to zero. If it is, return true and break otherwise proceed to the next step.
If the sum is less than zero, increment the value of j.
If the sum is greater than zero, decrement the value of k.

Time Complexity: O(n2), Only two nested loops are required, so the time complexity is O(n2).
Space Complexity: O(1), no extra space is required, so the space complexity is constant.

Code
*/
bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr+n);
        for(int i=0;i<n-1;i++)
        {
            int j = i+1;
            int k = n-1;
        while(j < k)
        {
            if(arr[i]+arr[j]+arr[k] == 0)
            {
                j++;
                k--;
                return true;
            }
            else if(arr[i]+arr[j]+arr[k] < 0)
            {
                j++;
            }
            else
             k--;
        }
        }
        return false;
    }
