/**
    665. Non-decreasing Array
Given an array with n integers, your task is to check if it could become 
non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.

Note: The n belongs to [1, 10,000]. 

Algo: O(N) + O(1)
    we have 2 situation
    1) /U/ grow, one decay and next grow
    2) /n/ grow, one rise and nex grow
    3 elements (p, c, n) pattern: 
        0: p <= c <= n: norm                               /
        1: p > c < n: we need to make c = p: p <= c ? n /|_|     _  /
        2: p < c > n: if nn >= n else try next variant          | |/
    go through array and save prev, cur, next                  /
    is_one = false
    if prev <=cur<=next: continue
    else:
        if next < prev: return false
        if is_one: return false
        is_one = true
    return true
    
Algo2: 2 itterators (from left and from right): O(N) + O(1)
- find li -- index, where ends sorted sequence from the left
- find ri -- index, where ends sorted sequence from the right
- if li+1 == nums.size: return true
- if li+1 != ri: return false
- return true if remove this element: sequence will be sorted: 
    - li > 0 and nums[li-1] <= nums[ri] or
    - ri +1 != nums.size() and nums[li] <= nums[ri+1]

*/

class Solution {
public:
    bool checkPossibility(const vector<int>& nums) {
        if (nums.size() < 3) return true;
        // check first two nums case
        int p;
        int c;
        int n, nn;
        bool was_one = false;
        if (nums[0] > nums[1]) {
            was_one = true;
            nums[0] = nums[1];
        } 
        // check other (we consider left side is correct)
        for (int i = 0; i+2 < nums.size(); ++i) {
            p = nums[i];
            c = nums[i+1];
            n = nums[i+2];
            if (p <= c && c <= n) continue;
            if (was_one) return false;
            was_one = true;
            if (i+3 == nums.size()) return true;
            nn = nums[i+3];
            // n < c
            if (nn < c) nums[i+1] = p; // n scenario
            else nums[i+2] = c;            
        }
        return true;
    }
};

class Solution {
public:
    bool checkPossibility(const vector<int>& nums) {
        if (nums.size() <= 2) return true;
        size_t li = 0;
        for (; li+1 < nums.size(); ++li) {
            if (nums[li] > nums[li+1]) break;
        }
        if (li+1 == nums.size()) return true;
        size_t ri = nums.size();
        for (; ri-- - 1 > 0; ) {
            if (nums[ri] < nums[ri-1]) break;
        }
        if (li + 1 != ri) return false;
        return (li == 0 || nums[li-1] <= nums[ri]) ||
               (ri+1 == nums.size() || nums[li] <= nums[ri+1]);
    }
};