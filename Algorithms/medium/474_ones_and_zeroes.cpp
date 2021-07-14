/**
    474. Ones and Zeroes
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Example 2:
Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.

Constraints:
1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100

Algo1: bf: backtracking (tle)
make every subset and calc 1 and 0
take 1 at 1st place and call for 2nd

Algo2: knapsack without repetition: dp (table3D: ones, zeroes and strings)
str_idx: can use strings until str_idx
d[si] = dp[si] <- can use same number of strings wo last
or use last
dp[si][ones][zeroes] = max(dp[si-1][ones][zeroes], dp[si-1][ones-oi][zeroes-zi]+1)
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> oz(strs.size());
        for (size_t i = 0; i < strs.size(); ++i) {
            oz[i] = count_01(strs[i]);
        }
        return findMax(oz, 0, n, m);
    }
    
private:
    pair<int, int> count_01(const string& s) {
        pair<int, int> res{0,0};
        for (char c : s) {
            if (c == '0') {
                ++res.second;
            } else {
                ++res.first;
            }
        }
        return res;
    }
    
    int findMax(const vector<pair<int, int>>& oz, size_t from, int ones, int zeros) {
        if (ones < 0 || zeros < 0) return -1;
        int res = 0;
        for (size_t i = from; i < oz.size(); ++i) {
            auto [o,z] = oz[i];
            ones -= o;
            zeros -= z;
            res = max(res, 
                findMax(oz, i+1, ones, zeros) + 1
            );                
            ones += o;
            zeros += z;
        }
        return res;
    }
};
// try memoisation
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> oz(strs.size());
        for (size_t i = 0; i < strs.size(); ++i) {
            oz[i] = count_01(strs[i]);
        }
        vector<vector<vector<int>>> from_ones_zeroes(strs.size(), 
            vector<vector<int>>(n+1, 
            vector<int>(m+1, -1)));
        return findMax(oz, 0, n, m, from_ones_zeroes);
    }
    
private:
    pair<int, int> count_01(const string& s) {
        pair<int, int> res{0,0};
        for (char c : s) {
            if (c == '0') {
                ++res.second;
            } else {
                ++res.first;
            }
        }
        return res;
    }
    
    int findMax(const vector<pair<int, int>>& oz, size_t from, int ones, int zeros, 
        vector<vector<vector<int>>>& cache
    ) {
        if (ones < 0 || zeros < 0) return -1;
        if (from == oz.size()) return 0;
        if (cache[from][ones][zeros] != -1) return cache[from][ones][zeros];
        int res = 0;
        for (size_t i = from; i < oz.size(); ++i) {
            auto [o,z] = oz[i];
            ones -= o;
            zeros -= z;
            res = max(res, 
                findMax(oz, i+1, ones, zeros, cache) + 1
            );                
            ones += o;
            zeros += z;
        }
        cache[from][ones][zeros] = res;
        return res;
    }
};

// knapsack
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> oz(strs.size());
        vector<vector<vector<int>>> dp(oz.size()+1, 
            vector<vector<int>>(n+1, 
            vector<int>(m+1, 0)));
        for (size_t si = 1; si < oz.size()+1; ++si) {
            auto [oi, zi] = count_01(strs[si-1]);
            for (int o = 0; o <= n; ++o) {
                for (int z = 0; z <= m; ++z) {
                    dp[si][o][z] = dp[si-1][o][z];
                    if (oi <= o && zi <= z) {
                        dp[si][o][z] = max(dp[si][o][z], dp[si-1][o-oi][z-zi]+1);
                    }
                }
            }
        }
            
        return dp.back().back().back();
    }
    
private:
    pair<int, int> count_01(const string& s) {
        pair<int, int> res{0,0};
        for (char c : s) {
            if (c == '0') {
                ++res.second;
            } else {
                ++res.first;
            }
        }
        return res;
    }
};