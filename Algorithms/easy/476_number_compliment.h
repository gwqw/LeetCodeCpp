/**
    476. Number Complement

Given a positive integer, output its complement number. 
The complement strategy is to flip the bits of its binary representation.
Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.

Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

Algo1:
- go from begin while bit is 0:
- number << n 
- !number
- number >> n

Algo2: binary search
100     shl
101     num
1000    shr
shl <= num < shr
shl = 0, shr = 31
while shr - shl > 1:
    - m = (shl + shr) / 2
    - num cmp 1 << m
101
111 xor
010

(1 << shl) + ((1 << shl)-1)
10000 + 1111

Algo3: 
mask = num
001????
mask |= mask >> 1;
0011???
mask |= mask >> 2;
...
mask |= mask >> 16;


*/

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int pos = 1;
        for (; pos < 32; ++pos) {
            if (num & (1 << (32 - pos - 1))) break;            
        }
        num <<= pos;
        num = ~num;
        num >>= pos;
        
        return num;
    }
};

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        
        int shl = 0, shr = 31;
        while (shr - shl > 1) {
            int m = (shl + shr) / 2;
            if (num < (1 << m)) {
                shr = m;
            } else {
                shl = m;
            }
        }
        
        //int pos = 32 - shl;
        //num <<= pos;
        //num = ~num;
        //num >>= pos;
        int mask = (1 << shl) + ((1 << shl) - 1);
        num ^= mask;
        
        return num;
    }
};

