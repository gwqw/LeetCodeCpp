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
        auto it_ins = nums.begin();
        while (it_ins != nums.end() && *it_ins != 0) {
            ++it_ins;
        }
        if (it_ins == nums.end()) return;
        auto it_fwd = next(it_ins);
        for (;it_fwd != nums.end(); ++it_fwd) {
            if (*it_fwd != 0) {
                swap(*it_ins++, *it_fwd);
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


