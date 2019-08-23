/**
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0

Example 5:
Input: [], 4
Output: 0

algo:
	binary search 
	l, r
	while l != r:
		m = (r - l) / 2
		if c == v[m]:
			return m
		elif c < v[m]:
			r = m
		else:
			l = m
	return l	
*/

/*
// STL solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - begin(nums);
    }
};
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		// for test [1,3,5,6], target = 5, 2, 7, 0
		/// STL solution
		// return lower_bound(nums.begin(), nums.end(), target) - begin(nums);
		/// Binary search		
		/*
		int left = 0;
		int right = nums.size() - 1;
		while (left != right) {
			int mid = left + (right - left) / 2;
			if (target == nums[mid]) {
				return mid;
			} else if (target < nums[mid]) {
				right = mid;
			} else {
				left = mid+1;
			}
		}
		return left;
		*/
		/// O(N) search
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == target || target < nums[i]) {
				return i;
			}
		}
		return nums.size();
    }
};

