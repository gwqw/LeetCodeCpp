/**
    581. Shortest Unsorted Continuous Subarray
Given an integer array, you need to find one continuous subarray 
that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

exp:
  _
 / \/
/ 

Algo:
- left: find left sorted boundary
- right: find right sorted boundary
- find min,max in middle array
- left -> upper_bound(min) for lef
- right -> lower_bound-1(max) for right


*/

class Solution {
public:
    int findUnsortedSubarray(const vector<int>& nums) {
        if (nums.empty()) return 0;
        
        size_t li = 0;
        while (li+1 < nums.size()) {
            if (nums[li] > nums[li+1]) break;
            ++li;
        }
        
        size_t ri = nums.size();
        while (ri > 2) {
            if (nums[ri-2] > nums[ri-1]) break;
            --ri;
        }
        
        if (li+1 >= ri) return 0;
        
        
    }
};
