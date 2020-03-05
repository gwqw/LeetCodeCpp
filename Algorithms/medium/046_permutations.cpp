/**
    46. Permutations
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

Algo:
- save initial state
- set cur_idx = n-1
- swap(n[cur_idx], n[cur_idx-1])
- --cur_idx
- if cur_idx == 0: cur_idx = n-1
- return n != init
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return {nums};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do {
            res.push_back(nums);
        } while (nextPermutation(nums));
        return res;
    }
    
private: 
    bool nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        int i = (int)nums.size()-1;
        for (;;) {
            if (i == 0) return false;
            int j = i-1;
            if (nums[j] < nums[i]) {
                i = j;
                j = (int)nums.size() - 1;
                while (nums[i] >= nums[j]) --j;
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return true;
            } else {
                --i;
            }
        }
    }
};

