/**
    704. Binary Search
Given a sorted (in ascending order) integer array nums of n elements and a target value, 
write a function to search target in nums. 
If target exists, then return its index, otherwise return -1.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

Note:
You may assume that all elements in nums are unique.
n will be in the range [1, 10000].
The value of each element in nums will be in the range [-9999, 9999].

Algo1: use lower_bound O(logN) + O(1)

Algo2: binary serach
- [l,r)
*/

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target) {
            return distance(nums.begin(), it);
        } else {
            return -1;
        }        
    }
};

// use [l, r) range for classic binary search
class Solution {
public:
    int search(const vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0;
        int r = (int)nums.size();
        while (r > l) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return -1;
    }
};

// bin search with predicate
template <typename P>
class Solution {
public:
    int search(const vector<int>& nums, P p) {
        if (nums.empty()) return -1;
        int l = 0;
        int r = (int)nums.size();
        while (r > l) {
            int m = l + (r - l) / 2;
            if (p(nums[m])) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};

