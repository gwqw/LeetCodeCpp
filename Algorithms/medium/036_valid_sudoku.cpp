/**
    36. Valid Sudoku
Determine if a 9x9 Sudoku board is valid.
Only the filled cells need to be validated according to the following rules:
    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false

Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.

Algo1:
- go through row and check duplicates
- go through col and check duplicates
- go through squares and check duplicates

Algo2:
- add elements to sets
sets can be array of array<int, digit>
*/

class Solution {
    using Nums = array<char, 10>;
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        // check rows
        for (const auto& row : board) {
            Nums nums = {0};
            for (auto c : row) {
                auto n = parseNum(c);
                if (n == 0) continue;
                if (nums[n] != 0) return false;
                nums[n] = 1;
            }
        }
        // check cols
        for (int ci = 0; ci < 9; ++ci) {
            Nums nums = {0};
            for (int ri = 0; ri < 9; ++ri) {
                auto n = parseNum(board[ri][ci]);
                if (n == 0) continue;
                if (nums[n] != 0) return false;
                nums[n] = 1;
            }
        }
        // check squares
        for (int si = 0; si < 9; ++si) {
            auto [r0,c0] = getStartIdx(si);
            Nums nums = {0};
            for (int ri = r0; ri < r0+3; ++ri) {
                for (int ci = c0; ci < c0+3; ++ci) {
                    auto n = parseNum(board[ri][ci]);
                    if (n == 0) continue;
                    if (nums[n] != 0) return false;
                    nums[n] = 1;
                }
            }
        }
        return true;
    }
private:
    static int parseNum(char c) {
        if (c == '.') return 0;
        assert('1' <= c && c <= '9');
        return c - '0';
    }
    
    static pair<int,int> getStartIdx(int square_idx) {
        return {
            3*(square_idx / 3),
            3*(square_idx % 3)
        };        
    }
};

class Solution {
    using NumSets = array<unordered_set<int>, 9>;
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        NumSets rows, cols, squares;
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                int el = parseNum(board[i][j]);
                if (el == 0) continue;
                if (!tryEmplace(rows[i], el)) return false;
                if (!tryEmplace(cols[j], el)) return false;
                auto sq_idx = getSquareIdx(i, j);
                if (!tryEmplace(squares[sq_idx], el)) return false;
            }
        }
        return true;
    }
    
private:
    static bool tryEmplace(unordered_set<int>& s, int val) {
        if (auto it = s.find(val); it != s.end()) return false;
        s.insert(val);
        return true;
    }
    
    static size_t getSquareIdx(size_t i, size_t j) {
        size_t ix = i / 3;
        size_t jx = j / 3;
        return 3*ix + jx;
    }
    
    static int parseNum(char c) {
        if (c == '.') return 0;
        assert('1' <= c && c <= '9');
        return c - '0';
    }
};

