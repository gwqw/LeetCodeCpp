/**
    171. Excel Sheet Column Number
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:
Input: "A"
Output: 1

Example 2:
Input: "AB"
Output: 28

Example 3:
Input: "ZY"
Output: 701

Algo:

A -> 0 + 1
Z -> 25 + 1
AA -> 26*1 + 0 + 1 = 27

Algo:
- conver letter to digit: digit = letter -'A' + 1
- multiply res on 26
- add digit to res

*/

class Solution {
public:
    int titleToNumber(const string& s) {
        int res = 0;
        for (auto c : s) {
            int digit = c - 'A' + 1;
            res *= 26;
            res += digit;
        }
        return res;
    }
};


