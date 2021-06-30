/**
    1351. Count Negative Numbers in a Sorted Matrix
Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 
Return the number of negative numbers in grid.

Example 1:
Input: grid = 
[[ 4, 3, 2,-1],
 [ 3, 2, 1,-1],
 [ 1, 1,-1,-2],
 [-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0

Example 3:
Input: grid = [[1,-1],[-1,-1]]
Output: 3

Example 4:
Input: grid = [[-1]]
Output: 1

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

Algo1: naive: O(NlogM) + O(1)
- for every row use upper_bound to find neg

Algo2: O(N+M) + O(1)
- go from the end of 1st row:
- if val < 0: 
    - move left
- else: 
    - count non-zero
    - move down

*/

class Solution {
public:
    int countNegatives(const vector<vector<int>>& grid) {
        int res = 0;
        for (const auto& row : grid) {
            auto it = upper_bound(row.begin(), row.end(), 0, 
                [](int lhs, int rhs) {
                    return lhs > rhs;
                }
            );
            res += distance(it, row.end());
        }
        return res;
    }
};

class Solution {
public:
    int countNegatives(const vector<vector<int>>& grid) {
        size_t m = grid[0].size();
        size_t r = 0, c = grid[0].size()-1;
        int res = 0;
        while (true) {
            if (grid[r][c] < 0 && c != 0) {
                --c;
            } else {
                res += m - c - (c > 0 || grid[r][c] >= 0 ? 1 : 0);
                ++r;
                if (r == grid.size()) break;
            }
        }
        return res;
    }
};

