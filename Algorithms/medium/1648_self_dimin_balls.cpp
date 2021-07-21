/**
    1648. Sell Diminishing-Valued Colored Balls
You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).

You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.

Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: inventory = [2,5], orders = 4
Output: 14
Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
The maximum total value is 2 + 5 + 4 + 3 = 14.

Example 2:
Input: inventory = [3,5], orders = 6
Output: 19
Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.

Example 3:
Input: inventory = [2,8,4,10,6], orders = 20
Output: 110

Example 4:
Input: inventory = [1000000000], orders = 1000000000
Output: 21
Explanation: Sell the 1st color 1000000000 times for a total value of 500000000500000000. 500000000500000000 modulo 109 + 7 = 21.

Constraints:
1 <= inventory.length <= 10^5
1 <= inventory[i] <= 10^9
1 <= orders <= min(sum(inventory[i]), 10^9)

Algo: max heap
pq(inventory)
num = pq.pop()
cnt = 1
while !pq.empty():
	while !pq.empty() and pq.top() == num:
		pq.pop()
		++cnt
	prev = not pq.empty() ? pq.top() : 0
	low = min(num - prev + 1, num - order)
	sum += cnt * Sum(low, num)
	order -= num - low
	if order == 0: return sum
	num = low-1
*/

class Solution {
    static constexpr int P = (int)1e9 + 7;
public:
    int maxProfit(const vector<int>& inventory, int order) {
        priority_queue<int> pq;
        for (int i : inventory) {
            pq.push(i);
        }        
		int num = pq.top();
		pq.pop();
		int cnt = 1;
		long sum = 0;
		while (!pq.empty() || order) {
			while (!pq.empty() && pq.top() == num) {
				pq.pop();
				++cnt;
			}
			int prev = !pq.empty() ? pq.top() : 0;
			int full_sell_cnt = min(order / cnt, num - prev);
			int low = num - full_sell_cnt;
			sum = mplus(sum, mmult(cnt, Sum(low+1, num)));
			order -= full_sell_cnt * cnt;
			if (order == 0) return sum % P;
			num = low;
			if (num > prev) {
				assert(order < cnt);
				sum = mplus(sum, mmult(order, num));
				return sum % P;
			}
		}
		return sum % P;
    }
	
private:
	long Sum(long low, long high) {
        return (high - low + 1) * (high + low) / 2;
		//return mmult((high - low + 1), mplus(high, low)) / 2;
	}
    
    long mplus(long l, long r) {
        l %= P;
        r %= P;
        return (l+r)%P;
    }
    
    long mmult(long l, long r) {
        l %= P;
        r %= P;
        return (l*r)%P;
    }
};