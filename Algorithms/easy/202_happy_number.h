/**
    202. Happy Number
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example: 
Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

Algo:
- make a set
- calc next 
- if in set: return false
- else: add to set
- repeat

proof:
can be 2 digit:
max 99 -> 2*81 = 162 (3 digit)
can be 3 digit:
max 999 -> 3*81 = 243 (3 digits)
cannot be more than 3 digit and more than 243
n-digit
9..9 -> n*81: (999 / 81) = 12 (if 12-digit number => no more than 999)
int 2^9 -> will be in in 3digit

*/

class Solution {
public:
    bool isHappy(int n) {
        if (n < 1) {
            return true;
        }
        unordered_set<int> cache{n};
        while (true) {
            n = calc_next(n);
            if (n == 1) {
                return true;
            }
            if (cache.count(n)) {
                return false;
            }
            cache.insert(n);
        }
        return true;
    }
private:
    int calc_next(int n) {
        int res = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            res += d*d;
        }
        return res;
    }
};
