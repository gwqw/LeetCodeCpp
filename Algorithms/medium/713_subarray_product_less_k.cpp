/**
    713. Subarray Product Less Than K
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0

Constraints:
1 <= nums.length <= 3 * 10^4
1 <= nums[i] <= 1000
0 <= k <= 10^6

Algo: sliding window && count ending in i
sliding_window: s,e 
if prod < k:
    cnt += e-s+1
    ++e
else:
    ++s
*/

class Solution {
public:
    int numSubarrayProductLessThanK(const vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        size_t s = 0, e = 0;
        uint64_t prod = nums[e];
        int cnt = prod < k ? 1 : 0;
        while (e+1 < nums.size()) {
            prod *= nums[++e];
            while (s <= e && prod >= k) {
                prod /= nums[s++];
            }
            if (prod < k) {
                cnt += e - s + 1;
            }
        }
        return cnt;
    }
};