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

Algo: O(N) + O(1)
- left: find left sorted boundary
- right: find right sorted boundary
- find min,max in middle array
- left -> upper_bound(min) for left
- right -> lower_bound-1(max) for right

Algo2: O(N) + O(N)
- go to the right and saves max values for every number and find last ridx: value < max 
- go to the left and saves min values for every number and find last lidx: value > min
- dist = ridx - lidx + 1

Algo: bad: make pairs [num, idx], stable_sort and find left and right. O(NlogN) + O(N)

*/

class Solution {
public:
    int findUnsortedSubarray(const vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        // find sorted left
        size_t li = 0;
        while (li+1 < nums.size()) {
            if (nums[li] > nums[li+1]) break;
            ++li;
        }
        ++li;
        
        // find sorted right
        size_t ri = nums.size();
        while (ri > 2 && ri > li+1) {
            if (nums[ri-2] > nums[ri-1]) break;
            --ri;
        }
        --ri;
        
        // everything is ok
        if (li > ri) return 0;
        
        // find min,max in middle subarray
        int min_value = li ? min(nums[li-1], nums[ri]) : INT_MAX;
        int max_value = li ? max(nums[li-1], nums[ri]) : nums[ri];
        for (size_t i = li; i < ri; ++i) {
            if (nums[i] > max_value) max_value = nums[i];
            if (nums[i] < min_value) min_value = nums[i];
        }
        
        // find new left and new right
        auto new_left_it = upper_bound(nums.begin(), nums.begin() + li, min_value);
        auto new_right_it = lower_bound(nums.begin()+ ri, nums.end(), max_value);
        
        return distance(new_left_it, new_right_it);
    }
};

class Solution {
public:
    int findUnsortedSubarray(const vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int min_value = INT_MAX, max_value = INT_MIN;
        size_t left_idx = nums.size(), right_idx = 0;
        // go to the right
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > max_value) {
                max_value = nums[i];
            } else if (nums[i] != max_value) {
                right_idx = i;
            }
        }
        if (right_idx == 0) return 0;
        // go to the left
        for (size_t i = nums.size(); i-->0; ) {
            if (nums[i] < min_value) {
                min_value = nums[i];
            } else if (nums[i] != min_value) {
                left_idx = i;
            }
        }
        return right_idx - left_idx + 1;
    }
};


