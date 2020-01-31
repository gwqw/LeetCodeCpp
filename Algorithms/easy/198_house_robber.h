/**
    198. House Robber
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
             
1 8 9 7 2

Algo: dynamic: O(N) + O(N)
- make vector with max(prev_max, cur + prev_prev_max)

Algo: the same + save memory: O(N) + O(1)
- save prev and prev_prev
*/

class Solution {
public:
    int rob(const vector<int>& n) {
        if (n.empty()) return 0;
        if (n.size() == 1) return n[0];
        vector<int> m(n.size(), 0);
        m[0] = n[0];
        m[1] = max(n[0], n[1]);
        for (size_t i = 2; i < n.size(); ++i) {
            m[i] = max(m[i-1], m[i-2] + n[i]);
        }
        return m.back();
    }
};

class Solution {
public:
    int rob(const vector<int>& n) {
        if (n.empty()) return 0;
        if (n.size() == 1) return n[0];
        int pp = n[0];
        int p = max(n[0], n[1]);
        for (size_t i = 2; i < n.size(); ++i) {
            int mx = max(p, pp + n[i]);
            pp = p;
            p = mx;
        }
        return p;
    }
};
