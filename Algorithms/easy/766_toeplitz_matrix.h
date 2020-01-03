/**
    766. Toeplitz Matrix

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
Now given an M x N matrix, return True if and only if the matrix is Toeplitz.

Example 1:
Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

Example 2:
Input:
matrix = [
  [1,2],
  [2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.

Note:
matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].

Follow up:
What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?

Algo: O(N*M) + O(1)
main diag: i == j: for every i: a[i] -- the same
- k -- shift:
- for k = 0; k < n; ++k:
    - int c = -1
    - int d = -1
    - for i = 0; i < n; ++i:
        - if i + k >= n: continue
        - if c == -1: c = a[i+k][i] continue
        - if c != a[i+k][i]: return false
    - for i = 0; i < n; ++i:
        - if i - k < 0: continue
        - if d == -1: d = [i-k][i] continue
        - if d != a[i-k][i]: return false
- return true

*/

class Solution {
public:
    bool isToeplitzMatrix(const vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        if (n <= 1) return true;
        int m = matrix[0].size();
        for (int k = 0; k < n-1; ++k) {
            int diag = matrix[k][0];
            for (int i = 1; i < n-k; ++i) {
                if (i >= m) break;
                if (diag != matrix[i+k][i]) {
                    return false;
                }
            }
        }
        for (int k = 1; k < m-1; ++k) {
            int diag = matrix[0][k];
            for (int i = 1; i < m-k; ++i) {
                if (i >= n) break;
                if (diag != matrix[i][i+k]) {
                    return false;
                }
            }
        }
        return true;
    }
};







