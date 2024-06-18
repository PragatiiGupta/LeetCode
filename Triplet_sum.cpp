/**
Triplet Sum in Array.
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Approach
The goal is to find three numbers in an array arr of size n that add up to a given sum X. To achieve this efficiently, we can use a combination of sorting and the two-pointer technique.

Sort the Array: Sorting the array helps us use the two-pointer technique, which is efficient for finding pairs that sum to a specific value.
Fix One Element and Find a Pair: For each element arr[i], use two pointers to find if there exists a pair (arr[l], arr[r]) such that arr[i] + arr[l] + arr[r] = X.
Two-Pointer Technique:
Initialize the first pointer (l) to the element just after i and the second pointer (r) to the last element.
Move the pointers towards each other based on the sum of the three elements:
If the sum is equal to X, return true.
If the sum is less than X, increment the left pointer l to increase the sum.
If the sum is greater than X, decrement the right pointer r to decrease the sum.
Intuition
The intuition behind this approach is that sorting the array and using two pointers allows us to efficiently narrow down the search for the triplet. By fixing one element and using the two-pointer technique on the remaining array, we can check all possible triplets in O(n^2)time, which is much more efficient than a brute-force O(n^3)approach.

Time Complexity
Sorting: The array is sorted, which takes O(nlogn).
Two-pointer search for each element: For each of the nn elements, the two-pointer technique runs in O(n). Therefore, the overall time complexity for this part is O(n^2)
Combining these, the overall time complexity is:
O(nlog n) + O(n2) = O(n2)O(nlogn)+O(n2)=O(n2)

Space Complexity
The space complexity is O(1) because:
We are using a constant amount of extra space regardless of the input size.
The sorting operation can be done in place, and the two-pointer technique uses only a few additional variables.

Code
*/
bool find3Numbers(int arr[], int n, int X)
    {
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++) {
      
        int l = i + 1; 
        int r = n - 1; 
        while (l < r) {
            int current_sum = arr[i] + arr[l] + arr[r];
            if (current_sum == X) {
                return true;
            } else if (current_sum < X) {
                l++;
            } else {
                r--;
            }
        }
    }
    return false;
    }
