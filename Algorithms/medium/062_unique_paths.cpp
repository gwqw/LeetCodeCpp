/**
    62. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:
Input: m = 7, n = 3
Output: 28

Constraints:
1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

Algo1: dp: recursion and cache: O(n*m) + O(n*m)
- if n == 1 or m == 1: return 1
- if (n-1,m) not in cache:
    - cache(n-1,m) = unique(n-1,m)
- if (n,m-1) not in cache:
    - cache(n,m-1) = unique(n,m-1)
- return unique(m-1,n) + unique(m, n-1)

Algo2: reverse dp: go from back O(n*m) + O(n*m)
- go from back and fill cache
- cache[m-1][i] = 1 cache[i][n-1] = 1
- cache[i][j] = cache[i+1][j] + cache[i][j+1]
- return cache[0][0]

Algo3: reverse dp: go from back O(n*m) + O(m)
- cache[m-1][i] = 1 cache[i][n-1] = 1
- have prev_row
- go from back and fill cur_row
- cur_row[i][j] = prev_row[j] + cur_row[j+1]
- return cur_row[0]

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n == 1 || m == 1) {
            return 1;
        }
        if (!cache.count({m-1,n})) {
            cache[{m-1,n}] = uniquePaths(m-1,n);
        }
        if (!cache.count({m,n-1})) {
            cache[{m,n-1}] = uniquePaths(m,n-1);
        }
        return cache[{m,n-1}] + cache[{m-1,n}];        
    }
private:
    unordered_map<pair<int,int>, int> cache;
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n == 1 || m == 1) {
            return 1;
        }
        vector<vector<int>> cache(m, vector<int>(n,1));
        for (size_t i = m-1; i-->0; ) {
            for (size_t j = n-1; j-->0; ) {
                cache[i][j] = cache[i+1][j] + cache[i][j+1];
            }
        }
        return cache[0][0];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n == 1 || m == 1) {
            return 1;
        }
        vector<int> prev_row(n, 1);
        vector<int> cur_row(n, 1);
        for (size_t i = m-1; i-->0; ) {
            for (size_t j = n-1; j-->0; ) {
                cur_row[j] = prev_row[j] + cur_row[j+1];
            }
            swap(cur_row, prev_row);
        }
        return prev_row[0];
    }
};


