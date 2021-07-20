/**
    1060. Missing Element in Sorted Array
Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, return the kth missing number starting from the leftmost number of the array.

Example 1:
Input: nums = [4,7,9,10], k = 1
Output: 5
Explanation: The first missing number is 5.

Example 2:
Input: nums = [4,7,9,10], k = 3
Output: 8
Explanation: The missing numbers are [5,6,8,...], hence the third missing number is 8.

Example 3:
Input: nums = [1,2,4], k = 3
Output: 6
Explanation: The missing numbers are [3,5,6,7,...], hence the third missing number is 6.

Constraints:
1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^7
nums is sorted in ascending order, and all the elements are unique.
1 <= k <= 10^8

Follow up: Can you find a logarithmic time complexity (i.e., O(log(n))) solution?

Algo: bin_search
n[i]: missing_cnt = n[i] - n[0] - (i-1) for i > 0

*/

class Solution {
public:
    int missingElement(vector<int>& n, int k) {
        int l = 0;
        int r = n.size();
        while (l+1 < r) {
            int m = l + (r-l)/2;
            int mcount = (n[m] - n[0] - 1) - (m-1);
            if (mcount < k) {
                l = m;
            } else {
                r = m;
            }
        }
        int lcount = l != 0 ? (n[l] - n[0] - 1) - (l-1) : 0;
        return n[l] + k - lcount;
    }
};