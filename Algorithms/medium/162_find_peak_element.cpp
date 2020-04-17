/**
    162. Find Peak Element
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Note:
Your solution should be in logarithmic complexity.

Algo:
- [] -> 0
- [1] -> 1
- [1,2] -> max
- [1 2 3 7 5 6]

- check if a[l] > a[l+1]: return a[l]
- l -- r: peak is into
    - m = (l+r)/2
    - check if a[l] > a[l+1]: return a[l]
    - l -- r: peak is into
    - m = (l+r)/2
    - m: l+1<r
        if a[m] < a[m+1]:
            l <- m+1
        if a[m] > a[m+1]:
            r <- m

*/

class Solution {
public:
    int findPeakElement(const vector<int>& a) {
        assert(!a.empty());
        if (a.size() == 1) return 0;
        size_t l = 0;
        size_t r = a.size();
        if (a[l] > a[l+1]) return l;
        while (l+1 < r) {
            size_t m = l + (r-l)/2;
            if (a[m-1] < a[m]) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};

