/**
    190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

Example 1:
Input:  00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 
represents the unsigned integer 43261596, so return 964176192 
which its binary representation is 00111001011110000010100101000000.

Example 2:
Input:  11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 
represents the unsigned integer 4294967293, so return 3221225471 
which its binary representation is 10111111111111111111111111111111.

Note:
Note that in some languages such as Java, there is no unsigned integer type. 
In this case, both input and output will be given as signed integer type and should not affect your implementation, 
as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. 
Therefore, in Example 2 above the input represents the signed integer -3 and the output represents the signed integer -1073741825.

Follow up:
If this function is called many times, how would you optimize it?

Algo: naive: convert to string: O(D) + O(D)
- convert to string and reverse, convert to number

Algo: use bit-operations: O(D) + O(1)
- for i bit in range(32):
    bit = check_bit(n,i)
    if (bit): set_bit(res, 31-i) to res
- return res
    
Algo: like for 10th:
- find digit: d = n %10
- add digit to res: res = res * 10 + d
- n /= 10
make for 2:
- d = n & 1
- res = (res << 1) | d
- n >>= 1

Algo: follow up: make table in ctor (16_16, 10_12_10, 8_8_8_8)
- make an array for 16bit number -> 16 reverse
    - rev2[1<<2] = {0, 2, 1, 3}; // 00 -> 00, 01 -> 10, 10 -> 01, 11 -> 11
    - rev4[1<<4];
    - for hi in range(1<<2):
        - for lo in range(1<<2):
            rev4[hi<<2|lo] = rev2[lo]<<2 | rev2[hi]
    - same for rev[8] and rev[16]
- hi = n >> 16
- lo = n << 16
- res = (rev16[lo] >> 16) | rev16[hi]


*/

// 4*32 bit operations
class Solution {
    static constexpr int SIZE = 32;
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < SIZE; ++i) {
            if (check_bit(n, i)) {
                set_bit(res, SIZE-1-i);
            }
        }
        return res;
    }
private:
    static bool check_bit(uint32_t n, int i) {
        return (n >> i) & 1;
    }
    
    static void set_bit(uint32_t& n, int i) {
        n |= (1 << i);
    }
};

// 4*32 bit operations
class Solution {
private:
    static constexpr int SIZE = 32;
public:

    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < SIZE; ++i) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }
};

// 5op * 5parts = 25 bit operations
class Solution {
private:
    static constexpr int SIZE = 32;
public:

    uint32_t reverseBits(uint32_t n) {
        // 16
        n = ((n & 0xFFFF0000) >> 16)
          | ((n & 0x0000FFFF) << 16);
        // 8
        n = ((n & 0xFF00FF00) >> 8)
          | ((n & 0x00FF00FF) << 8);
        //4
        n = ((n & 0xF0F0F0F0) >> 4)
          | ((n & 0x0F0F0F0F) << 4);
        // 2
        n = ((n & 0b11001100110011001100110011001100) >> 2)
          | ((n & 0b00110011001100110011001100110011) << 2);
        // 1
        n = ((n & 0b10101010101010101010101010101010) >> 1)
          | ((n & 0b01010101010101010101010101010101) << 1);
        
        return n;
    }
};

class Solution {
private:
    static constexpr int SIZE = 32;
    static uint16_t rev16[1<<16];
public:

    Solution() {
        if (rev16[1] == 0) {
            uint16_t rev2[1<<2] = {0, 2, 1, 3};
            
            uint16_t rev4[1<<4];
            for (uint16_t hi = 0; hi < (1<<2); ++hi) {
                for (uint16_t lo = 0; lo < (1<<2); ++lo) {
                    rev4[hi<<2|lo] = rev2[lo]<<2 | rev2[hi];
                }
            }
            
            uint16_t rev8[1<<8];
            for (uint16_t hi = 0; hi < (1<<4); ++hi) {
                for (uint16_t lo = 0; lo < (1<<4); ++lo) {
                    rev8[hi<<4|lo] = rev4[lo]<<4 | rev4[hi];
                }
            }
            
            
            for (uint16_t hi = 0; hi < (1<<8); ++hi) {
                for (uint16_t lo = 0; lo < (1<<8); ++lo) {
                    rev16[hi<<8|lo] = rev8[lo]<<8 | rev8[hi];
                }
            }
        }
    }

    uint32_t reverseBits(uint32_t n) {
        uint16_t hi = n >> 16;
        uint16_t lo = n & 0x0000FFFF;
        return rev16[lo] << 16 | rev16[hi];
    }
};

uint16_t Solution::rev16[1<<16];


