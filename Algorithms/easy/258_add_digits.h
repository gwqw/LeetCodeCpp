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
*/

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while (true) {
            while (num > 0) {
                sum += num % 10;
                if (sum
                num /= 10;
            }
            if (sum < 10) break;
            num = sum;
            sum = 0;
        }
        return sum;
    }
};
