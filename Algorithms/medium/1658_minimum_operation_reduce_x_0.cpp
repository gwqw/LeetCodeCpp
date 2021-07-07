/**
    1658. Minimum Operations to Reduce X to Zero
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
1 <= x <= 10^9

Algo1: back_tracking (TLE)
mv[1] = s[1], s[-1]
mv[2] = s[2], s[1][-1], s[-2]
mv[3] = s[3], s[2][-1], s[1][-2], s[-3]

target_sum(sum, target, ps, ss, cnt):
	if ps+ss >= sums.size():
		return
	if sum == target:
		update(cnt)
		return
	target_sum(sum+sums[ps], target, ps+1, ss, cnt);
	target_sum(sum+sums[ss], target, ps, ss+1, cnt);
	
Algo2: prefix sum and suffix sum and 2 pointers: O(N), O(N)mem
psum
ssum
reverse ssum
for ps in psum:
    find ss in ssum: ps == target
    
Algo3: try 2 pointers wo mem use
*/

class Solution {
public:
    int minOperations(const vector<int>& nums, int x) {
		int cnt = (int)nums.size()+1;
		backtrack(nums, x, 0, 0, 0, cnt);
		return cnt <= nums.size() ? cnt : -1;
    }
	
private:
	void backtrack(const vector<int>& nums, int target, int sum, int l, int r, int& cnt) {
		if (sum == target) {
			cnt = min(cnt, l+r);
			return;
		}
		if (l+r == nums.size() || sum > target) {
			return;
		}
		backtrack(nums, target, sum + nums[l], l+1, r, cnt);
		backtrack(nums, target, sum + nums[nums.size()-r-1], l, r+1, cnt);
	}
};

class Solution {
public:
    int minOperations(const vector<int>& nums, int x) {
		auto prefix_sum = calcPrefixSum(nums);
		auto suffix_sum = calcSuffixSum(nums);
		int n = (int)nums.size();
		size_t j = 0;
		int cnt = nums.size() + 1;
		for (size_t j = 0; j < suffix_sum.size(); ++j) {
		    if (suffix_sum[j] == x) cnt = min(cnt, int(n-j));
		}
		for (size_t i = 0; i < prefix_sum.size(); ++i) {
		    if (prefix_sum[i] == x) {
		        cnt = min(cnt, int(i+1));
		        break;
	        }
		    if (prefix_sum[i] >= x) break;
	        while (j < suffix_sum.size() && suffix_sum[j] + prefix_sum[i] > x) {
	            ++j;
	        }
	        if (j == suffix_sum.size()) continue;
	        if (suffix_sum[j] + prefix_sum[i] == x) {
	            cnt = min(cnt, int(i + n-j-1 + 2));
	        }
		}
		return cnt < nums.size()+1 ? cnt : -1;
    }

private:
    vector<int> calcPrefixSum(const vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            res[i] = res[i-1] + nums[i];
        }
        return res;
    }
    
    vector<int> calcSuffixSum(const vector<int>& nums) {
        vector<int> res(nums.size());
        res.back() = nums.back();
        for (size_t i = nums.size()-1; i-->0; ) {
            res[i] = res[i+1] + nums[i];
        }
        return res;
    }
};

class Solution {
public:
    int minOperations(const vector<int>& nums, int x) {
		auto suffix_sum = calcSuffixSum(nums);
		int n = (int)nums.size();
		size_t j = 0;
		int cnt = nums.size() + 1;
		for (size_t j = 0; j < suffix_sum.size(); ++j) {
		    if (suffix_sum[j] == x) cnt = min(cnt, int(n-j));
		}
		int sum = 0;
		for (size_t i = 0; i < nums.size(); ++i) {
		    sum += nums[i];
		    if (sum == x) {
		        cnt = min(cnt, int(i+1));
		        break;
	        }
		    if (sum >= x) break;
	        while (j < suffix_sum.size() && suffix_sum[j] + sum > x) {
	            ++j;
	        }
	        if (j == suffix_sum.size()) continue;
	        if (suffix_sum[j] + sum == x) {
	            cnt = min(cnt, int(i + n-j-1 + 2));
	        }
		}
		return cnt < nums.size()+1 ? cnt : -1;
    }

private:
    vector<int> calcSuffixSum(const vector<int>& nums) {
        vector<int> res(nums.size());
        res.back() = nums.back();
        for (size_t i = nums.size()-1; i-->0; ) {
            res[i] = res[i+1] + nums[i];
        }
        return res;
    }
};

