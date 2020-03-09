/**
    867. Transpose Matrix
Given a matrix A, return the transpose of A.
The transpose of a matrix is the matrix flipped over it's main diagonal, 
switching the row and column indices of the matrix.

Example 1:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:
Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

Note:
1 <= A.length <= 1000
1 <= A[0].length <= 1000

Algo1: copy
- i -> j

Algo2: in-place

*/

// copy
class Solution {
public:
    vector<vector<int>> transpose(const vector<vector<int>>& matr) {
        size_t n = matr.size();
        size_t m = matr[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                res[j][i] = matr[i][j];
            }
        }
        return res;
    }
};

// in-place
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matr) {
        size_t n = matr.size();
        size_t m = matr[0].size();
        assert(n == m;)
        for (size_t i = 0; i+1 < n; ++i) {
            for (size_t j = i+1; j < m; ++j) {
                swap(matr[j][i], matr[i][j]);
            }
        }
        return move(matr);
    }
};

//combined
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matr) {
        size_t n = matr.size();
        size_t m = matr[0].size();
        if (n == m) {
            transpose_square(matr, n);
            return move(matr);
        } else {
            return transpose(matr, n, m);
        }
    }
    
private:
    static void transpose_square(vector<vector<int>>& matr, size_t n) {
        for (size_t i = 0; i+1 < n; ++i) {
            for (size_t j = i+1; j < n; ++j) {
                swap(matr[j][i], matr[i][j]);
            }
        }
    }
    
    static vector<vector<int>> transpose(const vector<vector<int>>& matr, size_t n, size_t m) {
        vector<vector<int>> res(m, vector<int>(n));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                res[j][i] = matr[i][j];
            }
        }
        return res;
    }
    
};


