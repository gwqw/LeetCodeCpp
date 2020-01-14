/**
    7. Reverse Integer
    Given a 32-bit signed integer, reverse digits of an integer.
    ex1. 
        Input: 123
        Output: 321
    Example 2:
        Input: -123
        Output: -321
    Example 3:
        Input: 120
        Output: 21
        
Algo: O(D)
- save sign -> is_minus
- take digit: d = n % 10
- remove digit n /= 10
- check for overflow
- add digit to res: res = res*10 + d
- repeat while n != 0
- 
*/

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool is_minus = false;
        if (x < 0) { is_minus = true; x = -x;}
        int res = 0;
        while (x > 0) {
            char digit = x % 10;
            x /= 10;
            if (res < INT32_MAX / 10 || (res == INT32_MAX / 10 && digit <= INT32_MAX % 10)) {
                res = res*10 + digit;
            } else {
                return 0;
            }
        }
        if (is_minus) {res = -res;}
        return res;
    }
};
