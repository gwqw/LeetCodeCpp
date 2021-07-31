/**
    1134. Armstrong Number
Given an integer n, return true if and only if it is an Armstrong number.
The k-digit number n is an Armstrong number if and only if the kth power of each digit sums to n.

Example 1:
Input: n = 153
Output: true
Explanation: 153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.

Example 2:
Input: n = 123
Output: false
Explanation: 123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.

Constraints:
1 <= n <= 10^8
*/

class Solution {
public:
    bool isArmstrong(int n) {
        int num = n;
        string s = to_string(n);
        int k = s.size();
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += pow(digit, k);
        }
        return sum == num;
    }
};