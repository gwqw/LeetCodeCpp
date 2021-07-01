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
if a1.last < a2.first or a2.last < a1.first: search in 1 array
a1..an:
l.. r
m = mid;
find j: max a[j] < a[i]
check j + i == (n1+n2) / 2


*/

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& a1, const vector<int>& a2) {
        size_t n1 = a1.size();
        size_t n2 = a2.size();
        if (n1 == 0 or n2 == 0) {
            return simpleMedian(a1, a2);
        }
        if (a1.back() <= a2[0]) {
            return simpleMedian(a1, a2);
        } else if (a2.back() <= a1[0]) {
            return simpleMedian(a2, a1);
        }
        int l = 0;
        int r = n1;
        int hl = (n1+n2)/2;
        while (l+1 < r) {
            int i = (l+r)/2;
            auto it = upper_bound(a2.begin(), a2.end(), a1[i]);
            int j = it - a2.begin();
            --j;
            if (i+j == hl) {
                return calcMedian(a1, a2, i, j-1);
            } else if (i+j < hl) {
                l = i+1;
            } else {
                r = i;
            }
        }
        int i = l;
        int j = hl - i;
        return calcMedian(a1, a2, i, j);
    }
    
private:
    double simpleMedian(const vector<int>& a1, const vector<int>& a2) {
        size_t n1 = a1.size();
        size_t n2 = a2.size();
        int m = (n1+n2) / 2;
        if (m == 0) {
            return n1 != 0 ? a1[0] : a2[0];
        }
        if ((n1 + n2) % 2 == 0) {
            int r = (m >= n1) ? a2[m-n1] : a1[m];
            int l = (m-1 >= n1) ? a2[m-1-n1] : a1[m-1];
            return (l+r) / 2.0;
        } else {
            return (m >= n1) ? a2[m-n1] : a1[m];
        }
    }
    
    double calcMedian(const vector<int>& a1, const vector<int>& a2, int i, int j) {
        size_t n1 = a1.size();
        size_t n2 = a2.size();
        int m = (n1+n2) / 2;
        if ((n1 + n2) % 2 == 0) {
            int r = 0;
            if (i == -1 || i == a1.size()) {
                r = a2[j];
            } else if (j == -1 || j == a2.size()) {
                r = a1[i];
            } else {
                r = min(a1[i], a2[j]);
            }
            int l = 0;
            if (i <= 0) {
                l = a2[j-1];
            } else if (j <= 0) {
                l = a1[i-1];
            } else {
                l = max(a1[i-1], a2[j-1]);
            }
            return (l + r) / 2.0;
        } else {
            if (i == a1.size() || i < 0) return a2[j];
            if (j == a2.size() || j < 0) return a1[i];
            return min(a1[i], a2[j]);
        }
    }
};
