/**
    258. Add Digits
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:
Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Algo1: O(N)
- s = 0
- while true:
    - while n > 0:
        - s += n % 10
        - n/= 10
    - if sum < 10: break
    - n = s
    - s = 0
  - return s
  
Algo2: O(1)
n - dig_sum = sum(di * (10^i-1)) => (n - dig_sum) % 9 = 0 => n % 9 == dig_sum % 9
if n == 0: return 0
if n % 9 == 0: return 9
else: return n % 9
*/

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while (true) {
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            if (sum < 10) break;
            num = sum;
            sum = 0;
        }
        return sum;
    }
};

class Solution {
public:
    int addDigits(int n) {
        if (n == 0) return 0;
        if (n % 9 == 0) return 9;
        else return n % 9;
    }
};

class Solution {
public:
    int addDigits(int n) {
        if (n == 0) return 0;
        n %= 9;
        if (n == 0) return 9;
        else return n;
    }
};


