77. Combinations
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

Explanation:
Function generate:
ans stores all the combinations generated so far.
current stores the current combination being built.
start indicates the current number to be added to the combination.
When the size of current equals k, it is added to ans.
The loop runs from start to n, adding each number to current, recursively calling generate with the next number, and then removing the last number to backtrack.
Function combine:
Initializes the result vector ans and the current combination vector current.
Calls generate starting from 1.
Returns the result containing all combinations.

Time Complexity:
Combinatorial Nature: There are C(n, k) combinations of n items taken k at a time, where C(n, k) = n! / (k! * (n - k)!).
Combination Construction: Each combination requires O(k) time to generate and store in the result.
Total time complexity: O(k * C(n, k))

Space Complexity:
Auxiliary Space (Call Stack): The maximum depth of the recursion tree is O(k).
Result Storage: Storing all combinations requires O(k * C(n, k)) space.
Total space complexity: O(k * C(n, k)) for the result storage plus O(k) for the recursion stack, which is dominated by O(k * C(n, k)).

Code
*/
class Solution {
private:
    void generate(vector<vector<int>>&ans,vector<int>&vec,int n, int k, int st)
    {
        if(vec.size() == k)
        {
            ans.push_back(vec);
            return;
        }
        for(int i=st;i<=n;i++)
        {
            vec.push_back(i);
            generate(ans,vec,n,k,i+1);
            vec.pop_back();
        }
    }    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int> vec;
        generate(ans,vec,n,k,1);
        return ans;
    }
};
