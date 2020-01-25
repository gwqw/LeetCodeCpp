/**
    342. Power of Four
Given an integer (signed 32 bits), 
write a function to check whether it is a power of 4.

Example 1:
Input: 16
Output: true

Example 2:
Input: 5
Output: false

Follow up: Could you solve it without loops/recursion?

Algo1: naive log(N)
- n <= 0: false
- while n > 1: 
- check n % 4 == 0: false -> false
- n /= 4
- return true

Algo2: use log for degrees: O(log(log(N)))
2^32 = 4^16 => max degree: 15
15 = 8 + 4 + 2 + 1
check % on {4^8, 4^4, 4^2, 4^1}
if all % r in range and res /= == 1 => true;

Algo3: float calculation: sqrt
- if n not power of 2: return false
- sqrt(2^n) = 2^(n/2)

Algo4: is power of 2 and bit mask
bit mask 0101010101010101 -> to hex (4 bits) 0101 -> 0x5
0x55555555
(n & mask) != 0 or == n
or can take mask 101010..
0xAAAAAAAA
(n & mask) == 0

Algo5: math % 3
power of 2
1 % 3 = 1
2 % 3 = 2
4 % 3 = 1
8 % 3 = 2
16 % 3 = 1
32 % 3 = 2
64 % 3 = 1
if (n % 3) == 1: 
    m = n * 2
    m % 3 = 2 * (n % 3) == 2


00000000 -> 0
00000100 -> 4
00010000 -> 16
01000000 -> 64

1 -> true
2,3 -> false
4 -> 1 -> true
5-7 -> false
8 -> 2
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        if (n >= 65536) {
            if (n % 65536 != 0) return false;
            n /= 65536;
        }
        
        if (n >= 256) {
            if (n % 256 != 0) return false;
            n /= 256;
        }
        
        if (n >= 16) {
            if (n % 16 != 0) return false;
            n /= 16;
        }
        
        if (n >= 4) {
            if (n % 4 != 0) return false;
            n /= 4;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0 || (n & (n - 1)) != 0) {
            return false;
        }
        int sq = lround(sqrt(n));
        return sq * sq == n;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0 || (n & (n - 1)) != 0) {
            return false;
        }
        int mask = 0x55555555;
        return (n & mask) != 0;
    }
};
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0 || (n & (n - 1)) != 0) {
            return false;
        }
        int mask = 0xAAAAAAAA;
        return (n & mask) == 0;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};



