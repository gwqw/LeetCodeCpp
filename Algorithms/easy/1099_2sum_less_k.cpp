/**
    1099. Two Sum Less Than K
Given an array nums of integers and integer k, return the maximum sum such that there exists i < j with nums[i] + nums[j] = sum and sum < k. If no i, j exist satisfying this equation, return -1.

Example 1:
Input: nums = [34,23,1,24,75,33,54,8], k = 60
Output: 58
Explanation: We can use 34 and 24 to sum 58 which is less than 60.

Example 2:
Input: nums = [10,20,30], k = 15
Output: -1
Explanation: In this case it is not possible to get a pair sum less that 15.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 1000
1 <= k <= 2000

Algo1: lower_bound in prev nums. O(NlogN)
sort(nums)
for n in nums:
    if nums[i] > k: break
    auto jt = lower_bound(nums.begin(), nums.begin() + i, k - nums[i])
    if jt != nums.begin():
        --jt
        max_sum = max(max_sum, *jt + nums[i])
    return max_sum
    
Algo2: 2 iterators. O(NlogN)
sort(nums)
i = 0, j = nums.size()-1
sum = nums[i] + nums[j]
max_sum = sum < k ? sum : -1
while i < j:
    if sum > k:
        --j
    else:
        ++i
    sum = nums[i] + nums[j]
    if sum < k: max_sum = max(max_sum, sum)
return max_sum
*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max_sum = -1;
        for (size_t i = 0; i < nums.size() && nums[i] < k; ++i) {
            int n = nums[i];
            auto it = lower_bound(nums.begin(), nums.begin()+i, k - n);
            if (it != nums.begin()) {
                --it;
                max_sum = max(max_sum, *it + n);
            }
        }
        return max_sum;
    }
};

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = (int)nums.size()-1;
        int sum = nums[i] + nums[j];
        int max_sum = sum < k ? sum : -1;
        while (i+1 < j) {
            if (sum >= k) {
                --j;
            } else {
                ++i;
            }
            sum = nums[i] + nums[j];
            if (sum < k) {
                max_sum = max(max_sum, sum);
            }
        }
        return max_sum;
    }
};
