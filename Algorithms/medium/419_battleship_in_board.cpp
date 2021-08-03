/**
    419. Battleships in a Board
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.
Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

Example 1:
Input: board = 
[["X",".",".","X"],
 [".",".",".","X"],
 [".",".",".","X"]]
Output: 2

Example 2:
Input: board = [["."]]
Output: 0

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is either '.' or 'X'.

Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?

Algo1: FloodFill
for row in rows:
	for e in row:
		if e == 'X':
			floodfill
			++cnt
return cnt

Algo2: count only left-top edges
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
		int cnt = 0;
        for (size_t i = 0; i < board.size(); ++i) {
			for (size_t j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == 'X') {
					floodfill(board, i, j);
					++cnt;
				}
			}
		}
		return cnt;
    }
	
private:
	void floodfill(vector<vector<char>>& board, size_t i, size_t j) {
		if (i+1 == board.size() || j+1 == board[0].size() || board[i][j] == '.') return;
		board[i][j] = '.';
		floodfill(board, i, j+1);
		floodfill(board, i+1, j);
	}
};

class Solution {
public:
    int countBattleships(const vector<vector<char>>& board) {
		int cnt = 0;
        for (size_t i = 0; i < board.size(); ++i) {
			for (size_t j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == 'X') {
                    if (i == 0 && j == 0 ||
                        i == 0 && board[i][j-1] == '.' ||
                        j == 0 && board[i-1][j] == '.' ||
                        i != 0 && j !=0 && board[i-1][j] == '.' && board[i][j-1] == '.')
                    {
                        ++cnt;
                    }
				}
			}
		}
		return cnt;
    }
};