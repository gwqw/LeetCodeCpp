/**
    326. Power of Three
Given an integer, write a function to determine if it is a power of three.

Example 1:
Input: 27
Output: true

Example 2:
Input: 0
Output: false

Example 3:
Input: 9
Output: true

Example 4:
Input: 45
Output: false

Follow up:
Could you do it without using any loop / recursion?

Algo: naive O(log3(N)) + O(1)
- while n > 3 && n % 3 == 0:
    n /= 3
- return n == 3

Algo2: template table
- make a template power and cmp with 3^n

Algo3: max 3^N (N = 19) % n == 0

Algo4:
- 3^N = 3^(0+1+2+4+8+16)
- try to divide on 3^{...}
- 6 steps

*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 0) return false;
        while (n > 2 && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};


template <int N>
int power(int x) {
    return x * power<N-1>(x);
}

template <>
int power<0>(int x) {
    return 1;
}

class Solution {
public:
    bool isPowerOfThree(int n) {
        return (
            n == power<0>(3) ||
            n == power<1>(3) ||
            n == power<2>(3) ||
            n == power<3>(3) ||
            n == power<4>(3) ||
            n == power<5>(3) ||
            n == power<6>(3) ||
            n == power<7>(3) ||
            n == power<8>(3) ||
            n == power<9>(3) ||
            n == power<10>(3) ||
            n == power<11>(3) ||
            n == power<12>(3) ||
            n == power<13>(3) ||
            n == power<14>(3) ||
            n == power<15>(3) ||
            n == power<16>(3) ||
            n == power<17>(3) ||
            n == power<18>(3) ||
            n == power<19>(3)
        );
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};



/*
1 - true; 
2 - false
3 - true
4 - false
5 - false
6 - false
...
9 - true


*/