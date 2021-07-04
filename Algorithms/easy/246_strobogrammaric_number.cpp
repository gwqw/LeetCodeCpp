/**
    246. Strobogrammatic Number
Given a string num which represents an integer, return true if num is a strobogrammatic number.
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Example 1:
Input: num = "69"
Output: true

Example 2:
Input: num = "88"
Output: true

Example 3:
Input: num = "962"
Output: false

Example 4:
Input: num = "1"
Output: true

Constraints:
1 <= num.length <= 50
num consists of only digits.
num does not contain any leading zeros except for zero itself.

Algo: is_palindromic
convert to to string
check for is palindromic with ==-operator
also check middle for odd string
==:
return l: (1,1), (8,8), (0,0), (6,9), (9,6)
*/

class Solution {
public:
    bool isStrobogrammatic(string_view num) {
        for (size_t i = 0; i < (num.size()+1) / 2; ++i) {
            if (!isEqual(num[i], num[num.size()-i-1])) return false;
        }
        return true;
    }
    
private:
    bool isEqual(char l, char r) {
        return 
            l == '0' && r == '0' ||
            l == '1' && r == '1' ||
            l == '8' && r == '8' ||
            l == '6' && r == '9' ||
            l == '9' && r == '6';
    }
};