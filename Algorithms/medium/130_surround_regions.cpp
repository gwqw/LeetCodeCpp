/**
    130. Surrounded Regions
Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:
Input: board = 
[["X","X","X","X"],
 ["X","O","O","X"],
 ["X","X","O","X"],
 ["X","O","X","X"]]
Output: 
[["X","X","X","X"],
 ["X","X","X","X"],
 ["X","X","X","X"],
 ["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

Example 2:
Input: board = [["X"]]
Output: [["X"]]

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.

Algo: graph recursive dfs
start element -- 'O' elements on the border of matrix
for start_element in start_elements:
	dfs(i, j)
change('O' -> 'X', 'V' -> 'O')
return matrix

dfs(i, j):
	if i < 0 || j < 0 || i >= n || j >= m: return
	if m[i, j] == 'X' or m[i,j] = 'V': return
	m[i, j] = 'V'
	dfs(m, i-1, j)
	dfs(m, i+1, j)
	dfs(m, i, j-1)
	dfs(m, i, j+1)


[["X","X","X","X"],
 ["X","X","O","X"],
 ["X","O","O","X"],
 ["X","O","X","X"]]
*/

class Solution {
public:
    void solve(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return;
		int n = (int)matrix.size();
		int m = (int)matrix[0].size();
		// top row
		for (int j = 0; j < m; ++j) {
			if (matrix[0][j] == 'O') {
				dfs(matrix, 0, j);
			}
		}
		// bottom row
		if (n > 1) {
			for (int j = 0; j < m; ++j) {
				if (matrix[n-1][j] == 'O') {
					dfs(matrix, n-1, j);
				}
			}
		}
		// left column
        for (int i = 1; i+1 < n; ++i) {
			if (matrix[i][0] == 'O') {
				dfs(matrix, i, 0);
			}
		}
		//right column
		if (m > 1) {
			for (int i = 1; i+1 < n; ++i) {
				if (matrix[i][m-1] == 'O') {
					dfs(matrix, i, m-1);
				}
			}
		}
		// convert matrix
		for (auto& row : matrix) {
			for (auto& element : row) {
				if (element == 'O') element = 'X';
				if (element == 'V') element = 'O';
			}
		}
    }
private:
	void dfs(vector<vector<char>>& matrix, int i, int j) {
		if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) return;
		if (matrix[i][j] == 'X' || matrix[i][j] == 'V') return;
		matrix[i][j] = 'V';
		dfs(matrix, i, j-1);
		dfs(matrix, i, j+1);
		dfs(matrix, i-1, j);
		dfs(matrix, i+1, j);		
	}
};


