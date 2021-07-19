/**
    486. Predict the Winner
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.
Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

Example 1:
Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.

Example 2:
Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 10^7

Algo: dp[s][e] = (f,s). O(N^2), O(N^2) mem
dp[s][e] -> (f,s)
fill by len:
1:
    dp[s][s] = a[s], 0
2:
    dp[s][e] = max(dp[s+1][e][1] + a[s], dp[s][e-1][1] + a[e]) and fill [1]

*/

class Solution {
public:
    bool PredictTheWinner(const vector<int>& a) {
        if (a.size() == 1) return true;
        vector<vector<pair<int, int>>> dp(a.size(), vector<pair<int, int>>(a.size(), {0,0}));
        for (size_t s = 0; s < a.size(); ++s) {
            dp[s][s] = {a[s], 0};
        }
        for (size_t len = 2; len <= a.size(); ++len) {
            for (size_t s = 0; s+len-1 < a.size(); ++s) {
                size_t e = s + len - 1;
                auto [f2, f1] = dp[s+1][e];
                auto [e2, e1] = dp[s][e-1];
                if (f1 + a[s] >= e1 + a[e]) {
                    dp[s][e] = {f1 + a[s], f2};
                } else {
                    dp[s][e] = {e1 + a[e], e2};
                }
            }
        }
        return dp[0][a.size()-1].first >= dp[0][a.size()-1].second;
    }
};
