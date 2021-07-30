/**
    794. Valid Tic-Tac-Toe State
Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.

Here are the rules of Tic-Tac-Toe:
Players take turns placing characters into empty squares ' '.
The first player always places 'X' characters, while the second player always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.

Example 1:
Input: board = 
["O  ",
 "   ",
 "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = 
["XOX",
 " X ",
 "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = 
["XXX",
 "   ",
 "OOO"]
Output: false

Example 4:
Input: board = 
["XOX",
 "O O",
 "XOX"]
Output: true

Constraints:
board.length == 3
board[i].length == 3
board[i][j] is either 'X', 'O', or ' '.

Algo: check false conditions
- Xcnt == Ocnt or Xcnt == Ocnt+1
- cannont be 2 wins


*/

class Solution {
public:
    bool validTicTacToe(const vector<string>& board) {
        n = board.size();
        int cnt = fillArrays(board);
        if (cnt < 0 || cnt > 1) return false;
        int xrw = arrWins(rx);
        int xcw = arrWins(cx);
        int xmdw = mdx == 3 ? 1 : 0;
        int xadw = adx == 3 ? 1 : 0;
        int xwins = xrw + xcw + xmdw + xadw;
        int orw = arrWins(r0);
        int ocw = arrWins(c0);
        int omdw = md0 == 3 ? 1 : 0;
        int oadw = ad0 == 3 ? 1 : 0;
        int owins = orw + ocw + omdw + oadw;
        if (xwins > 0 && owins > 0) {
            return false;
        }
        if (xrw > 1 || xcw > 1 || orw > 1 || ocw > 1) return false;        
        if (xwins >= 1 && cnt == 0 || owins >= 1 && cnt == 1) return false;
        return true;
    }
	
private:
    int fillArrays(const vector<string>& board) {
        int cnt = 0;        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'X') {
                    ++rx[r];
                    ++cx[c];
                    if (r == c) {
                        ++mdx;
                    } 
                    if (n-r-1 == c) {
                        ++adx;
                    }
                    ++cnt;
                } else if (board[r][c] == 'O') {
                    ++r0[r];
                    ++c0[c];
                    if (r == c) {
                        ++md0;
                    } 
                    if (n-r-1 == c) {
                        ++ad0;
                    }
                    --cnt;
                }                
            }
        }
        return cnt;
    }
    
    int arrWins(const array<int, 3>& a) {
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == n) ++cnt;
        }
        return cnt;
    }
    
    
	
private:
	array<int, 3> rx{0}, cx{0}, r0{0}, c0{0};
	int mdx{0}, md0{0}, adx{0}, ad0{0};
	size_t n = 0;
};


