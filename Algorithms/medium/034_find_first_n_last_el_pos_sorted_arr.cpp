/**
    34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Algo1: use equal_range

Algo2: binary_search
    - lower_bound
    - upper_bound
    - return pair
    lower_bound:
        l = 0, r = a.size()
        while l+1 < r:
            m = l+r/2
            if a[m] < target:
                l = m
            else:
                r = m
        return r
    upper_bound:
        l = 0, r = a.size()
        while l+1 < r:
            m = l+r/2
            if a[m] <= target:
                l = m
            else:
                r = m
        return r
*/

class Solution {
public:
    vector<int> searchRange(const vector<int>& a, int target) {
        auto [b,e] = equal_range(a.begin(), a.end(), target);
        if (b == e) {
            return {-1,-1};
        }
        return {(int)distance(a.begin(), b), (int)distance(a.begin(), prev(e))};
    }
};

class Solution {
public:
    vector<int> searchRange(const vector<int>& a, int target) {
        auto [b,e] = equalRange(a, target);
        if (b == e) {
            return {-1,-1};
        }
        return {(int)b, (int)(e)-1};
    }
    
private:
    static pair<size_t, size_t> equalRange(const vector<int>& a, int target) {
        return {
            lowerBound(a, target),
            upperBound(a, target)
        };
    }
    
    static size_t lowerBound(const vector<int>& a, int target) {
        size_t l = 0;
        size_t r = a.size();
        if (a.empty() || a[0] >= target) return 0;
        while (l+1 < r) {
            size_t m = l + (r-l)/2;
            if (a[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
    
    static size_t upperBound(const vector<int>& a, int target) {
        size_t l = 0;
        size_t r = a.size();
        if (a.empty() || a[0] > target) return 0;
        while (l+1 < r) {
            size_t m = l + (r-l)/2;
            if (a[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
};

/*
[5,7,7,8,8,10]
8
[5,7,7,8,8,10]
6
[5,7,7,8,8,10]
5
[5,7,7,8,8,10]
10
*/

