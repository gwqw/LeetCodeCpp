/**
    368. Largest Divisible Subset
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
All the integers in nums are unique.

Algo: dp: O(N^2)
max_cnt
prefix: idx->cnt
for n1 in nums:
	cnt = 1
	for n2 in [0,n1):
		if n2 % n1 == 0:
			cnt = max(cnt, pref[n1])
	update(max_cnt)
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.empty()) return {};
		sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size());
		dp[0] = {nums[0]};
		size_t max_i = 0;
		size_t max_size = 0;
		for (size_t i = 1; i < nums.size(); ++i) {
			size_t cur_len = 0;
			size_t max_j = 0;
			bool j_found = false;
			for (size_t j = 0; j < i; ++j) {
				if (nums[i] % nums[j] == 0 && dp[j].size()+1 > cur_len) {
					cur_len = dp[j].size()+1;
					max_j = j;
					j_found = true;
				}
			}
			if (j_found) {
			    dp[i] = dp[max_j];
			    dp[i].push_back(nums[i]);
			} else {
			    dp[i].push_back(nums[i]);
			}
			if (dp[i].size() > max_size) {
				max_size = dp[i].size();
				max_i = i;
			}
		}
		return dp[max_i];
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.empty()) return {};
		sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> max_idx(nums.size(), -1);
		dp[0] = 1;
		max_idx[0] = -1;
		int max_i = 0;
		size_t max_size = 0;		
		// fill dp
		for (size_t i = 1; i < nums.size(); ++i) {
			for (size_t j = 0; j < i; ++j) {
				if (nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]) {
					dp[i] = dp[j]+1;
					max_idx[i] = j;
				}
			}
			if (dp[i] > max_size) {
				max_size = dp[i];
				max_i = i;
			}
        }
		// fill res
		vector<int> res;
		res.reserve(max_size);
        int cur_idx = max_i;
		for (int i = max_i; i != -1; i = max_idx[i]) {
		    res.push_back(nums[i]);
		}
		return res;
    }
};
