# Least Number of Unique Integers after K Removals

## Intuition
The intuition behind this problem is to count the frequency of each integer in the array and then greedily remove the least frequent integers until the condition is met. By sorting the integers based on their frequencies, we can easily determine which ones to remove first.

## Approach
1. Count the frequency of each integer in the array using a hash map.
2. Create a vector of pairs where each pair contains an integer and its frequency.
3. Sort the vector of pairs based on the frequencies of the integers.
4. Iterate through the sorted vector and greedily remove integers until the condition is met (i.e., the remaining frequency of each integer is less than or equal to k).
5. Return the number of remaining unique integers.

## Complexity
- Time complexity: O(n log n) for sorting the vector of pairs, where n is the size of the input array.
- Space complexity: O(n) for storing the frequencies of the integers in the hash map and the vector of pairs.
