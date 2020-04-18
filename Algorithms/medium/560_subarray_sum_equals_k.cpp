/**
    560. Subarray Sum Equals K
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

Algo: prefix sum + set
- counter = 0
- go through array and calc prefix sum
- if prefix == target: ++counter
- if sum - target in map:
    counter += map[sum-target]
- add sum to map
*/

class Solution {
public:
    int subarraySum(const vector<int>& nums, int target) {
        unordered_map<int, int> m;
        size_t sum = 0;
        int cnt = 0;
        for (auto n : nums) {
            sum += n;
            if (target == sum) {
                ++cnt;
            }
            if (m.count(sum - target)) {
                cnt += m[sum - target];
            }
            ++m[sum];
        }
        return cnt;
    }
};