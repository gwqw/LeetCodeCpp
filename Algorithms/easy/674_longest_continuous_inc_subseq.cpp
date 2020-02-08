/**
    674. Longest Continuous Increasing Subsequence
Given an unsorted array of integers, 
find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 

Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 

Note: Length of the array will not exceed 10,000.

Algo: simply go through array: O(N) + O(1)
- go through array and check if increasing (save previous)
- if inc: cur++
- else: update max
- update max after the end
*/

class Solution {
public:
    int findLengthOfLCIS(const vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_length = 0;
        int cur_length = 1;
        int prev_value = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > prev_value) {
                ++cur_length;
            } else {
                if (cur_length > max_length) max_length = cur_length;
                cur_length = 1;
            }
            prev_value = nums[i];
        }
        return max(max_length, cur_length);
    }
};

/*
    1 3 5 4 7
            2
    1 2 3 1 2

    1 3 2 1 2 3 4
    1 2 1 1 2 3 4
    
*/
