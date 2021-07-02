/**
    887. Super Egg Drop
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:
Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

Example 2:
Input: k = 2, n = 6
Output: 3

Example 3:
Input: k = 3, n = 14
Output: 4

Constraints:
1 <= k <= 100
1 <= n <= 10^4

Algo1: dp[k,n] with memo (recursion) + bin.search
throw_egg(k, n):
    if k == 1: return n
    if n <= 1: return n
    if (k,n) in memo: return memo[(k,n)]
    
    min_attempts = n
    for i in range(1,n+1):
        attempts = max (
            throw_egg(k-1,i-1),
            throw_egg(k, n-i)
            ) + 1
        min_attempts = min(min_attempts, attempts)
    memo[(k,n)] = min_attempts
    return min_attempts

Algo2: dp[moves,K]->n
    for m in [1,???]:
        for k in [1,K]:
            dp[m,k] = dp[m-1,k-1] + dp[m-1,k] + 1 # with one additional move we can determine height = n_lower + n_upper + 1 (current)
        if dp[m,K] >= N: return m
*/

// TLE
class Solution {
public:
    Solution()
        : memo(101, vector<int>(10001, 0))
    {}

    int superEggDrop(int k, int n) {
        if (k == 1) return n;
        if (n <= 1) return n;
        if (memo[k][n]) {
            return memo[k][n];
        }
        
        int min_attempts = n;
        for (int i = 1; i <= n; ++i) {
            int attempts = max(
                superEggDrop(k-1, i-1),
                superEggDrop(k, n-i)
            ) + 1;
            min_attempts = min(min_attempts, attempts);
        }
        memo[k][n] = min_attempts;
        return min_attempts;
    }
    
private:
    vector<vector<int>> memo;
};

// 196ms
class Solution {
public:
    Solution()
        : memo(101, vector<int>(10001, 0))
    {}

    int superEggDrop(int k, int n) {
        if (k == 1) return n;
        if (n <= 1) return n;
        if (memo[k][n]) {
            return memo[k][n];
        }
        
        int min_attempts = n;
        int l = 1, r = n;
        while (l+1 < r) {
            int m = l + (r - l) / 2;
            int broken = superEggDrop(k-1, m-1) + 1;
            int not_broken = superEggDrop(k, n-m) + 1;
            if (broken <= not_broken) {
                l = m;
                min_attempts = min(min_attempts, not_broken);
            } else {
                r = m-1;
                min_attempts = min(min_attempts, broken);
            }
        }
        memo[k][n] = min_attempts;
        return min_attempts;
    }
    
private:
    vector<vector<int>> memo;
};

/*
Algo2: dp[moves,K]->n
    for m in [1,???]:
        for k in [1,K]:
            dp[m,k] = dp[m-1,k-1] + dp[m-1,k] + 1 # with one additional move we can determine height = n_lower + n_upper + 1 (current)
        if dp[m,K] >= N: return m
*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        if (k == 1) return n;
        if (n <= 1) return n;
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
        int m = 0;
        while (dp[k][m] < n) {
            ++m;
            for (int kk=1; kk <= k; ++kk) {
                dp[kk][m] = dp[kk-1][m-1] + dp[kk][m-1] + 1;
            }
        }
        return m;
    }   
};

/*
1
2
2
6
3
14
2
100
4
10000
*/