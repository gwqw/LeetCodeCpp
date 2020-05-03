/**
    64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

Algo1: dp
- make matrix with costs
- for every cell:
    - cost = min(left, up) + value

Algo2: min path in graph

*/

class Solution {
    using Matrix = vector<vector<int>>;
public:
    int minPathSum(const vector<vector<int>>& grid) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        Matrix costs(n, vector<int>(m, 0));
        costs[0][0] = grid[0][0];
        for (size_t j = 1; j < m; ++j) {
            costs[0][j] = costs[0][j-1] + grid[0][j];
        }
        for (size_t i = 1; i < n; ++i) {
            costs[i][0] = costs[i-1][0] + grid[i][0];
            for (size_t j = 1; j < m; ++j) {
                costs[i][j] = min(costs[i-1][j], costs[i][j-1]) + grid[i][j];
            }
        }
        return costs[n-1][m-1];
    }
};

class Solution {
    using Matrix = vector<vector<int>>;
public:
    int minPathSum(const vector<vector<int>>& grid) {
        size_t n = grid.size();
        size_t m = grid[0].size();
        vector<int> cur(m, 0), prev(m, 0);
        prev[0] = grid[0][0];
        for (size_t j = 1; j < m; ++j) {
            prev[j] = prev[j-1] + grid[0][j];
        }
        for (size_t i = 1; i < n; ++i) {
            cur[0] = prev[0] + grid[i][0];
            for (size_t j = 1; j < m; ++j) {
                cur[j] = min(prev[j], cur[j-1]) + grid[i][j];
            }
            prev = cur;
        }
        return prev[m-1];
    }
};
