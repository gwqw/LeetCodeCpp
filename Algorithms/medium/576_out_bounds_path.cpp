/**
    576. Out of Boundary Paths
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 10^9 + 7.

Example 1:
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
[*.]
[..]


Example 2:
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
[*..]
3

Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

Algo: dp: O(n*m*maxMove) ~ 625000 ~ 6e5
make dp[n x m] for 1: corner: 2, side: 1, inside: 0
dp[i][j] for k = prev[i-1][j] + ...
return dp[0][0]
*/

class Solution {
	using Matrix = vector<vector<int>>;
    static constexpr int M = 1e9 + 7;
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        Matrix prev(n+2, vector<int>(m+2));
		fill_cur(prev);
		for (int mve = 0; mve < maxMove; ++mve) {
			Matrix cur(n+2, vector<int>(m+2));
			fill_cur(cur);
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					cur[i][j] = mplus(mplus(prev[i-1][j], prev[i][j-1]), mplus(prev[i][j+1], prev[i+1][j]));
				}
			}
			prev = move(cur);
		}
		return prev[startRow+1][startColumn+1];
    }
	
private:
	void fill_cur(Matrix& mtx) {
		for (int i = 0; i < mtx.size(); ++i) {
			mtx[i][0] = 1;
			mtx[i].back() = 1;
		}
		for (int j = 0; j < mtx[0].size(); ++j) {
			int pp = mtx.size()-2;
			mtx[0][j] = 1;
			mtx.back()[j] = 1;
		}
	}
    
    static int64_t mplus_ext(int64_t a, int64_t b) {
        return (a%M + b%M) % M;
    }
    
    static int64_t mplus(int64_t a, int64_t b) {
        return (a + b) % M;
    }
    
    void print(const Matrix& mtx) {
        for (int i = 1; i < mtx.size(); ++i) {
            for (int j = 1; j < mtx[0].size(); ++j) {
                cout << mtx[i][j] << " ";
            }
            cout << '\n';
        }
    }
};