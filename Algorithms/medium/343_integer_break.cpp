/**
    343. Integer Break
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

Constraints:
2 <= n <= 58

Algo: math O(1), O(1)mem
1) split on k nums: each num must be equal: n/k (last element n/k + residual)
2) k = n/e ~ n/3 (from diff (n/k)^k )
or
1) if n > 4: 2*(n-2) > n => n > 4, so n/k <= 4 (4 = 2*2, so n/k < 4)
2) if n > 3: 1 is bad: (n-1)*1 < n: so 2 <= n/k <= 3
3) 2*2*2 < 3*3, so count(2) <= 2
res = 3*3*3...*3*2*2, 2 can be 0, 1, 2

1) n % 3 = 0
k = n/3 => prod = 3^k
n > 3 (n=3: 2)
2) n % 3 = 1
k = (n-4)/3 -> prod = 3^k*4
n > 4 (n=4: 4)
3) n % 3 = 2
k = (n-2)/3 => prod = 3^k*2
n > 2 (n=2: 1)


Algo2: dp O(N^2), O(N) mem
max_product(n) 
for i in 2..n:
    max_product(n) = max(max_product[n], i*max_product[n-i])
*/

class Solution {
public:
    int integerBreak(int n) {
		if (n < 9) {
			return prod[n];
		}
		if (n % 3 == 0) {
			int k = n / 3;
			return pow(3,k);
		}
		if (n % 3 == 1) {
			int k = (n-4)/3;
			return pow(3,k) * 4;
		}
		if (n % 3 == 2) {
			int k = (n - 2) / 3;
			return pow(3, k) * 2;
		}
		throw runtime_error("Bad number");
    }
private:
	static array<int, 9> prod;
};

array<int, 9> Solution::prod = {0, 0, 1, 2, 4, 6, 9, 12, 18};
