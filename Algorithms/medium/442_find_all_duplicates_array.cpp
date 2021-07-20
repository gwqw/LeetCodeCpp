/**
    442. Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []

Constraints:
n == nums.length
1 <= n <= 10^5
1 <= nums[i] <= n
Each element in nums appears once or twice.

Algo: radix sort and push to answer nums that cannot be set on its place
n[i] -> n[n[i]]
1 2 3 4 5 6 7 8
1 2 3 4 3 2 7 8
              ^
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& n) {
        vector<int> res;
		res.reserve(n.size()/2);
		// sort
		for (int i = 0; i < (int)n.size(); ++i) {
			int new_idx = n[i]-1;
			while (n[i] != i+1 && n[i] != n[new_idx]) {
			    swap(n[i], n[new_idx]);
			    new_idx = n[i]-1;
			}
		}
		// collect answer
		for (int i = 0; i < (int)n.size(); ++i) {
			if (n[i] != i+1) {
				res.push_back(n[i]);
			}
		}
		return res;
    }
};