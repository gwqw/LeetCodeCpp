/**
12. Integer to Roman
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: 3
Output: "III"

Example 2:
Input: 4
Output: "IV"

Example 3:
Input: 9
Output: "IX"

Example 4:
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution {
public:
  /*string intToRoman(int num) {
      string res;
      int degree = 0;
      while (num > 0) {
          int digit = num % 10;
          num /= 10;
          if (digit == 0) {degree++; continue;}
          auto& m = i2r[degree];
          if (digit <= 3) {
              string s(digit, m[1]);
              res = s + res;
          } else if (digit == 4) {
              res = string(1, m[1]) + m[5] + res;
          } else if (digit <= 8) {
              string s(digit-5, m[1]);
              res = string(1, m[5]) + s + res;
          } else {
              res = string(1, m[1]) + m[10] + res;
          }
          degree++;
      }
      return res;
  }
    vector<unordered_map<int, char>> i2r = {
      {{1, 'I'}, {5, 'V'}, {10, 'X'}},
      {{1, 'X'}, {5, 'L'}, {10, 'C'}},
      {{1, 'C'}, {5, 'D'}, {10, 'M'}},
      {{1, 'M'}, {5, '\0'}, {10, '\0'}},
  };
  */
  string intToRoman(int num) {
      string res;
      res.reserve(8);
      int degree = 0;
      while (num > 0) {
          int digit = num % 10;
          num /= 10;
          if (digit == 0) {degree++; continue;}
          auto& m = i2r[degree];
          res += m[digit];
          degree++;
      }
      reverse(res.begin(), res.end());
      return res;
  }
  // reversed
  array<string, 10> i2r[4] = {
      {"", "I", "II", "III", "VI", "V", "IV", "IIV", "IIIV", "XI"},
      {"", "X", "XX", "XXX", "LX", "L", "XL", "XXL", "XXXL", "CX"},
      {"", "C", "CC", "CCC", "DC", "D", "CD", "CCD", "CCCD", "MC"},
      {"", "M", "MM", "MMM", "", "", "", "", "", ""}
  };
};