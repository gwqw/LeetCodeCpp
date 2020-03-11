/**
    338. Counting Bits
Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's 
in their binary representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]

Example 2:
Input: 5
Output: [0,1,1,2,1,2]

Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like 
__builtin_popcount in c++ or in any other language.

Algo1: naive: for every num calc ones independent: O(n*sizeof(integer)) + O(1)

Algo2: make table for parts

Algo3: find dependency
00  0
-----
01  1   +1
-----
10  1   +1
11  2
-----
100 1   +1
101 2
110 2
111 3
Dynamic programming
repeat last and + 1 to everyone
res[0] = 0
prev_pos = 0
for i in 0,n:
    if i is_power_of 2:
        prev_pos = 0
    res[i] = res[prev_pos++] + 1
    
Algo4: dp with bits functions
res[i] = res[i & (i-1)] + 1 # get result for last 1 bit
res[i] = res[i >> 1] + (i & 1)


*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        for (int i = 0; i <= num; ++i) {
            res[i] = countOnes(i);
        }
        return res;
    }
    
private:
    static int countOnes(int n) {
        int ones = 0;
        while (n) {
            n &= n-1;
            ++ones;
        }
        return ones;
    }
};

class Solution {
public:
    Solution() {
        if (ones_16[1] == 0) {
            init();
        }
    }

    vector<int> countBits(int num) {
        vector<int> res(num+1);
        for (int i = 0; i <= num; ++i) {
            uint16_t high = i >> 16;
            uint16_t low = i & 0xFFFFFFFF;
            res[i] = ones_16[high] + ones_16[low];
        }

        return res;
    }
    
private:
    static int countOnes(int n) {
        int ones = 0;
        while (n) {
            n &= n-1;
            ++ones;
        }
        return ones;
    }
    
    void init() {
        for (int i = 0; i < (1<<16); ++i) {
            ones_16[i] = countOnes(i);
        }
    }
    
    static array<uint8_t, 1<<16> ones_16;
    
};
array<uint8_t, 1<<16> Solution::ones_16;

/**
res[0] = 0
prev_pos = 0
for i in 0,n:
    if i is_power_of 2:
        prev_pos = 0
    res[i] = res[prev_pos++] + 1
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        size_t prev_pos = 0;
        for (int i = 1; i <= num; ++i) {
            if ((i & (i-1)) == 0) {
                prev_pos = 0;
            }
            res[i] = res[prev_pos++] + 1;
        }
        return res;
    }
};







