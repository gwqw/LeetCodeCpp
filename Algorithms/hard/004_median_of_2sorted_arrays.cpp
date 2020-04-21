/**
    4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5

Algo: binary_search
- median for merged array will be: 
    - if (n1 + n2) % 2 != 0:
        - m = (n1 + n2) / 2
        - med: a[m]
    - else:
        - m1 = (n1 + n2) / 2
        - m2 = m1-1
        - med: (a[m1] + a[m2]) / 2
        
- edge points:
    - a1[0] > a2[n2-1]
    - a2[0] > a1[n1-1]
    
- binary_select median in a1:
    - m1 = (l + r) / 2
    - a1 left part size is m1
    - a2 left part must be m2 = (n1 + n2) / 2 - m1 - 1
    - if a1[m1] < a2[m2+1] && a2[m2] < a1[m1+1]
    - elif a2[m2] > a[m1+1]:
        - l = m
    - else:
        - r = m
    

*/

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& a1, const vector<int>& a2) {
        size_t n1 = a1.size();
        size_t n2 = a2.size();
        
    }
};
