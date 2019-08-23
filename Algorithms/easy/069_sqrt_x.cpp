/**
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
Example 1:
Input: 4
Output: 2

Example 2:
Input: 8
Output: 2

Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.


sqrt(x) = y
x = y * y

Algo2:
O(log(x))
  l = 0, r = x
  while (r - l > 1):
    m = l + (r - l) / 2
    m2 = m*m
    if x == m2;
      return m
    else if x < m2:
      r = m-1
    else:
      l = m
  return l
*/

class Solution {
public:
    int mySqrt(int x) {
      if (x == 0) return 0;
      if (x < 4) return 1;
      
      int l{0}, r{x};
      while (r - l > 1) {
        int m = l + (r - l) / 2;
        int64_t m2 = int64_t(m) * m;
        if (x == m2) {
          return m;
        } else if (x < m2) {
          r = m;
        } else {
          l = m;
        }
      }
      return l;
    }
};