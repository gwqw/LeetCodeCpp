/**
    977. Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

Algo1: naive O(NlogN)
- square array
- sort array

Algo2: O(N)
split array on a1: negative and a2: positive (non-negative)
square a1 and a2
reverse a2
merge(a1, a2)

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (auto& n : nums) {
            n *= n;
        }
        transform(nums.begin(), nums.end(), [](const auto& v){return v*v;});
        sort(nums.begin(), nums.end());
        return nums;
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        transform(nums.begin(), nums.end(), nums.begin(), [](const auto& v){return v*v;});
        sort(nums.begin(), nums.end());
        return nums;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        auto it = lower_bound(nums.begin(), nums.end(), 0);
        for (auto& n : nums) {
            n *= n;
        }
        reverse(nums.begin(), it);
        vector<int> res;
        res.reserve(nums.size());
        size_t j = 0;
        size_t i = it - nums.begin();
        size_t e = i;
        while (j < e && i < nums.size()) {
            if (nums[j] <= nums[i]) {
                res.push_back(nums[j++]);
            } else {
                res.push_back(nums[i++]);
            }
        }
        for (; j < e; ++j) {
            res.push_back(nums[j]);
        }
        for (; i < nums.size(); ++i) {
            res.push_back(nums[i]);
        }
        return res;
    }
};
