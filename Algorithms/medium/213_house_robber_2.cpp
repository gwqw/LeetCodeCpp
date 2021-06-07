/**
    213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [0]
Output: 0

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 1000

Algo: dp: max rob from prefix: O(N), O(N)mem (can be O(1))
cnt[idx] -> rob_cnt
cnt1, cnt2: (cnt2 does not use a[0])
cnt1[0] = a[0]
cnt2[0] = 0
cnt[i] = max(cnt[i-2] + a[i], cnt[i-1]) for 1,2
last = max(cnt2[i-2] + a[i], cnt1[i-1]) for 1,2
*/

class Solution {
public:
    int rob(const vector<int>& a) {
        if (a.empty()) return 0;
        //if (a.size() <= 3) return max(a.begin(), a.end());
        vector<int> cnt1(a.size()), cnt2(a.size());
        cnt1[0] = a[0];
        cnt2[0] = 0;
        for (size_t i = 1; i < a.size(); ++i) {
            if (i+1 != a.size()) {
                {
                    int pp = i > 1 ? cnt1[i-2] : 0;
                    cnt1[i] = max(pp + a[i], cnt1[i-1]);
                }
                {
                    int pp = i > 1 ? cnt2[i-2] : 0;
                    cnt2[i] = max(pp + a[i], cnt2[i-1]);
                }
            } else {
                int pp = i > 1 ? cnt2[i-2] : 0;
                cnt1[i] = max(pp + a[i], cnt1[i-1]);
            }
        }
        return cnt1.back();
    }
};

