/**
    289. Game of Life
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

- Any live cell with fewer than two live neighbors dies, as if caused by under-population.
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies, as if by over-population..
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:
Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

Algo1: use other matrix and swap: O(N*M) + O(N*M)
- for every call calc n = nums of neighbours
- if c == 1:
    - if n < 2: c = 0
    - elif n > 3: c = 0
    - else: c = 1
- else: # c == 0
    - if n == 3: c = 1
    - else: c = 0
    
Algo2: use aditional state: O(N*M) + O(1)
- for every call calc n = nums of neighbours
- if c == 1:
    - if n < 2: c = 3
    - elif n > 3: c = 3
- else: # c == 0
    - if n == 3: c = 4

*/

class Solution {
    using Matrix = vector<vector<int>>;
public:
    void gameOfLife(vector<vector<int>>& board) {
        size_t n = board.size();
        if (n == 0) return;
        size_t m = board[0].size();
        Matrix res(n, vector<int>(m));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                auto n = getNeighbours(board, i, j);
                if (board[i][j] == 1) {
                    if (n < 2 || n > 3) {
                        res[i][j] = 0;
                    } else {
                        res[i][j] = 1;
                    }
                } else {
                    if (n == 3) {
                        res[i][j] = 1;
                    } else {
                        res[i][j] = 0;
                    }
                }
            }
        }
        swap(board, res);
    }
    
private:
    int getNeighbours(const Matrix board, size_t i, size_t j) {
        size_t n = board.size();
        size_t m = board[0].size();
        int res = 0;
        if (i > 0) {
            if (j > 0) res += board[i-1][j-1];
            res += board[i-1][j];
            if (j+1 < m) res += board[i-1][j+1];
        }
        if (j > 0) res += board[i][j-1];
        res += board[i][j];
        if (j+1 < m) res += board[i][j+1];
        if (i+1 < n) {
            if (j > 0) res += board[i+1][j-1];
            res += board[i+1][j];
            if (j+1 < m) res += board[i+1][j+1];
        }
        return res;
    }
};

class Solution {
    using Matrix = vector<vector<int>>;
public:
    void gameOfLife(vector<vector<int>>& board) {
        size_t n = board.size();
        if (n == 0) return;
        size_t m = board[0].size();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                auto n = getNeighbours(board, i, j);
                if (board[i][j] == 1) {
                    if (n < 2 || n > 3) {
                        board[i][j] = 3;
                    }
                } else {
                    if (n == 3) {
                        board[i][j] = 4;
                    }
                }
            }
        }
        recalcValues(board);
    }
    
private:
    int getNeighbours(const Matrix board, size_t i, size_t j) {
        size_t n = board.size();
        size_t m = board[0].size();
        int res = 0;
        if (i > 0) {
            if (j > 0) res += board[i-1][j-1] % 2;
            res += board[i-1][j] % 2;
            if (j+1 < m) res += board[i-1][j+1] % 2;
        }
        if (j > 0) res += board[i][j-1] % 2;
        if (j+1 < m) res += board[i][j+1] % 2;
        if (i+1 < n) {
            if (j > 0) res += board[i+1][j-1] % 2;
            res += board[i+1][j] % 2;
            if (j+1 < m) res += board[i+1][j+1] % 2;
        }
        return res;
    }
    
    void recalcValues(Matrix& board) {
        size_t n = board.size();
        size_t m = board[0].size();
        for (auto& row : board) {
            for (auto& v : row) {
                if (v == 3) v = 0;
                else if (v == 4) v = 1;
            }
        }
    }
};




