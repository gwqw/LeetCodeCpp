/**
    168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

Example 1:
Input: 1
Output: "A"

Example 2:
Input: 28
Output: "AB"

Example 3:
Input: 701
Output: "ZY"

Algo: 26-numeric system: O(log(N))
- dec(n): --n;
- take digit: int d = n % 26
- remove digit: n /= 26
- conv digit to letter 0->A, .. 25->Z => char(A+d)
- add letter to res
- reverse res

1..26 -> A..Z
26+1..26*2 -> AA..AZ
26*2+1..26*3 -> BA..BZ


*/

class Solution {
    static constexpr int ALPHABET_SIZE = 26;
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            n--;
            int d = n % ALPHABET_SIZE;
            n /= ALPHABET_SIZE;
            char letter = char('A' + d);
            res += letter;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};