/**
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Algo: naive O(N^2)
max_sum = INT_MIN
for i=0 to n:
  sum = 0
  for l=i to n-i:
    sum += v[l]
    if sum > max_sum:
      max_sum = sum
return max_sum

Algo: dynamic O(N) + O(1)
for every position take max this position or best before + this position
max_sum = INT_MIN or first element
sum  = 0
for i in n:
  sum += i # calc current sum
  if max_sum < sum: max_sum = sum # update max, if needed
  if sum < 0: sum = 0 # if sum < 0 -- better to throw it out
return max_sum

*/

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_sum = nums[0];
        int sum = 0;
        for (auto i : nums) {
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
