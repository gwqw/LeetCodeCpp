/**
    79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = 
[["A","B","C","E"],
 ["S","F","C","S"],
 ["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = 
[["A","B","C","E"],
 ["S","F","C","S"],
 ["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = 
[["A","B","C","E"],
 ["S","F","C","S"],
 ["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a larger board?

Algo: dfs in graph

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string_view word) {
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    bool res = dfs(board, i, j, word);
                    if (res) return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string_view word) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || word[0] != board[i][j]) return false;
        word.remove_prefix(1);
        if (word.empty()) return true;
        char prev = board[i][j];
        board[i][j] = ' ';
        bool res = false;
        res = dfs(board, i-1, j, word);
        if (res) return true;
        res = dfs(board, i+1, j, word);
        if (res) return true;
        res = dfs(board, i, j-1, word);
        if (res) return true;
        res = dfs(board, i, j+1, word);
        board[i][j] = prev;
        return res;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string_view word) {
        unordered_set<char> letters = getLetters(board);
        for (char c : word) {
            if (!letters.count(c)) return false;
        }
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    bool res = dfs(board, i, j, word);
                    if (res) return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string_view word) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || word[0] != board[i][j]) return false;
        word.remove_prefix(1);
        if (word.empty()) return true;
        char prev = board[i][j];
        board[i][j] = ' ';
        bool res = false;
        res = dfs(board, i-1, j, word);
        if (res) return true;
        res = dfs(board, i+1, j, word);
        if (res) return true;
        res = dfs(board, i, j-1, word);
        if (res) return true;
        res = dfs(board, i, j+1, word);
        board[i][j] = prev;
        return res;
    }
    
    unordered_set<char> getLetters(const vector<vector<char>>& board) {
        unordered_set<char> letters;
        for (const auto& row : board) {
            for (char c : row) {
                letters.insert(c);
            }
        }
        return letters;
    }
};
