/**
    287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

Example 1:
Input: [1,3,4,2,2]
Output: 2

Example 2:
Input: [3,1,3,4,2]
Output: 3

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

Algo1: divide and conqueer (binary_search) O(NlogN) + O(1)
values are 1..N
- l = 1, r = N
- while l<r:
    - n = r-l+1
    - if n % 2 != 0:
        check r is duplicate:
            return r
        else:
            r = r-1
    - m = n/2
    - count nums in l..l+m as c:
        if c > n/2:
            r = l+m
        else:
            l = l+m+1

Algo2: Floyd cycle detection
tortoise and hare
- tortoise = f(0)
- hare = f(f(0))
- while tortoise != hare:
    - tortoise = f(tortoise)
    - hare = f(f(hare))
# find point
- mu = 0
- tortoise = 0
- while tortoise != hare:
    - tortoise = f(tortoise)
    - hare = f(hare)
    - ++mu
*/

class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        size_t l = 1;
        size_t r = nums.size()-1;
        while (l < r) {
            size_t n = r - l + 1;
            if (n % 2 != 0) {
                if (isDuplicate(r, nums)) {
                    return r;
                } else {
                    --r;
                }
            }
            if (l == r) return l;
            size_t m = n / 2;
            size_t c = countNums(l, l+m, nums);
            if (c > m) {
                r = l+m-1;
            } else {
                l = l+m;
            }
        }
        assert(l == r);
        return l;
    }
private:
    static bool isDuplicate(int n, const vector<int>& nums) {
        int count = 0;
        for (auto e : nums) {
            if (e == n) {
                if (++count > 1) return true;
            }
        }
        return false;
    }
    
    size_t countNums(int from, int to, const vector<int>& nums) {
        size_t count = 0;
        for (auto e : nums) {
            if (from <= e && e < to) {
                ++count;
            }
        }
        return count;
    }
};


class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        auto tort = step(nums.begin(), nums);
        auto hare = double_step(nums.begin(), nums);
        while (hare != tort) {
            tort = step(tort, nums);
            hare = double_step(hare, nums);
        }
        
        tort = nums.begin();
        while (hare != tort) {
            tort = step(tort, nums);
            hare = step(hare, nums);
        }
        return distance(nums.begin(), tort);
    }
    
private:
    vector<int>::const_iterator step(const vector<int>::const_iterator it, const vector<int>& nums) {
        auto st = *it;
        auto res = nums.begin() + st;
        return res;
    }
    vector<int>::const_iterator double_step(const vector<int>::const_iterator it, const vector<int>& nums) {
        auto st = *it;
        auto res = nums.begin() + st;
        st = *res;
        res = nums.begin() + st;
        return res;
    }
};
