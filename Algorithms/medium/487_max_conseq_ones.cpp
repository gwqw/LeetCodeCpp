/**
    487. Max Consecutive Ones II
Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

Example 1:
Input: nums = [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of consecutive 1s is 4.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 4

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.

Follow up: What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?

Algo: O(N), O(1)mem
i = find(nums, 0)
if not found: return nums.size()
l0 = 0
lf = i+1
max_length = 0
for i in (i+1, nums.size()):
    if nums[i] == 1:
        l0++
        lf++
    else:
        max_length = max(max_length, lf)
        lf = l0+1
        l0 = 0
return max(max_length, lf)
        
*/

class Solution {
public:
    int findMaxConsecutiveOnes(const vector<int>& nums) {
        auto it = find(nums.begin(), nums.end(), 0);
        if (it == nums.end()) return nums.size();
        int l0 = 0;
        int lf = int(it - nums.begin())+1;
        int max_length = 0;
        ++it;
        for (; it != nums.end(); ++it) {
            if (*it == 1) {
                ++l0;
                ++lf;
            } else {
                max_length = max(max_length, lf);
                lf = l0 + 1;
                l0 = 0;
            }
        }
        return max(max_length, lf);
    }
};