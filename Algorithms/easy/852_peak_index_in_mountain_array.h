/**
    852. Peak Index in a Mountain Array

Let's call an array A a mountain if the following properties hold:
A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:
Input: [0,1,0]
Output: 1

Example 2:
Input: [0,2,1,0]
Output: 1

Note:
3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.

Algo: naive O(N) + O(1)
- go through array
- if value < prev: prev_idx is mountain

Algo: binary_search O(logN) + O(1)
- l = 0, r = n-1 (l is BEFORE peak and r is AFTER peak)
- check if l and r and boundaries isn't needed
- while l < m:
    - calc m = l + (r-l)/2
    - if a[m-1] < a[m] > a[m+1]: peak is found
    - elif a[m] < a[m+1] -> l = m
    - else: r = m
*/

#pragma once

class Solution {
public:
    int peakIndexInMountainArray(const vector<int>& a) {
        int prev = a[0];
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] < prev) return i-1;
            prev = a[i];
        }
        return a.size()-1;
    }
};


class Solution {
public:
    int peakIndexInMountainArray(const vector<int>& a) {
        int l = 0;
        int r = int(a.size()) - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (a[m-1] < a[m] && a[m] > a[m+1]) {
                return m;
            } else if (a[m] < a[m+1]) {
                l = m;
            } else {
                r = m;
            }
        }
    }
};




