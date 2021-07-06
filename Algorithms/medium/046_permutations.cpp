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

Algo1:
- save initial state
- set cur_idx = n-1
- swap(n[cur_idx], n[cur_idx-1])
- --cur_idx
- if cur_idx == 0: cur_idx = n-1
- return n != init

Algo2: recursive
- make recursive call: rec(nums, free_idx)
- if all free_idx is false: return {}
- res = {}
- for i in free_idx:
    if not i: continue
    n <- nums[i]
    new_pref = {n}
    free_idx[i] = false
    suf <- rec(nums, free_idx)
    free_idx[i] = true
    if suf is empty:
        res add new_pref
    for s in suf:
        res add (new_pref + s)
return res

Algo3:
- generate for N-1
- and insert N-value to all positions

Algo4: like Algo2, but rec(pref, remaining)
- remove ith element from remaining
- push to prefix
- call rec(pref, remaining)
- pop from prefix
- insert in remaining

Algo5: backtracking
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


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return {nums};
        vector<bool> free_idx(nums.size(), true);
        return rec(nums, free_idx);
    }
    
private: 
    vector<vector<int>> rec(const vector<int>& nums, vector<bool>& free_idx) {
        if (all_of(free_idx.begin(), free_idx.end(), [](const auto& value){return !value;})) {
            return {};
        }
        vector<vector<int>> res;
        for (size_t i = 0; i < free_idx.size(); ++i) {
            if (!free_idx[i]) continue;
            int n = nums[i];
            free_idx[i] = false;
            vector<int> new_prefix{n};
            auto suf = rec(nums, free_idx);
            free_idx[i] = true;
            if (suf.empty()) {
                res.push_back(move(new_prefix));
            }
            for (auto& s : suf) {
                res.push_back(new_prefix);
                res.back().insert(res.back().end(), s.begin(), s.end());
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return rec(nums, 0);
    }
private:
    vector<vector<int>> rec(vector<int>& nums, size_t b) {
        if (b + 1 == nums.size()) {
            return {{nums[b]}};
        }
        
        auto suf = rec(nums, b+1);
        vector<vector<int>> res;
        for (const auto& s : suf) {
            for (size_t pos = 0; pos <= s.size(); ++pos) {
                res.push_back(s);
                auto& last = res.back();
                last.insert(last.begin() + pos, nums[b]);
            }           
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur(nums.size());
        unordered_set<int> used;
        rec(nums, cur, 0, used, res);
        return res;
    }
private:
    void rec(const vector<int>& nums, vector<int> cur, size_t b,
            unordered_set<int> used, vector<vector<int>>& res
    ) {
        if (b == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (auto n : nums) {
            if (used.count(n)) continue;
            cur[b] = n;
            used.insert(n);
            rec(nums, cur, b+1, used, res);
            used.erase(n);
        }
    }
};










