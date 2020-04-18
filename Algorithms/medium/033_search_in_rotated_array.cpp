/**
    33. Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Algo: binary search: O(logN)
a[l] > a[r]
- target can be before or after pivot: before: target > a[l]
0 a[m] == target: return m
1 target before pivot:
    1.1 a[m] < target:
        a[m] - before: l = m
        a[m] - after:  r = m
    1.2 target < a[m]:
        r = m
2 target after pivot:
    2.1 a[m] < target:
        l = m
    2.2 a[m] > target:
        a[m] - before: l = m
        a[m] - after:  r = m
        
  /
 /
/
     /
    /
*/

class Solution {
public:
    int search(const vector<int>& a, int target) {
        if (a.empty()) return -1;
        size_t l = 0;
        size_t r = a.size();
        if (a[l] == target) return l;
        bool target_before = is_before(target, a);
        while (l+1 < r) {
            size_t m = l + (r-l)/2;
            if (a[m] == target) return m;
            if (target_before) {
                if (a[m] < target && is_before(a[m], a)) {
                    l = m;
                } else {
                    r = m;
                }
            } else {
                if (a[m] < target || is_before(a[m], a)) {
                    l = m;
                } else {
                    r = m;
                }
            }
        }
        return a[l] == target ? l : -1;
    }
private:
    static bool is_before(int value, const vector<int>& a) {
        return value >= a[0] || a[0] < a.back();
    }
};

class Solution {
public:
    int search(const vector<int>& a, int target) {
        if (a.empty()) return -1;
        size_t l = 0;
        size_t r = a.size();
        if (a[l] == target) return l;
        bool target_before = is_before(target, a);
        while (l+1 < r) {
            size_t m = l + (r-l)/2;
            if (a[m] == target) return m;
            if (target_before) {
                if (a[m] < target && is_before(a[m], a)) {
                    l = m+1;
                } else {
                    r = m;
                }
            } else {
                if (a[m] < target || is_before(a[m], a)) {
                    l = m+1;
                } else {
                    r = m;
                }
            }
        }
        return l < r && a[l] == target ? l : -1;
    }
private:
    static bool is_before(int value, const vector<int>& a) {
        return value >= a[0] || a[0] < a.back();
    }
};
