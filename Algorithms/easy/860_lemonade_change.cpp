/**
    860. Lemonade Change
At a lemonade stand, each lemonade costs $5. 
Customers are standing in a queue to buy from you, 
and order one at a time (in the order specified by bills).
Each customer will only buy one lemonade 
and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer, 
so that the net transaction is that the customer pays $5.
Note that you don't have any change in hand at first.
Return true if and only if you can provide every customer 
with correct change.

Example 1:
Input: [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Example 2:
Input: [5,5,10]
Output: true

Example 3:
Input: [10,10]
Output: false

Example 4:
Input: [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, 
we collect a $10 bill and give back a $5 bill.
For the last customer, we can't give change of $15 back 
because we only have two $10 bills.
Since not every customer received correct change, the answer is false.

Note:
0 <= bills.length <= 10000
bills[i] will be either 5, 10.

Algo: O(N) + O(1)
- make 2 vars c5 and c10
- if 5: inc c5
- if 10: inc c10, dec c5
- if 20: try dec c10 and c5 else try 3 dec c5
- if cannot dec: return false
- else return true
*/

class Solution {
 public:
    bool lemonadeChange(const vector<int>& bills) {
        int c5 = 0, c10 = 0;
        for (auto b : bills) {
            if (b == 5) {
                ++c5;
            } else if (b == 10) {
                if (c5 == 0) return false;
                ++c10;
                --c5;
            } else if (b == 20) {
                if (c10 != 0) {
                    if (c5 == 0) return false;
                    --c10;
                    --c5;
                } else if (c5 >= 3) {
                    c5 -= 3;
                } else {
                    return false;
                }
            } else {
                throw logic_error("coin with value != 5, 10 or 20");
            }
        }
        return true;
    }
};


