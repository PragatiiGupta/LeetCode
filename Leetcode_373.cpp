/**
373. Find K pair with smallest sums.
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.Define a pair (u, v) which consists of one element from the first array and one element from the second array.Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Explanation
Min-Heap Initialization:
We use a lambda function as a custom comparator to create a min-heap based on the sum of pairs.
Pushing Initial Pairs:
Push pairs (nums1[i], nums2[0]) for the first k elements from nums1. This ensures that we start with the smallest possible sums.
Extracting and Pushing Pairs:
For each smallest pair extracted from the heap, push the next potential smallest pair (num1, nums2[idx + 1]) if it exists.

Complexity Analysis
Time Complexity:
Building the initial heap takes O(klogk).
Each insertion and extraction operation on the heap takes O(logk).
Total complexity is O(klogk+klogk)=O(klogk), assuming k ≤ m×n.
Space Complexity:
The space complexity is O(k) due to the space used by the priority queue and the output vector.
Code
*/
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;
    auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < nums1.size() && i < k; ++i) {
        pq.emplace(i, 0);
    }
    while (k-- > 0 && !pq.empty()) {
        auto [i, j] = pq.top();
        pq.pop();
        ans.push_back({nums1[i], nums2[j]});
        if (j + 1 < nums2.size()) {
            pq.emplace(i, j + 1);
        }
    }
    return ans;
    }
