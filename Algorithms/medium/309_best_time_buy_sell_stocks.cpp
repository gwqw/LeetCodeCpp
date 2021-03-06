/**
   309. Best Time to Buy and Sell Stock with Cooldown
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Algo1: dp + brute-force: O(N^3)
- for every lastSell:
    - for every lastBuy:
        - update best_buy if (lastSell - lastBuy) + max money in [0,lastBuy) > best_buy[lastSell]

Algo2: dp + dp: O(N^2)
- for every lastSell:
    - for every lastBuy:
        - update best_buy if (lastSell - lastBuy) + max money in [0,lastBuy) > best_buy[lastSell]
        - max_best_buy[lastSell] = max(max_best_buy[lastSell-1], best_buy[lastSell])
        
Algo3: dp+dp+dp: O(N)
best_buy[i] -- best buy for sell in i
max_best_buy[i] -- max best_buy in [0,i]
dp[i] -- max count of -buy in [0,i] and +max_best_buy before buy
- for every lastSell:
    best_buy[lastSell] = prices[lastSell]+dp[lastBuy]
    max_best_buy[lastSell] = max(max_best_buy[lastSell-1], best_buy[lastSell])
    dp[lastSell] = max(0-prices[lastSell] + max_best_buy[lastSell-1], dp[lastSell-1])
*/

// Algo1 (TL)
class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        vector<int> best_buy(prices.size());
        int ans = 0;
        for (size_t lastSell = 1; lastSell < prices.size(); ++lastSell) {
            for (size_t lastBuy = 0; lastBuy < lastSell; ++lastBuy) {
                if (lastBuy >= lastSell) continue; //<- optimization
                int prevMaxBuy = 0;
                for (size_t i = 0; i+1 < lastBuy; ++i) {
                    if (best_buy[i] > prevMaxBuy) prevMaxBuy = best_buy[i];
                }
                best_buy[lastSell] = max(
                    best_buy[lastSell],
                    (prices[lastSell] - prices[lastBuy]) + prevMaxBuy
                );
            }
            ans = max(ans, best_buy[lastSell]);
        }
        return ans;
    }
};

// Algo2: 116ms
class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        vector<int> best_buy(prices.size());
        vector<int> max_best_buy(prices.size());
        int ans = 0;
        for (size_t lastSell = 1; lastSell < prices.size(); ++lastSell) {
            for (size_t lastBuy = 0; lastBuy < lastSell; ++lastBuy) {
                if (lastBuy >= lastSell) continue; //<- optimization
                best_buy[lastSell] = max(
                    best_buy[lastSell],
                    (prices[lastSell] - prices[lastBuy]) 
                        + (lastBuy > 1 ? max_best_buy[lastBuy-2] : 0)
                );
            }
            ans = max(ans, best_buy[lastSell]);
            max_best_buy[lastSell] = max(max_best_buy[lastSell-1], best_buy[lastSell]);
        }
        return ans;
    }
};

// Algo3: 0ms
class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int> best_buy(prices.size());
        vector<int> max_best_buy(prices.size());
        vector<int> dp(prices.size());
        dp[0] = -prices[0];
        int ans = 0;
        for (size_t lastSell = 1; lastSell < prices.size(); ++lastSell) {
            best_buy[lastSell] = prices[lastSell] + dp[lastSell-1];
            max_best_buy[lastSell] = max(max_best_buy[lastSell-1], best_buy[lastSell]);
            int mbb_prev = lastSell > 1 ? max_best_buy[lastSell-2] : 0;
            dp[lastSell] = max(0-prices[lastSell] + mbb_prev, dp[lastSell-1]);
            ans = max(ans, best_buy[lastSell]);
        }
        return ans;
    }
};

