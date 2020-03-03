/**
    461. Hamming Distance
The Hamming distance between two integers is the number of positions 
at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
          ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Algo:
- xor nums
- calc ones

*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        return countOnes(x ^ y);
    }
    
private:
    int countOnes(int n) {
        int ones = 0;
        while (n > 0) {
            n &= n-1;
            ++ones;
        }
        return ones;
    }
};
