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
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Algo0: brute-force: O(N^2), O(1)mem

Algo1: sliding window or 2pointers(???), O(N), O(1) mem
max_prod = 0
pos_prod = 0
neg_prod = 0
for n in nums:
	if n > 0:
		if not pos_prod:
			pos_prod = 1
		pos_prod *= n
        if neg_prod:
			neg_prod *= n		
	elif n < 0:
        update(max, pos_prod, neg_prod)
		if neg_prod:
			pos_prod = neg_prod * n
        if pos_prod:
            neg_prod = pos_prod * n
        else: 
            neg_prod = n
	else:
		update(max, 0, pos_prod, neg_prod)
		cur_prod = nullopt
		neg_prod = nullopt
update(max_prod, pos_prod, all_prod)
return max_prod
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

/*

*/