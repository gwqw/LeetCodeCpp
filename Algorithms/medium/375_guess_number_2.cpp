/**
    375. Guess Number Higher or Lower II
We are playing the Guessing Game. The game will work as follows:
I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

Example 1:
Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.

Example 2:
Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.

Example 3:
Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.

Constraints:
1 <= n <= 200

Algo1: don't work :-(
sum(n^2) / sum(n) = n * (n+1)(2n+1)/ 6 // n (n+1) / 2 = (2n+1) / 3
ave = (2*10+1)/3 = 7

sum[k,n] = n(n+1)/2 - (k-1)k/2
sum2[k,n] = n(n+1)(2n+1)/6 - (k-1)k(2k-1)/6
ave[k,n] = sum2[k,n] / sum[k,n]

Algo2: dp for all: [l, r]: O(N^3)
dp[l, r] -> min_money for range
dp[l,r] (where l == r) = 0
max_money = 0
for l in range(1,n):
    dp[l][l+1] = l 
    max_money = max(max_money, l)
for l in range(1,n+1):
    for len in range(3,n):
        r = l + len - 1
        if r > n: break
        dp[l][r] = INT_MAX
        for m in range [l, r]:
            if m == l:
            dp[l][r] = min(dp[l][m-1], max(dp[l][m-1], dp[m+1][r]) + m)
        max_money = max(max_money, dp[l][r])

*/

class Solution {
public:
	int getMoneyAmount(int n) {
		return guess(1,n);
	}
	
private:
	int guess(int k, int n) {
		if (k >= n) return 0;
		int m = ave(k, n);
        return m + max(guess(k, m-1), guess(m+1, n));
	}

	static int sum(int k, int n) {
		return n*(n+1)/2 - (k-1)*k/2;		
	}
	
	static int sum2(int k, int n) {
		return n*(n+1)*(2*n+1)/6 - (k-1)*k*(2*k-1)/6;
	}
	
	static int ave(int k, int n) {
        return sum2(k, n) / sum(k, n);
	}
};

class Solution {
public:
	int getMoneyAmount(int n) {
	    if (n == 1) return 0;
		vector<vector<int>> dp(n+1, vector<int>(n+1));
		for (int l = 1; l < n; ++l) {
		    dp[l][l+1] = l;
		}
		
		for (int len = 3; len <= n; ++len) {
		    for (int l = 1; l+1 < n; ++l) {
		        int r = l + len - 1;
		        if (r > n) break;
		        dp[l][r] = dp[l+1][r] + l;
		        for (int m = l+1; m < r; ++m) {
		            dp[l][r] = min(
		                dp[l][r],
		                max(dp[l][m-1], dp[m+1][r]) + m
		            );
		        }
		        dp[l][r] = min(dp[l][r], dp[l][r-1]+r);
		    }
		}
		return dp[1][n];
	}
};



