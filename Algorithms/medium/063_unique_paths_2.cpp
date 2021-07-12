/**
    63. Unique Paths II
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.

Example 1:
Input: obstacleGrid = 
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

Constraints:
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

Algo1: dp 2d from top and to right: O(N^2) + O(N^2)
dp[r][c] -> paths_count
d[r][c] = if !obstacle: dp[r-1][c] + dp[r][c-1] else: 0

Algo2: same but with 2 vectors O(N)memory
*/

class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
        int n = (int)obstacleGrid.size();
        int m = (int)obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int c = 0; c < m; ++c) {
            if (obstacleGrid[0][c] == 1) {
                dp[0][c] = 0;
            } else {
                dp[0][c] = c > 0 ? dp[0][c-1] : 1;
            }
        }
        
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (obstacleGrid[r][c] == 1) {
                    dp[r][c] = 0;
                } else {
                    dp[r][c] = dp[r-1][c];
                    dp[r][c] += c > 0 ? dp[r][c-1] : 0;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
        int n = (int)obstacleGrid.size();
        int m = (int)obstacleGrid[0].size();
        vector<int> prev(m, 0);
        for (int c = 0; c < m; ++c) {
            if (obstacleGrid[0][c] == 1) {
                prev[c] = 0;
            } else {
                prev[c] = c > 0 ? prev[c-1] : 1;
            }
        }
        
        for (int r = 1; r < n; ++r) {
            vector<int> cur(m, 0);
            for (int c = 0; c < m; ++c) {
                if (obstacleGrid[r][c] == 1) {
                    cur[c] = 0;
                } else {
                    cur[c] = prev[c];
                    cur[c] += c > 0 ? cur[c-1] : 0;
                }
            }
            prev = move(cur);
        }
        return prev.back();
    }
};
