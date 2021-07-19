/**
    1277. Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

Algo1: dp of square size: O(N^3)
for s in 1, n:
    if a[i][j] >= s-1 && a[i][j+s-1] >= s-1 && ...
        a[i][j] = s
        
Algo2: dp like max square size: O(N^2)
dp[i,j] -> max_sq_size
dp[i,j] = min(dp[i][j-1], dp[i-1][j-1], dp[i-1][j])+1
cnt += dp[i,j]

*/

class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int cnt = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < a[0].size(); ++j) {
                if (a[i][j] == 1) ++cnt;
            }
        }
        for (size_t len = 2; len <= a.size(); ++len) {
            for (size_t i = 0; i+len-1 < a.size(); ++i) {
                for (size_t j = 0; j+len-1 < a[0].size(); ++j) {
                    if (a[i][j] >= len-1 && a[i][j+1] >= len-1 
                    && a[i+1][j] >= len-1 && a[i+1][j+1] >= len-1) {
                        a[i][j] = len;
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int cnt = 0;
        vector<vector<int>> dp(a.size(), vector<int>(a[0].size()));
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i][0] == 1) {
                dp[i][0] = a[i][0];
                ++cnt;
            }
        }
        for (size_t j = 1; j < a[0].size(); ++j) {
            if (a[0][j] == 1) {
                dp[0][j] = a[0][j];
                ++cnt;
            }
        }
        for (size_t i = 1; i < a.size(); ++i) {
            for (size_t j = 1; j < a[0].size(); ++j) {
                if (a[i][j] == 1) {
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]}) + 1;
                    cnt += dp[i][j];
                }
            }
        }
        return cnt;
    }
};
