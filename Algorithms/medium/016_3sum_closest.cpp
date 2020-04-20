/**
    16. 3Sum Closest
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Algo: sort and 2 iterators O(N2) + O(1)
- sort nums
- min_diff = INT_MAX
- min_sum = 0
- for every i: 0, n-2:
    - j = i+1
    - k = n-1
    - while (j < k):
        - sum = a[i] + a[j] + a[k]
        - if abs(sum - target) < min_diff:
            min_diff = abs(sum - target)
            min_sum = sum
        - if sum > target:
            --k
        - if sum == target: return sum
        - if sum < target:
            ++j
- return min_sum
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        assert(nums.size() >= 3);
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int min_sum = 0;
        for (size_t i = 0; i+2 < nums.size(); ++i) {
            size_t j = i+1;
            size_t k = nums.size()-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return target;
                if (abs(sum - target) < min_diff) {
                    min_diff = abs(sum - target);
                    min_sum = sum;
                }
                if (sum > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return min_sum;
    }
};