/**
    498. Diagonal Traverse
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Example 1:
Input: mat = 
[[1,2,3],
 [4,5,6],
 [7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:
Input: mat = 
[[1,2],
 [3,4]]
Output: [1,2,3,4]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
-10^5 <= mat[i][j] <= 10^5

Algo:
"main" diag: a[i][n-i]
for k in range(0, max(n,m)):
	k % 2 == 1:
		for i in range 0, m:
			if i, k in range(0..n-1, 0..m-1)
			next = a[i][k-i]
	else:
		for i in range m-1, -1:
			if i, k in range(0..n-1, 0..m-1)
			next = a[i][k-i]
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
		int n = mat.size();
		int m = mat[0].size();
		for (int k = 0; k < n+m-1; ++k) {
			if (k % 2 == 1) {
				for (int i = 0; i < n; ++i) {
                    int j = k-i;
					if (0 <= j && j < m) {
						res.push_back(mat[i][j]);
					}
				}
			} else {
				for (int i = n-1; i >= 0; --i) {
                    int j = k-i;
					if (0 <= j && j < m) {
						res.push_back(mat[i][j]);
					}
				}
			}
		}
		return res;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
		int n = mat.size();
		int m = mat[0].size();
        bool up = true;
		for (int k = 0; k < n; ++k) {
			if (!up) {
				for (int i = max(0, k-m+1); i < n; ++i) {
                    int j = k-i;
                    if (j < 0) break;
                    res.push_back(mat[i][j]);
				}
			} else {
				for (int i = min(k,n-1); i >= 0; --i) {
                    int j = k-i;
                    if (j >= m) break;
                    res.push_back(mat[i][j]);
				}
			}
            up = !up;
		}
        for (int k = n; k < n+m-1; ++k) {
            if (up) {
				for (int j = k-n+1; j < m; ++j) {
                    int i = k-j;
                    if (i < 0) break;
                    res.push_back(mat[i][j]);
				}
			} else {
				for (int j = min(m-1, k); j >= 0; --j) {
                    int i = k-j;
                    if (i >= n) break;
                    res.push_back(mat[i][j]);
				}
			}
            up = !up; 
        }
		return res;
    }
};