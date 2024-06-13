Longest Sub-Array with Sum K.
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

Explanation
HashMap (prefixSumMap):
The hash map stores the sum of elements up to the current index and the first occurrence of this sum. This helps in efficiently finding subarrays with a sum equal to KK.
Iterate through the array:
Calculate the cumulative sum (sum) while iterating through the array.
If the cumulative sum is equal to KK, it means the subarray from the start to the current index has the required sum, so update maxLen.
Check if sum - K exists in the hash map. If it does, it means there exists a subarray that sums to KK between the previous occurrence of sum - K and the current index.
Update maxLen if the length of the current subarray is greater than the previous maxLen.
Update HashMap:
If the current sum is not already in the hash map, store it with the current index. This ensures we store the earliest occurrence of each sum.

Time and Space Complexity
Time Complexity: O(N), where NN is the number of elements in the array. We iterate through the array once, and each operation with the hash map (insert and find) is O(1) on average.
Space Complexity: O(N), due to the hash map storing the cumulative sums and their indices. In the worst case, all elements could contribute to different sums.

Code
*/
int lenOfLongSubarr(int arr[], int N, int K) {
        unordered_map<int, int> prefixSumMap;
        int sum = 0;
        int maxLen = 0;
    
        for (int i = 0; i < N; i++) {
            sum += arr[i];
            if (sum == K) {
                maxLen = i + 1;
            }
            if (prefixSumMap.find(sum - K) != prefixSumMap.end()) {
                maxLen = max(maxLen, i - prefixSumMap[sum - K]);
            }
            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }
        return maxLen;
}
