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
bool compare(const pair<int,int>& a,const pair<int,int>& b)
{
    return a.second < b.second;
}

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        vector<pair<int,int>> p;

        for(int i = 0; i < arr.size(); i++)
        {
            if(m.find(arr[i]) != m.end())
                m[arr[i]] += 1;
            else
                m[arr[i]] = 1;
        }
        
        for(const auto& kvp : m)
        {
            p.push_back(kvp);
        }
        
        sort(p.begin(), p.end(), compare);
        
        int removed = 0; // Number of elements removed so far
        for(const auto& pair : p)
        {
            if(k >= pair.second){
                k -= pair.second;
                removed++;
            }
            else
            {
                break;
            }
        }
        
        return p.size() - removed;
    }
};

/*
Optimized code using priority queue.

# Intuition
The problem requires finding the minimum number of unique integers after removing at most k elements from the array.

# Approach
1. Count the frequency of each element using an unordered map.
2. Push the frequencies into a min-heap (priority queue).
3. Iterate through the heap until k becomes less than the current minimum frequency. Pop the minimum frequency and subtract it from k.
4. Return the size of the heap, which represents the number of unique integers left.

# Complexity
- Time complexity: O(n log n) // where n is the size of the input array. Building the frequency map takes O(n) time, and pushing elements into the priority queue takes O(n log n) time.
- Space complexity: O(n) // Space is used to store the frequency map and the priority queue.
  */

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i : arr)
        {
            m[i]++;
        }
        priority_queue<int, vector<int>,greater<int>> pq;
        for(auto& [num,count] : m)
        {
            pq.push(count);
        }
        while(k >= pq.top() && !pq.empty())
        {
            int minFreq = pq.top();
            pq.pop();
            k -= minFreq; // Subtract the minimum frequency from k
        }
        return pq.size();
    }
};
