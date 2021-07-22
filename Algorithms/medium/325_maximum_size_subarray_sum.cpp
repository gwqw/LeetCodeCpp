/**
    325. Maximum Size Subarray Sum Equals k
Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.

Example 2:
Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.

Constraints:
1 <= nums.length <= 2 * 10^5
-104 <= nums[i] <= 10^4
-10^9 <= k <= 10^9

Algo: prefix sum
prefix_sum: ps
dict[n]->idx
max_len
for i,n in nums:
    if pi == k:
        max_len = max(max_len, i+1)
    else if pi - k in dict:
        max_len = max(max_len, i - d[pi-k])
    if pi not in d:
        d[ppi] = i
return max_len
*/

class Solution {
public:
    int maxSubArrayLen(const vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> dict;
        int max_len = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) {
                max_len = max(max_len, i+1);
            } else if (dict.count(sum-k)) {
                max_len = max(max_len, i - dict[sum-k]);
            }
            if (!dict.count(sum)) {
                dict[sum] = i;
            }
        }
        return max_len;
    }
};