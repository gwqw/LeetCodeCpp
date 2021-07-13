/**
    354. Russian Doll Envelopes
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1

Constraints:
1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 10^4

Algo1: special 2D-LIS with compare: l.w < r.w && l.h < r.h: O(NlogN + N^2
sort with areas
dp[idx]->size
dp[i] = 1
dp[i] = max(dp[i], dp[j] + 1 (if dp[j] < dp[i]))

Algo2: sort + 1D-LIS
sort by w after h descending! (it garantee we will not use 2 dolls with same width)
LIS on heights 
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), 
            [](const vector<int>& lhs, const vector<int>& rhs){
                return lhs[0]*lhs[1] < rhs[0]*rhs[1];
            }
        );
        vector<int> dp(envelopes.size(), 1);
        int max_cnt = 1;
        for (size_t i = 1; i < envelopes.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (isLess(envelopes[j], envelopes[i])) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_cnt = max(max_cnt, dp[i]);
        }
        return max_cnt;
    }
    
private:
    bool isLess(const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[0] < rhs[0] && lhs[1] < rhs[1];
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), 
            [](const vector<int>& lhs, const vector<int>& rhs){
                return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
            }
        );
        vector<int> dp(envelopes.size(), 1);
        int max_cnt = 1;
        for (size_t i = 1; i < envelopes.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (isLess(envelopes[j], envelopes[i])) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_cnt = max(max_cnt, dp[i]);
        }
        return max_cnt;
    }
    
private:
    bool isLess(const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[1] < rhs[1];
    }
};

[[5,4],[6,4],[6,7],[2,3]]
[[1,1],[1,1],[1,1]]
[[1,1]]
[[30,50],[12,2],[3,4],[12,15]]
[[17,15],[17,18],[2,8],[7,2],[17,2],[17,8],[6,15]]
[2,8],[7,2],[6,15],[17,2],[17,15],[17,18],[17,8]

[5,4],[6,4],[6,7],[2,3]
                   ^
dp: 1  1     2     1
max: 1