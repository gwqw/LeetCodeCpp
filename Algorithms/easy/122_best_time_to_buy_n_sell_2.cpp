/**
    122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Algo: dynamic
- state: buying = true
- profit = 0
- buy_price = 0, sell_price = 0
- if is buying:
    - if n[i] <= buy_price: 
        - update buy_price
    - else:
        - state = selling
        - sell_price = n[i]
- else:
    - if n[i] >= sell_price:
         - update selling
    - else:
        profit += sell_price - buy_price
        state = buying
        buy_price = n[i]
we must sell in the end if we buy

  7 1 5 3 6 4
s b b s b s b
bp7 1 1 3 3 4
sp_ _ 5 _ 6 _
p 0 0 0 4 0 7

   1 2 3 4 5
s  b s s s s
bp 1 1 1 1 1
sp _ 2 3 4 5
p  0 0 0 0 0 4

   7 6 4 3 1
s  b b b b b
bp 7 6 4 3 1
sp _ _ _ _ _
p  0 0 0 0 0 0

*/

class Solution {
enum class State {buy, sell};
public:
    int maxProfit(const vector<int>& prices) {
        if (prices.empty()) return 0;
        State state = State::buy;
        int profit = 0;
        int buy_price = prices[0], sell_price = 0;
        for (auto p : prices) {
            if (state == State::buy) {
                if (p <= buy_price) {
                    buy_price = p;
                } else {
                    state = State::sell;
                    sell_price = p;
                }
            } else { // state == sell
                if (p >= sell_price) {
                    sell_price = p;
                } else {
                    state = State::buy;
                    profit += sell_price - buy_price;
                    buy_price = p;
                }
            }
        }
        if (state == State::sell) {
            profit += sell_price - buy_price;
        }
        return profit;
    }
};
 
