/**
    334. Increasing Triplet Subsequence
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:
Input: [1,2,3,4,5]
Output: true

Example 2:
Input: [5,4,3,2,1]
Output: false

Algo: like search 3 min elements
- i_value = INT_MAX
- j_valu = INT_MAX
- for n in nums:
    if n < i_value: 
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i_val = INT_MAX;
        int j_val = INT_MAX;
        for (auto n : nums) {
            if (n <= i_val) {
                i_val = n;
            } else if (n <= j_val) {
                j_val = n;
            } else if (n > j_val) {
                return true;
            }
        }
        return false;
    }
};
