/**
    15. 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

Algo: 2 iterators O(N^2) 
- sort
- for i in [0,n-2):
    k = n-1
    while j < k
        sum = a[i] + a[j] + a[k]
        if sum == 0:
            ans <- a[i], a[j], a[k]
            prev = a[j]
            while (j < k && a[j] == prev) ++j
        elif sum > 0:
            --k
        else:
            ++j
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        if (a.size() < 3) return {};
        sort(a.begin(), a.end());
        size_t n = a.size();
        vector<vector<int>> ans;
        ans.reserve(n);
        bool prev_i_set = false;
        int prev_i = 0;
        for (size_t i = 0; i < n-2; ++i) {
            if (prev_i_set && a[i] == prev_i) continue;
            prev_i_set = true;
            prev_i = a[i];
            size_t j = i+1;
            size_t k = n-1;
            while (j < k) {
                int sum = a[i] + a[j] + a[k];
                if (sum == 0) {
                    ans.push_back({a[i], a[j], a[k]});
                    int prev = a[j];
                    while (j < k && a[j] == prev) {
                        ++j;
                    }
                } else if (sum > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
};
