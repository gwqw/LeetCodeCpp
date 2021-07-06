/**
    4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:
Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:
Input: nums1 = [2], nums2 = []
Output: 2.00000

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6

Algo: binary_search
binary search in small:
    in second position = k - m, where k -- position in unified sorted array

*/

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& a, const vector<int>& b) {
        if (a.size() > b.size()) {findMedianSortedArrays(b, a);}
        size_t an = a.size();
        size_t bn = b.size();
        size_t k = (an + bn - 1) / 2;
        size_t l = 0;
        size_t r = min(an, k);
        while (l < r) {
            size_t m1 = l + (r - l) / 2;
            size_t m2 = k - m1;
            if (a[m1] < b[m2]) {
                l = m1+1;
            } else {
                r = m1;
            }
        }
        
        // median is between a[l-1], a[l], b[k-l], b[k-l+1]
        int al1 = l > 0 && l < an+1 ? a[l-1] : INT_MIN;
        int bkl = k >= l && k < bn+l ? b[k-l] : INT_MIN;
        int al = l >= 0 && l < an ? a[l] : INT_MAX;
        int bkl1 = k+1 >= l && k+1 < bn+l ? b[k-l+1] : INT_MAX;
        // if n % 2 == 1: max(a[l-1], b[k-l])
        if ((an+bn) % 2 == 1) {
            return max(al1, bkl);
        } else {
        // if even max(a[l-1], b[k-l]) and min(a[l], b[k-l+1])
            return double(max(al1, bkl) + min(al, bkl1)) / 2.0;
        }
    }
};
