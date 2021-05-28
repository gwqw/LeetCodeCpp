/**
   55. Jump Game
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5

Algo: dp (solved for prefixes) O(N^2), O(N)
	dp = [steps+1, false]
	for step in nums:
		for j < i:
			if dp[j] and i-j < nums[j]:
				dp[i] = true
				break
	return dp[nums.size()]
*/
 /*
 [3,2,1,0,4]
  1 1 1 1 0
 */
class Solution {
public:
    bool canJump(const vector<int>& nums) {
		if (nums.empty()) return true;
		vector<char> dp(nums.size(), 0);
		dp[0] = 1;
		for (size_t i = 1; i < nums.size(); ++i) {
			for (size_t j = 0; j < i; ++j) {
				if (dp[j] && nums[j] >= i-j) {
					dp[i] = 1;
					break;
				}
			}
		}
		return dp[nums.size()-1] == 1;
    }
};
