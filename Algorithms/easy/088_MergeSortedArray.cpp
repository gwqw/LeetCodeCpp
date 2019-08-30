/**
     88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]

Algo: O(N), O(1)
shift num1 on n to left
i, j, k = 0, 0, 0
for k in range(n+m):
    if nums1[i] <= nums2[j]:
        nums1[k] = nums1[i]
        i++
    else:
        nums1[k] = nums2[j]
        j++
    if j == n: break
    
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        // shift
        for (int i = m-1; i >= 0; --i) {
            nums1[i+n] = nums1[i];
        }
        // filling part
        int i = n, j = 0, k = 0;
        for (int k = 0; k < n+m; ++k) {
            if (i < m+n && nums1[i] <= nums2[j]) {
                nums1[k] = nums1[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            if (j == n) break;
        }        
    }
};
