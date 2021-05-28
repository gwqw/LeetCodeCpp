/**
   322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

Example 4:
Input: coins = [1], amount = 1
Output: 1

Example 5:
Input: coins = [1], amount = 2
Output: 2

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4

Algo1: dp O(ClogC + am^2), O(coins)
sort(coins)
a2n = amount->num: array of size=amount+1, value=INT_MAX
a2n[0] = 0
for a in range(1, amount+1):
    for c in coins:
        if a-c>=0:
            a2n[a] = min(a2n[a], a2n[a-c]+1)
        else:
            break
return a2n[amount] != INT_MAX ? a2n[amount] : INT_MAX;

Algo2: same but wo sort: O(am*coins), O(coins)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        constexpr int CANNOT = INT_MAX / 2;
        sort(coins.begin(), coins.end());
        vector a2n(amount+1, CANNOT);
        a2n[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto c : coins) {
                if (c > i) break;
                if (a2n[i-c] != CANNOT) {
                    a2n[i] = min(a2n[i], a2n[i-c]+1);
                }
            }
        }
        return a2n[amount] != CANNOT ? a2n[amount] : -1;
    }
};

// wo sort
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        constexpr int CANNOT = INT_MAX / 2;
        vector a2n(amount+1, CANNOT);
        a2n[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto c : coins) {
                if (i >= c && a2n[i-c] != CANNOT) {
                    a2n[i] = min(a2n[i], a2n[i-c]+1);
                }
            }
        }
        return a2n[amount] != CANNOT ? a2n[amount] : -1;
    }
};
