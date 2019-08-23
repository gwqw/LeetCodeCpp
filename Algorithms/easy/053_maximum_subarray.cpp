/**
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

algo O(N^2)
max_sum = -2147483647
for i=0 to n:
  sum = 0
  for l=i to n-i:
    sum += v[l]
    if sum > max_sum:
      max_sum = sum
return max_sum

algo O(N)
max_sum = -2147483647
sum  = 0
for i in n:
  sum += v[i]
  if max_sum < sum: max_sum = sum
  if sum < 0: sum = 0
return max_sum

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      if (nums.empty()) return 0;
      int max_sum = -2147483647;
      int sum = 0;
      for (int i : nums) {
        sum += i;
        if (sum > max_sum) {
          max_sum = sum;
        }
        if (sum < 0) {
          sum = 0;
        }        
      }
      return max_sum;
    }
};