/**
56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Explanation:
Sorting:
We first sort the intervals based on their starting points. This allows us to process the intervals in order and makes it easier to merge overlapping intervals.
Merging:
We initialize an empty list called merged to store the merged intervals.
We iterate through the sorted list of intervals. For each interval, we check if the merged list is empty or if the current interval does not overlap with the last interval in the merged list (i.e., the end of the last interval in merged is less than the start of the current interval). If either condition is true, we add the current interval to merged.
If the current interval overlaps with the last interval in merged, we merge them by updating the end of the last interval in merged to be the maximum of the end of the last interval in merged and the end of the current interval.
Time Complexity:
Sorting the intervals takes O(nlogn) time, where nn is the number of intervals.
The merging process takes O(n) time since we iterate through the intervals once.
Thus, the overall time complexity is O(nlogn).
Space Complexity:
The space complexity is O(n) in the worst case, where all intervals are merged into a single interval, as we store the merged intervals in a separate list.

Code
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> arr;
        for(const auto& interval : intervals)
        {
            if(arr.empty() || arr.back()[1] < interval[0])
                arr.push_back(interval);
            else{
                arr.back()[1] = max(arr.back()[1],interval[1]);
            }
        }
        return arr;
    }
