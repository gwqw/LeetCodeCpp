/**
    238. Product of Array Except Self
Given an array nums of n integers where n > 1, 
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix 
or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? 
(The output array does not count as extra space for the purpose of space complexity analysis.)

Algo1: O(N) + O(N)
- go through array and make integral products -- prefixes
- go through array back and make inv. integral products -- suffixes
- for each element: i find pref[i-1] and suff[i+1] and product them

Algo2: O(N) + O(1)
- multiply prefix and suffix directly to result
*/

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        size_t n = nums.size();
        vector<int> pref(n, 1), suff(n, 1);
        
        for (size_t i = 1; i < n; ++i) {
            pref[i] = pref[i-1] * nums[i-1];
        }
        for (size_t i = n-1; i-->0; ) {
            suff[i] = suff[i+1] * nums[i+1];
        }
        vector<int> res(n);
        for (size_t i = 0; i < n; ++i) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        size_t n = nums.size();
        vector<int> res(n, 1);
        
        for (size_t i = 1; i < n; ++i) {
            res[i] = res[i-1] * nums[i-1];
        }
        size_t suff = 1;
        for (size_t i = n-1; i-->0; ) {
            suff *= nums[i+1];
            res[i] *= suff;            
        }
        return res;
    }
};