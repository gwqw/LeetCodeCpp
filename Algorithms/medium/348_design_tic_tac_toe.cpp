/**
    348. Design Tic-Tac-Toe
Design a Tic-tac-toe game that is played between two players on a n x n grid.
You may assume the following rules:
A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation?

Algo1: bf check

Algo2: make counters for rows, cols and diags for every player

*/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : data(n, vector<int>(n, 0)) 
    {}
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        setField(row, col, player);
        if (checkWin(player, row, col)) {
            return player;
        } else {
            return 0;
        }
    }
    
private:
    vector<vector<int>> data;
    
    void setField(int row, int col, int player) {
        data[row][col] = player;
    }
    
    bool checkWinSimple(int player, int row, int col) {
        // check rows
        for (const auto& r : data) {
            bool is_all_player = true;
            for (auto f : r) {
                if (f != player) {
                    is_all_player = false;
                    break;
                }
            }
            if (is_all_player) {
                return true;
            }
        }
        // check cols
        for (size_t ci = 0; ci < data[0].size(); ++ci) {
            bool is_all_player = true;
            for (size_t ri = 0; ri < data.size(); ++ri) {
                if (data[ri][ci] != player) {
                    is_all_player = false;
                    break;
                }
            }
            if (is_all_player) {
                return true;
            }
        }
        // check diagonals
        // main diagonal
        {
            bool is_all_player = true;
            for (size_t i = 0; i < data.size(); ++i) {
                if (data[i][i] != player) {
                    is_all_player = false;
                    break;
                }
            }
            if (is_all_player) {
                return true;
            }
        }
        // other diagonal
        {
            bool is_all_player = true;
            size_t n = data.size();
            for (size_t i = 0; i < data.size(); ++i) {
                if (data[i][n-i-1] != player) {
                    is_all_player = false;
                    break;
                }
            }
            if (is_all_player) {
                return true;
            }
        }
        return false;
    }
    
    bool checkWin(int player, int row, int col) {
        size_t n = data.size();
        // check row
        {
            bool is_all_player = true;
            const auto& r = data[row];
            for (auto f : r) {
                if (f != player) {
                    is_all_player = false;
                    break;
                }
            }
            if (is_all_player) {
                return true;
            }
        }
        // check col
        {
            bool is_all_player = true;
            size_t ci = col;
            for (size_t ri = 0; ri < n; ++ri) {
                if (data[ri][ci] != player) {
                    is_all_player = false;
                    break;
                }
            }
            if (is_all_player) {
                return true;
            }
        }
        // check diagonals
        // main diagonal
        {
            if (row == col) {
                bool is_all_player = true;
                for (size_t i = 0; i < n; ++i) {
                    if (data[i][i] != player) {
                        is_all_player = false;
                        break;
                    }
                }
                if (is_all_player) {
                    return true;
                }
            }
        }
        // other diagonal
        {
            if (row + col == n-1) {
                bool is_all_player = true;
                for (size_t i = 0; i < n; ++i) {
                    if (data[i][n-i-1] != player) {
                        is_all_player = false;
                        break;
                    }
                }
                if (is_all_player) {
                    return true;
                }
            }
        }
        return false;
    }
};

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    {
        rp[0].resize(n, 0); rp[1].resize(n, 0);
        cp[0].resize(n, 0); cp[1].resize(n, 0);
        dmp[0] = 0; dmp[1] = 0;
        dop[0] = 0; dop[1] = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        setField(row, col, player);
        if (checkWin(player, row, col)) {
            return player;
        } else {
            return 0;
        }
    }
    
private:
    array<vector<int>, 2> rp, cp;
    array<int, 2> dmp, dop;
    
    void setField(int row, int col, int player) {
        size_t n = rp[player-1].size();
        ++rp[player-1][row];
        ++cp[player-1][col];
        if (col == row) {
            ++dmp[player-1];
        }
        if (col+row == n-1) {
            ++dop[player-1];
        }
    }
    
    bool checkWin(int player, int row, int col) {
        size_t n = rp[player-1].size();
        return (rp[player-1][row] == n) || (cp[player-1][col] == n) ||
            (row == col && dmp[player-1] == n) || (row + col == n-1 && dop[player-1] == n);
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */