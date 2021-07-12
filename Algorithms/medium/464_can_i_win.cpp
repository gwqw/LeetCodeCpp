/**
    464. Can I Win
In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

Example 1:
Input: maxChoosableInteger = 10, desiredTotal = 11
Output: false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

Example 2:
Input: maxChoosableInteger = 10, desiredTotal = 0
Output: true

Example 3:
Input: maxChoosableInteger = 10, desiredTotal = 1
Output: true

Constraints:
1 <= maxChoosableInteger <= 20
0 <= desiredTotal <= 300

Algo: dp with memo, code state in bitset
State = bitset<20>
is_win[state]->bool
if state in is_win: return is_win[state]
for n in state:
    if target < n:
        is_win[state] = true
        return true
    else:
        res = can_win(state - n, target - n)
        if not res:
            is_win[state] = true
            return true
is_win[state] = false
    
*/

// bitset + vector
class Solution {
    using State = bitset<20>;
public:
    bool canIWin(int n, int target) {
        if (n * (1 + n) / 2 < target) return false;
        vector<char> is_win(1 << 20);
        State state;
        state.set();
        return can_win(target, state, n, is_win);
    }
    
private:
    bool can_win(int target, State state, const int n, vector<char>& is_win) {
		if (is_win[state] != 0) return is_win[state] == 1;
        for (int i = n; i > 0; --i) {
            if (state.test(i-1)) {
                if (target <= i) {
		            is_win[state] = 1;
                    return true;
                }
                state.reset(i-1);
                auto res = can_win(target - i, state, n, is_win);
                state.set(i-1);
                if (!res) {
		            is_win[state] = 1;
                    return true;
                }
            }
        }
        is_win[state] = -1;
        return false;
    }
};
// bit operation + unordered_map
class Solution {
    using State = uint32_t;
public:
    bool canIWin(int n, int target) {
        if (n * (1 + n) / 2 < target) return false;
        unordered_map<State, bool> is_win;
        State state = ((1 << 22) - 1) << 1;
        return can_win(target, state, n, is_win);
    }
    
private:
    bool can_win(int target, State state, const int n, unordered_map<State, bool>& is_win) {
		if (is_win.count(state)) return is_win[state];
        for (int i = n; i > 0; --i) {
            if ((state & (1 << i)) == (1 << i)) {
                if (target <= i) {
		            is_win[state] = true;
                    return true;
                }
                auto res = can_win(target - i, state & ~(1 << i), n, is_win);
                if (!res) {
		            is_win[state] = true;
                    return true;
                }
            }
        }
        is_win[state] = false;
        return false;
    }
};
// bit operation + vector
class Solution {
    using State = uint32_t;
public:
    bool canIWin(int n, int target) {
        if (n * (1 + n) / 2 < target) return false;
        vector<char> is_win(1 << 20);
        State state = (1 << 20) - 1;
        return can_win(target, state, n, is_win);
    }
    
private:
    bool can_win(int target, State state, const int n, vector<char>& is_win) {
		if (is_win[state] != 0) return is_win[state] == 1;
        for (int i = n; i > 0; --i) {
            if ((state & (1 << i-1)) == (1 << i-1)) {
                if (target <= i) {
		            is_win[state] = 1;
                    return true;
                }
                auto res = can_win(target - i, state & ~(1 << i-1), n, is_win);
                if (!res) {
		            is_win[state] = 1;
                    return true;
                }
            }
        }
        is_win[state] = -1;
        return false;
    }
};
