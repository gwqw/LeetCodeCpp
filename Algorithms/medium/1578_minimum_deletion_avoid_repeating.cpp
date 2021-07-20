/**
    1578. Minimum Deletion Cost to Avoid Repeating Letters
Given a string s and an array of integers cost where cost[i] is the cost of deleting the ith character in s.
Return the minimum cost of deletions such that there are no two identical letters next to each other.

Notice that you will delete the chosen characters at the same time, in other words, after deleting a character, the costs of deleting other characters will not change.

Example 1:
Input: s = "abaac", cost = [1,2,3,4,5]
Output: 3
Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each other).

Example 2:
Input: s = "abc", cost = [1,2,3]
Output: 0
Explanation: You don't need to delete any character because there are no identical letters next to each other.

Example 3:
Input: s = "aabaa", cost = [1,2,3,4,1]
Output: 2
Explanation: Delete the first and the last character, getting the string ("aba").

Constraints:
s.length == cost.length
1 <= s.length, cost.length <= 10^5
1 <= cost[i] <= 10^4
s contains only lowercase English letters.

Algo: stack
for c in s[i]:
    if not st.empty() and s[st.top()[0]] == c:
        pi = st.top()
        st.pop()
        if not st.empty() and s[st.top()] == c:
            ppi = st.top()
            st.pop()
            cost += min(cost, pcost, ppcost)
            
*/

class Solution {
public:
    int minCost(string_view s, const vector<int>& cost) {
        stack<int> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (!st.empty() && s[st.top()] == s[i]) {
                int pi = st.top();
                if (cost[i] <= cost[pi]) {
                    cnt += cost[i];
                } else {
                    cnt += cost[pi];
                    st.top() = i;
                }
            } else {
                st.push(i);
            }
        }
        return cnt;
    }
};