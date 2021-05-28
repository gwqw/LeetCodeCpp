/**
    221. Maximal Square
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
Input: matrix = 
[["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = 
[["0","1"],
 ["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

Algo: brute-force: O(N^4)
for i,j in matrix:
	find max square with left top angle in i,j

Algo: dp: O(N^2), O(N^2)mem
matrix: max square with bottom right corner in i,j
if matrix[i,j] == '1':
    m[i,j] = min(m[i-1,j], m[i,j-1], m[i-1,j-1]) + 1 # min square upper, lefter and diag shift and +1
    update max_square
    
Algo2: same dp, but less mem: O(N^2), O(N)mem
*/

class Solution {
public:
    int maximalSquare(const vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        size_t h = matrix.size();
        size_t w = matrix[0].size();
        vector<vector<int>> m(h, vector<int>(w, 0));
        int ans = 0;
        for (size_t j = 0; j < w; ++j) {
            m[0][j] = matrix[0][j] == '1' ? 1 : 0;
            ans = max(ans, m[0][j]);
        }
        for (size_t i = 1; i < h; ++i) {
            m[i][0] = matrix[i][0] == '1' ? 1 : 0;
            ans = max(ans, m[i][0]);
            for (size_t j = 1; j < w; ++j) {
                if (matrix[i][j] == '1') {
                    m[i][j] = min(min(m[i][j-1], m[i-1][j-1]), m[i-1][j]) + 1;
                    ans = max(ans, m[i][j]);
                }
            }
        }
        return ans*ans;
    }
};


class Solution {
public:
    int maximalSquare(const vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        size_t h = matrix.size();
        size_t w = matrix[0].size();
        vector<int> prev(w, 0);
        int ans = 0;
        for (size_t j = 0; j < w; ++j) {
            prev[j] = matrix[0][j] == '1' ? 1 : 0;
            ans = max(ans, prev[j]);
        }
        for (size_t i = 1; i < h; ++i) {
            vector<int> cur(w, 0);
            cur[0] = matrix[i][0] == '1' ? 1 : 0;
            ans = max(ans, cur[0]);
            for (size_t j = 1; j < w; ++j) {
                if (matrix[i][j] == '1') {
                    cur[j] = min(min(cur[j-1], prev[j-1]), prev[j]) + 1;
                    ans = max(ans, cur[j]);
                }
            }
            swap(prev, cur);
        }
        return ans*ans;
    }
};
