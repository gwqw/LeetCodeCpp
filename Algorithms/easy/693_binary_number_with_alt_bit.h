/**
    693. Binary Number with Alternating Bits

Given a positive integer, check whether it has alternating bits: 
namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101

Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.

Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.

Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.

Algo:
0101010
1010100 <<
-------
111111x >>
0111111 = r

n | r = n
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int r = n ^ (n << 1);
        r >>= 1;
        return (r & (r+1)) == 0;
    }
};
