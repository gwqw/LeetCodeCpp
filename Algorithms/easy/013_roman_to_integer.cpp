/**
13. Roman to Integer
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
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: "III"
Output: 3

Example 2:
Input: "IV"
Output: 4

Example 3:
Input: "IX"
Output: 9

Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Algo:
- make dict: char -> num
- go through string from second char [1]
- check if prev digit > curr digit
    - add prev digit
- else:
    - substruct prev digit
- add last digit to res
*/

class Solution {
public:
    int romanToInt(const string& s) {
        int res = 0;
        if (s.empty()) {return res;}
        for (auto it = next(begin(s)); it < end(s); ++it) {
            if (r2i.at(*prev(it)) >= r2i.at(*it)) {
                res += r2i.at(*prev(it));
            } else {
                res -= r2i.at(*prev(it));
            }
        }
        res += r2i.at(s.back());
        return res;
    }
private:
    const static unordered_map<char, int> r2i;
};
const unordered_map<char, int> Solution::r2i = {{'I', 1}, {'V', 5}, {'X', 10}, 
    {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

class Solution {
public:
    int romanToInt(const string& s) {
        int res = 0;
        if (s.empty()) {return res;}
        int p = r2i(*s.begin());
        for (auto it = next(begin(s)); it < end(s); ++it) {
            int c = r2i(*it);
            if (p >= c) {
                res += p;
            } else {
                res -= p;
            }
            p = c;
        }
        res += r2i(s.back());
        return res;
    }
    
private:
    static int r2i(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};

