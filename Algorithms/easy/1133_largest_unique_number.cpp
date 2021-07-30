/**
    1133. Largest Unique Number
Given an array of integers nums, return the largest integer that only occurs once.
If no integer occurs once, return -1.

Example 1:
Input: nums = [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: 
The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it's the answer.

Example 2:
Input: nums = [9,9,8,8]
Output: -1
Explanation: 
There is no number that occurs only once.

Note:
1 <= nums.length <= 2000
0 <= nums[i] <= 1000

Algo1: use map

Algo2: use sort
*/

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
		int prev = nums[0];
		int cnt = 1;
		for (size_t i = 1; i < nums.size(); ++i) {
			if (nums[i] == prev) {
				++cnt;
			} else {
				if (cnt == 1) return prev;
				prev = nums[i];
				cnt = 1;
			}
		}
		return cnt == 1 ? prev : -1;
    }
};