/**
    877. Stone Game
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.
Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

Example 1:
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.

Constraints:
2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.

Algo: dp(2D)
dp[start][end] = (f,s)
for l in length:
    if l == 1: dp[l][l] = a[l],0
    check turn
    for s in start_positions:
        e = calc_end(l, s)
        dp[s][e] = max(a[s] + dp[s+1][e], a[e] + dp[s][e-1])
*/

class Solution {
public:
    bool stoneGame(const vector<int>& a) {
        vector<vector<int>> dp(a.size(), vector<int>(a.size()));
        for (size_t i = 0; i < a.size(); ++i) {
            dp[i][i] = a[i];
        }
        bool first = false;
        for (size_t l = 2; l <= a.size(); ++l) {
            bool is_first = !first;
            for (size_t s = 0; s+l-1 < a.size(); ++s) {
                size_t e = s + l - 1;
                if (is_first) {
                    dp[s][e] = max(
                        a[s] + dp[s+1][e],
                        a[e] + dp[s][e-1]
                    );
                } else {
                    dp[s][e] = min(
                        -a[s] + dp[s+1][e],
                        -a[e] + dp[s][e-1]
                    );
                }
            }
        }
        return dp[0][a.size()-1] > 0;
    }
};