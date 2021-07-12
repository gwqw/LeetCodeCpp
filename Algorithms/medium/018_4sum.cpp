/**
    18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9

Algo: 2 iterators: O(N^3)
sort
for k in [0, n-3):
    for l in [i, n-2):
        target_kl = target - a[k] - a[l]
        i = l+1, j = n-1
        while (i+1 < j) {
            if a[i] + a[j] == target_kl:
                res.push_back(...)
            else if a[i] + a[j] < target_kl:
                ++i
            else:
                --j
        }

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        if (a.size() < 4) return {};
        sort(a.begin(), a.end());
        set<vector<int>> res;
        int n = (int)a.size();
        for (int k = 0; k+3 < n; ++k) {
            for (int l = k+1; l+2 < n; ++l) {
                int target_kl = target - a[k] - a[l];
                int i = l+1;
                int j = a.size()-1;
                while (i < j) {
                    int sum = a[i] + a[j];
                    if (sum == target_kl) {
                        res.insert({a[k],a[l],a[i],a[j]});
                        if ((a[i+1] - a[i]) <= (a[j-1] - a[j])) {
                            ++i;
                        } else {
                            --j;
                        }
                    } else if (sum < target_kl) {
                        ++i;
                    } else {
                        --j;
                    }
                }
            }
        }
        return {res.begin(), res.end()};
    }
};