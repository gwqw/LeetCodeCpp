/**
    39. Combination Sum
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

Algo: backtracking
- sort array and unique
- take e = upper_bound(target)
- if e = end: return
- auto ans
- while (e >= begin):
    - --e
    - if e == target:
        ans += [e]
    else:
        - res = combinSum(cand, target - up)
        - for r : res:
            - ans += [r+e]
- return ans
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        if (a.empty()) return {};
        sort(a.begin(), a.end(), greater<int>());
        return combSum(a, target, 0);        
    }
    
private:
    // TODO: cache

    vector<vector<int>> combSum(vector<int>& a, int target, size_t start) {
        size_t i = distance(a.begin(), lower_bound(a.begin() + start, a.end(), target, greater<int>()));
        if (i == a.size()) return {};
        vector<vector<int>> ans;
        for (; i < a.size(); ++i) {
            if (a[i] == target) {
                ans.push_back({target});
            } else {
                auto res = combSum(a, target - a[i], i);
                for (auto& r : res) {
                    r.push_back(a[i]);
                    ans.push_back(move(r));
                }
            }
        }
        return ans;
    }
};
