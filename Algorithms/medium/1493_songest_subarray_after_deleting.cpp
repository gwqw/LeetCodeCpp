/**
    1493. Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array.
Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Example 4:
Input: nums = [1,1,0,0,1,1,1,0,1]
Output: 4

Example 5:
Input: nums = [0,0,0]
Output: 0

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.

Algo: dp has 2 sum (with deleting and wo)
- find first 0
- if not found: return nums.size()-1
- ld = zero position
- l0 = 0
- max_length = 0
for el in nums:
    if el == 1:
        ld += 1
        l0 += 1
    else:
        max_length = max(max_length, ld)
        ld = l0
        l0 = 0
return max(max_length, ld)

*/

class Solution {
public:
    int longestSubarray(const vector<int>& nums) {
        auto it = find(nums.begin(), nums.end(), 0);
        if (it == nums.end()) return nums.empty() ? 0 : nums.size()-1;
        int ld = it - nums.begin();
        int l0 = 0;
        int max_length = 0;
        ++it;
        for (; it != nums.end(); ++it) {
            if (*it == 1) {
                ++ld;
                ++l0;
            } else {
                max_length = max(max_length, ld);
                ld = l0;
                l0 = 0;
            }            
        }
        return max(max_length, ld);        
    }
};