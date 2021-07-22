/**
    525. Contiguous Array
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.

Algo1: prefix count: O(N^2)
cnt1[i] = 1 cnt, cnt0 == 0 cnt
for j in 0,i:
	cnt[i,j] = cnt[i] - cnt[j-1]
	if cnt0[i,j] == cnt1[i,j]: len = i - j

Algo: prefix diff count
cnt[i] = cnt1 - cnt0
dict[cnt_diff]->idx
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> dict;
		int cnt = 0;
		int max_len = 0;
		for (int i = 0; i < (int)nums.size(); ++i) {
			cnt += nums[i] == 1 ? 1 : -1;
			if (cnt == 0) {
				max_len = max(max_len, i+1);
			}
			if (dict.count(cnt)) {
				int j = dict[cnt];
				max_len = max(max_len, i - j);
			} else {
				dict[cnt] = i;
			}
		}
		return max_len;
    }
};