/**
    45. Jump Game II
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 1000

Algo1: bf recursion with memo: O(N^2)
c = last_pos
min_jump = INT_MAX
for i in 0, c:
	if i+nums[i] >= c:
		min_jump = min(min_jump, jump(i))
return min_jump

Algo2: O(N^2), O(N)mem
	dp[i] ->cnt
	
Algo3: greedy: find next max_jump and jump: O(N), O(1)mem
cur_idx = 0
to_idx = nums[0]
while to_idx+1 < nums.size():
	max_idx = to_idx
	for i = cur_idx to to_idx:
		max_idx = max(max_dix, i + nums[i])
	++cnt
	cur_idx = to_idx+1
	to_idx = max_idx

*/

class Solution {
public:
    int jump(const vector<int>& nums) {
        if (nums.size() == 1) return 0;
		vector<int> memo(nums.size(), -1);
		return jump(nums, nums.size()-1, memo);
    }
	
private:
	int jump(const vector<int>& nums, int to, vector<int>& memo) {
        if (to == 0) return 0;
		if (memo[to] != -1) return memo[to];
		int min_jump = INT_MAX;
		for (int i = 0; i < to; ++i) {
			if (i + nums[i] >= to) {
				min_jump = min(min_jump, jump(nums, i, memo)+1);
			}
		}
		memo[to] = min_jump;
		return min_jump;
	}
};

class Solution {
public:
    int jump(const vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
		dp[0] = 0;
		for (size_t i = 1; i < nums.size(); ++i) {
			for (size_t j = 0; j < i; ++j) {
				if (j + nums[j] >= i) {
					dp[i] = min(dp[i], dp[j]+1);
				}
			}
		}
		return dp.back();
    }	
};

/*
cur_idx = 0
to_idx = nums[0]
while to_idx+1 < nums.size():
	max_idx = to_idx
	for i = cur_idx to to_idx:
		max_idx = max(max_idx, i + nums[i])
	++cnt
	cur_idx = to_idx+1
	to_idx = max_idx

*/

class Solution {
public:
    int jump(const vector<int>& nums) {
        if (nums.size() == 1) return 0;
		int cur_idx = 0;
		int to_idx = nums[0];
		int cnt = 1;
		while (to_idx+1 < nums.size()) {
			int max_idx = to_idx;
			for (int i = cur_idx; i <= to_idx; ++i) {
				max_idx = max(max_idx, i + nums[i]);
			}
			++cnt;
			cur_idx = to_idx+1;
			to_idx = max_idx;
		}
		return cnt;
    }	
};