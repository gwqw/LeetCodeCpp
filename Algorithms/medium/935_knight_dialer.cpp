/**
    935. Knight Dialer
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:
A chess knight can move as indicated in the chess diagram below:
We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
Given an integer n, return how many distinct phone numbers of length n we can dial.
You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.
As the answer may be very large, return the answer modulo 10^9 + 7.

Example 1:
Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

Example 2:
Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

Example 3:
Input: n = 3
Output: 46

Example 4:
Input: n = 4
Output: 104

Example 5:
Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.

Constraints:
1 <= n <= 5000

Algo: dp
n == 1: return 10 # special case
1 -> 6,8
2 -> 7,9
3 -> 4,8
4 -> 3,9,0
5 -> x
6 -> 1,7,0
7 -> 2,6
8 -> 1,3
9 -> 2,4
0 -> 4,6
dp[length][num] = sum dp[length-1][a] for a in next[num]
return sum(dp[n][i])
*/

class Solution {
    static constexpr int M = 1e9 + 7;
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        vector<vector<int>> dp(n+1, vector<int>(10));
        dp[1] = vector(10, 1);
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i < 10; ++i) {
                for (int n : next[i]) {
                    dp[l][i] = mplus(dp[l][i], dp[l-1][n]);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum = mplus(sum, dp[n][i]);
        }
        return sum;
    }
    
private:
    int64_t mplus(int64_t x, int64_t y) {
        return (x%M + y%M) % M;
    }
    
private:
    static array<vector<int>, 10> next;
};

array<vector<int>, 10> Solution::next{
    vector<int>{4,6},
    vector<int>{6,8},
    vector<int>{7,9},
    vector<int>{4,8},
    vector<int>{3,9,0},
    vector<int>{},
    vector<int>{1,7,0},
    vector<int>{2,6},
    vector<int>{1,3},
    vector<int>{2,4},
};
