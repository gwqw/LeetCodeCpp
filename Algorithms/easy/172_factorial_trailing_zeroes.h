/**
    172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.

Example 1:
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Algo: log(n)
- zeroes count ~ 5 count + 25 count + 125 count + ...

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes = 0;
        while (n > 0) {
            n /= 5;
            zeroes += n;
        }
        return zeroes;
    }
};
