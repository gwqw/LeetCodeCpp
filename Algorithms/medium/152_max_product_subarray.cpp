/**
    152. Maximum Product Subarray
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
It is guaranteed that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

Constraints:
1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Algo1: O(N)
2 prods: positive, negative
if n>0: pos*= n
elif n<0: swap(pos, neg) pos *= n, neg *= n or neg = n
else: pos = 0, neg = 0

Algo2: two-pass O(N)
neg1 [pos] neg2 -> [new_interval]
*/

class Solution {
public:
    int maxProduct(const vector<int>& nums) {
        int max_prod = INT_MIN;
        optional<int> pos_prod;
        optional<int> neg_prod;
        for (auto n : nums) {
            if (n > 0) {
                if (!pos_prod) pos_prod = 1;
                pos_prod = *pos_prod * n;
                if (neg_prod) neg_prod = *neg_prod * n;
            } else if (n < 0) {
                if (pos_prod) max_prod = max(max_prod, *pos_prod);
                if (neg_prod) max_prod = max(max_prod, *neg_prod);
                swap(pos_prod, neg_prod);
                if (pos_prod) pos_prod = *pos_prod * n;
                if (neg_prod) 
                    neg_prod = *neg_prod * n;
                else
                    neg_prod = n;
            } else {
                if (pos_prod) max_prod = max(max_prod, *pos_prod);
                if (neg_prod) max_prod = max(max_prod, *neg_prod);
                max_prod = max(max_prod, 0);
                pos_prod = nullopt;
                neg_prod = nullopt;
            }
        }
        if (pos_prod) max_prod = max(max_prod, *pos_prod);
        if (neg_prod) max_prod = max(max_prod, *neg_prod);
        return max_prod;
    }
};

class Solution {
public:
    int maxProduct(const vector<int>& nums) {
        int prod = nums[0];
        int max_prod = prod;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (prod == 0) 
                prod = nums[i];
            else
                prod *= nums[i];
            max_prod = max(max_prod, prod);
        }
        prod = nums.back();
        max_prod = max(max_prod, prod);
        for (size_t i = nums.size()-1; i-->0; ) {
            if (prod == 0) 
                prod = nums[i];
            else
                prod *= nums[i];
            max_prod = max(max_prod, prod);
        }
        return max_prod;
    }
};
