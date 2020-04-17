/**
    78. Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Algo: recursive: rec(nums, b, &ans)
- if b+1 == len(nums):
    - ans <- {nums[b]}
    - return 
- rec(nums, b+1, ans)
- for n in nums:
    - new = n + nums[b]
    - ans <- new
- ans <- {nums[b]}

Algo2: backtracking:
- we have ans for n-1:
- for every value in ans:
    - add to ans value + num
n = 0: [[]]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        rec(nums, 0, res);
        res.push_back({});
        return res;
    }
    
private:
    void rec(const vector<int>& nums, size_t b, vector<vector<int>>& ans) {
        if (b+1 == nums.size()) {
            ans.push_back({nums.back()});
            return;
        }
        rec(nums, b+1, ans);
        size_t n = ans.size();
        for (size_t i = 0; i < n; ++i) {
            auto v = ans[i];
            v.push_back(nums[b]);
            ans.push_back(move(v));
        }
        ans.push_back({nums[b]});
    }
};

class Solution {
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        ans.reserve(1 << nums.size());
        for (auto num : nums) {
            size_t n = ans.size();
            for (size_t i = 0; i < n; ++i) {
                auto val = ans[i];
                val.push_back(num);
                ans.push_back(move(val));
            }
        }
        return ans;
    }
};


