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
*/

class Solution {
public:
    int reverse(int x) {
      bool is_minus = false;
      if (x <= INT32_MIN) {return 0;}
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