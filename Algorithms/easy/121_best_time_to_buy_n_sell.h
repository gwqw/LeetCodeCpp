/**
    121. Best Time to Buy and Sell Stock
    
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Algo1: O(N) + O(1)
7 1 5 3 6 4 got and write left min for every value 
7 1 1 1 1 1 calc diff
0 0 4 2 5 3 find max diff
        ^
We don't need to save all diffs, so calc diff on each step and update max_diff

Algo2: O(N) + O(1)
the same, but use more complicated scheme
- recurrently calc diff between 1-st element and current: diff(i+1) += diff(i) + x[i+1] - x[i]
- if diff < 0:
    update min: diff = 0 (so next recur. diff will be calculated from this element)
- else if diff < max_diff:
    - update max_diff

*/

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if (prices.empty()) return 0;
        int max_diff = 0;
        int min_value = prices[0];
        for (auto p : prices) {
            if (p < min_value) {
                min_value = p;
                continue;
            }
            int diff = p - min_value;
            if (diff > max_diff) max_diff = diff;
        }
        return max_diff;
    }
};
