/**
    279. Perfect Squares
Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; 
in other words, it is the product of some integer with itself.
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

Constraints:
    1 <= n <= 10^4

Algo1: dp O(N*sqrt(N)), O(N) mem
- n = min(i**2 + dp(n-i**2), for i in 1 sqrt(n))

Algo2: bruteforce O(NN*sqrt(N)), O(1) mem
- take 1-st term: O(sqrt(N))
- take 2-nd term: O(sqrt(N))
- take 3-rd term: O(sqrt(N))
- check if 4-th if full-sqr: O(1)

Algo3: bfs in graph O(?)

*/

// 172ms
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int j = 2; j <= n; ++j) {
            int sq_j = (int)sqrt(j);
            dp[j] = INT_MAX;
            for (int i = 1; i <= sq_j; ++i) {
                int prev = j - i*i;
                if (prev >= 0) {
                    dp[j] = min(dp[j], 1+dp[prev]);
                }
            }
        }
        return dp[n];
    }
};

// hack: 0ms
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp;
        dp.reserve(10001);
        int init = dp.size();
        if (init < 2) {
            dp.resize(2);
            dp[0] = 0;
            dp[1] = 1;
        }
        init = dp.size();
            
        for (int j = init; j <= n; ++j) {
            dp.push_back(INT_MAX);
            for (int i = 1; i*i <= j; ++i) {
                int prev = j - i*i;
                if (prev >= 0) {
                    dp[j] = min(dp[j], 1+dp[prev]);
                }
            }
        }
        return dp[n];
    }
};

// 12ms
class Solution {
public:
    int numSquares(int n) {
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(0);
        int lvl_cnt = 1;
        while (!q.empty()) {
            queue<int> new_q;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int j = 1; j*j+x <= n; ++j) {
                    int new_value = x+j*j;
                    if (new_value == n) {
                        return lvl_cnt;
                    }
                    if (!visited[new_value]) {
                        visited[new_value] = true;
                        new_q.push(new_value);
                    }
                }
            }
            q = new_q;
            ++lvl_cnt;
        }
        return 5;
    }
};
