/**
    371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = -2, b = 3
Output: 1

Algo1: matherr
sum = log(exp(a)*exp(b))

Algo2: digit
- take digits
- calc sum as xor
- calc shift as (d1 & d2 << 1)
- if shift == 0: break
- go further

*/

class Solution {
public:
    int getSum(int a, int b) {
        constexpr auto MASK = 0x1'00'00'00'00ul;
        int res = (a ^ b) % MASK;
        int shift = ((a & b) << 1) % MASK;
        while (shift) {
            int new_res = (res ^ shift) % MASK;
            shift = ((shift & res) << 1) % MASK;
            res = new_res;
        }
        return res;
    }
};
