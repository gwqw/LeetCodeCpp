/**
    191. Number of 1 Bits
Write a function that takes an unsigned integer and return the number of '1' bits it has 
(also known as the Hamming weight).

Example 1:
Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Example 2:
Input: 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

Example 3:
Input: 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

Note:
Note that in some languages such as Java, there is no unsigned integer type. 
In this case, the input will be given as signed integer type and should not affect your implementation, 
as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. 
Therefore, in Example 3 above the input represents the signed integer -3.

Follow up:
If this function is called many times, how would you optimize it?

Algo: naive: O(N)(?) + O(1)
- go through and calc bits

Algo: same as naive: O(ones) + O(1)
- n & (n-1) removes last one
- repeat ^ while n > 0 and inc(counter)

0   0
1   1
2   1
3   2
4   1
5   2  
6   2
7   3
8   1   1000
9   2   1001
10  2   1010
11  3   1011
12  2   1100
13  3   1101
14  3   1110
15  4   1111

*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        while (n > 0) {
            ones += (n & 1);
            n >>= 1;
        } 
        return ones;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // https://en.wikipedia.org/wiki/Hamming_weight
        int ones = 0;
        while (n > 0) {
            n &= n-1;
            ++ones;
        } 
        return ones;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};

class Solution {
public:
    Solution() {
        if (ones16[1] == 1) return;
        init_simple();
    }

    int hammingWeight(uint32_t n) {
        uint16_t n1 = (n & 0x0000FFFF);
        uint16_t n2 = n >> 16;
        return ones16[n1] + ones16[n2];
    }
    
private:
    
    static uint16_t ones16[65536];
    
    static void init_simple() {        
        for (int i = 0; i < 65536; ++i) {
            uint16_t ones = 0;
            uint16_t n = i;
            while (n > 0) {
                n &= n-1;
                ++ones;
            }
            ones16[i] = ones;
        }
    }
    
    static void init() {        
        uint8_t ones4[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
        uint8_t ones8[1<<8];
        for (uint8_t i = 0; i < (1<<8); ++i) {
            ones8[i] = ones4(i << 0xF) + ones4(i >> 0xF);
        }
        
        for (uint16_t i = 0; i < (i << 16); ++i) {
            ones16[i] = ones8[i << 0xFF] + ones8[i >> 0xFF];
        }
    }
};

/*
4 -- 16
8 -- 256
16 -- 65536
32 -- 4*10^9
*/
