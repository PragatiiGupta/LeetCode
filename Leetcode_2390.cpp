/**
2390. Removing stars from a string.
You are given a string s, which contains stars *.
In one operation, you can:
Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.
Intuition
As we have to remove the very most left non-star character from current star character, we have to use the LIFO data structure i.e stack to store the non-star characters as the nearest non-star character would at the top of the stack.

Approach
We will push all the non-star characters on the stack and pop out when any star character is found.

Complexity
Time complexity and Space complexity:
O(n)

Code
*/
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(auto i:s) {
            if(i!='*')
                st.push(i);
            else
                st.pop();
        }

        if(st.size() == s.size()) 
            return s;

        string ans="";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
