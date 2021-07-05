/**
    283. Move Zeroes
    
Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Algo:
- have 2 iterators: it1, it2
- it1 at first zero (at place where to insert)
- it2 goes through array and places non-zero values to it1
    - ++it1 after insert
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it = find(nums.begin(), nums.end(), 0);
        if (it == nums.end()) return;
        for (auto jt = next(it); jt < nums.end(); ++jt) {
            if (*jt != 0) {
                swap(*it++, *jt);
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // or stable_partition
        stable_sort(nums.begin(), nums.end(), 
            [](int lhs, int rhs){ return lhs != 0 && rhs == 0;});
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // or stable_partition
        stable_partition(nums.begin(), nums.end(), 
            [](int val){ return val != 0;});
    }
};



