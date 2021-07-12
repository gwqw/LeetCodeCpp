/**
    29. Divide Two Integers
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, assume that your function returns 2^31 − 1 when the division result overflows.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.

Example 3:
Input: dividend = 0, divisor = 1
Output: 0

Example 4:
Input: dividend = 1, divisor = 1
Output: 1

Constraints:
-2^31 <= dividend, divisor <= 2^31 - 1
divisor != 0

Algo1: bf: -divisor and count

Algo2: binary search
while (divisor < dividend):
    divisor = divisor * divisor
    cnt += cnt
dividend -= divisor
repeat

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend != -2147483648 ? -dividend : 2147483647;
        int res = 0;
        if (dividend == -2147483648) {
            if (divisor > 0) {
                dividend += divisor;
            } else {
                dividend -= divisor;
            }
            ++res;
        }
        if (divisor == -2147483648) {
            return dividend == -2147483648 ? 1 : 0;
        }
        bool is_neg = dividend < 0 ^ divisor < 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor) {
            dividend -= divisor;
            ++res;
        }
        return is_neg ? -res : res;
    }
};

class Solution {
    static constexpr int HALF_INT_MAX = 1073741824;
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend != -2147483648 ? -dividend : 2147483647;
        int res = 0;
        if (divisor == -2147483648) {
            return dividend == -2147483648 ? 1 : 0;
        }
        if (dividend == -2147483648) {
            if (divisor > 0) {
                dividend += divisor;
            } else {
                dividend -= divisor;
            }
            ++res;
        }
        bool is_neg = dividend < 0 ^ divisor < 0;
        dividend = abs(dividend);
        divisor = abs(divisor);

        while (dividend >= divisor) {
            int new_div = divisor;
            int cnt = 1;
            while (new_div < HALF_INT_MAX && new_div+new_div <= dividend) {
                new_div += new_div;
                cnt += cnt;
            }
            dividend -= new_div;
            res += cnt;
        }
        return is_neg ? -res : res;
    }
};

10
3
7
-3
0
1
1
1
1000000000
2
10
1
-2147483648
-1
-2147483648
2
-2147483648
4
-2147483648
-3
-1010369383
-2147483648