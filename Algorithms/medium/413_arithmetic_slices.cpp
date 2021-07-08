/**
    413. Arithmetic Slices
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

Example 1:
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Example 2:
Input: nums = [1]
Output: 0

Constraints:
1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000

Algo: 
- go to diff
1 2 3 4
  1 1 1
- count subarray of 2 or more equal elements:
- count length-1 of equal subsequent elements
1 1 1 1
0 1 2 3
- sum lengths
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
		// diff
		vector<int> diff(nums.size()-1);
		for (size_t i = 1; i < nums.size(); ++i) {
			diff[i-1] = nums[i] - nums[i-1];
		}
		// count same nums
		vector<int> lengths(diff.size());
		int cur_num = diff[0];
		for (size_t i = 1; i < diff.size(); ++i) {
			if (cur_num == diff[i]) {
				lengths[i] = lengths[i-1]+1;
			} else {
				cur_num = diff[i];
			}
		}
		// sum
		int ans = 0;
		for (auto n : lengths) {
			ans += n;
		}
		return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
		// diff
		vector<int> diff(nums.size()-1);
		for (size_t i = 1; i < nums.size(); ++i) {
			diff[i-1] = nums[i] - nums[i-1];
		}
		// count same nums
		vector<int> lengths(diff.size());
		int cur_num = diff[0];
		int cur_length = 0;
		int ans = 0;
		for (size_t i = 1; i < diff.size(); ++i) {
			if (cur_num == diff[i]) {
				lengths[i] = lengths[i-1]+1;
			} else {
				cur_num = diff[i];
			}
			ans += lengths[i];
		}
		return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
		vector<int> lengths(nums.size()-1);
		int cur_num = nums[1] - nums[0];
		int ans = 0;
		for (size_t i = 1; i+1 < nums.size(); ++i) {
			int diff = nums[i+1] - nums[i];
			if (cur_num == diff) {
				lengths[i] = lengths[i-1]+1;
			} else {
				cur_num = diff;
			}
			ans += lengths[i];
		}
		return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
		int cur_num = nums[1] - nums[0];
		int cur_length = 0;
		int ans = 0;
		for (size_t i = 1; i+1 < nums.size(); ++i) {
			int diff = nums[i+1] - nums[i];
			if (cur_num == diff) {
				cur_length++;
			} else {
				cur_num = diff;
				cur_length = 0;
			}
			ans += cur_length;
		}
		return ans;
    }
};