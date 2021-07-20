/**
    1918. Kth Smallest Subarray Sum
Given an integer array nums of length n and an integer k, return the kth smallest subarray sum.
A subarray is defined as a non-empty contiguous sequence of elements in an array. A subarray sum is the sum of all elements in the subarray.

Example 1:
Input: nums = [2,1,3], k = 4
Output: 3
Explanation: The subarrays of [2,1,3] are:
- [2] with sum 2
- [1] with sum 1
- [3] with sum 3
- [2,1] with sum 3
- [1,3] with sum 4
- [2,1,3] with sum 6 
Ordering the sums from smallest to largest gives 1, 2, 3, 3, 4, 6. The 4th smallest is 3.

Example 2:
Input: nums = [3,3,5,5], k = 7
Output: 10
Explanation: The subarrays of [3,3,5,5] are:
- [3] with sum 3
- [3] with sum 3
- [5] with sum 5
- [5] with sum 5
- [3,3] with sum 6
- [3,5] with sum 8
- [5,5] with sum 10
- [3,3,5], with sum 11
- [3,5,5] with sum 13
- [3,3,5,5] with sum 16
Ordering the sums from smallest to largest gives 3, 3, 5, 5, 6, 8, 10, 11, 13, 16. The 7th smallest is 10.

Constraints:
n == nums.length
1 <= n <= 2 * 10^4
1 <= nums[i] <= 5 * 10^4
1 <= k <= n * (n + 1) / 2

Algo: binary_search on answer(logK) + sliding window, counting sum <= ans

*/

class Solution {
public:
    int kthSmallestSubarraySum(const vector<int>& nums, int k) {
        int r = sumElements(nums);
        int l = 0;
        while (l+1 < r) {
            int m = l + (r-l)/2;
            int cnt = count(nums, m); // count sums <= m
            if (cnt < k) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
    
private:
    int count(const vector<int>& nums, int max_sum) {
        size_t i = 0;
        size_t j = 0;
        int sum = 0;
        int cnt = 0;
        while (j < nums.size()) {
            sum += nums[j++];
            while (i < j && sum > max_sum) {
                sum -= nums[i++];
            }
            if (i < j) {
                cnt += j - i;
            }
        }
        return cnt;
    }
    
    int sumElements(const vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        return sum;
    }
};