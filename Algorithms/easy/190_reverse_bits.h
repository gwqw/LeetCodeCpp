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
    
Algo: use cache for follow up O(D*N) + O(N), where N - number of calls
- dict: int -> int

*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        constexpr int SIZE = 32;
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

class Solution {
private:
    static constexpr int SIZE = 32;
public:
    
    uint32_t reverseBits(uint32_t n) {
        if (cache.count(n)) {
            return cache[n];
        } else {
            uint32_t res = 0;
            for (int i = 0; i < SIZE; ++i) {
                if (check_bit(n, i)) {
                    set_bit(res, SIZE-1-i);
                }
            }
            cache[n] = res;
            return res;
        }
    }
private:
    static bool check_bit(uint32_t n, int i) {
        return (n >> i) & 1;
    }
    
    static void set_bit(uint32_t& n, int i) {
        n |= (1 << i);
    }
    
    mutable unordered_map<int, int> cache_;
};

