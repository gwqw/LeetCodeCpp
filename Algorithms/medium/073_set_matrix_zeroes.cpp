/**
    73. Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in-place.

Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Algo: naive: O(n*m), O(n+m)mem
- go through matrix 
    - save to set what columns must be set to zero
    - zero row
- go through matrix and zero value for saved column number

*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<size_t> column2zero;
        set<size_t> visited_rows;
        for (size_t j = 0; j < matrix.size(); ++j) {
            auto& row = matrix[j];
            bool zero_row = false;
            for (size_t i = 0; i < row.size(); ++i) {
                if (row[i] == 0) {
                    column2zero.insert(i);
                    zero_row = true;
                    visited_rows.insert(j);
                }
            }
            if (zero_row) {
                fill(row.begin(), row.end(), 0);
            }
        }
        for (size_t j = 0; j < matrix.size(); ++j) {
            auto& row = matrix[j];
            if (visited_rows.count(j)) continue;
            for (auto cn : column2zero) {
                row[cn] = 0;
            }
        }
    }
};

class Solution {
using Matrix = vector<vector<int>>;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        auto [rz, cz, res] = findFirstZero(matrix);
        if (!res) return;
        
        for (size_t i = 0; i < matrix.size(); ++i) {
            const auto& row = matrix[i];
            for (size_t j = 0; j < row.size(); ++j) {
                if (row[j] == 0) {
                    setColumnNumber2Zero(matrix, j, rz);
                    setRowNumber2Zero(matrix, i, cz);
                }
            }
        }
        
        for (size_t i = 0; i < matrix.size(); ++i) {
            auto& row = matrix[i];
            if (i != rz && rowToZero(matrix, i, cz)) {
                zeroRow(matrix, i);    
            } else {
                for (size_t j = 0; j < row.size(); ++j) {
                    if (colToZero(matrix, j, rz)) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        zeroRow(matrix, rz);
    }
    
private:
    static tuple<size_t, size_t, bool> findFirstZero(const Matrix& matrix) {
        for (size_t i = 0; i < matrix.size(); ++i) {
            const auto& row = matrix[i];
            for (size_t j = 0; j < row.size(); ++j) {
                if (row[j] == 0) return {i, j, true};
            }
        }
        return {0, 0, false};
    }
    
    static void setColumnNumber2Zero(Matrix& matrix, size_t coln, size_t rz) {
        // TODO: good idea to save ref to zero_row
        matrix[rz][coln] = 0;
    }
    
    static void setRowNumber2Zero(Matrix& matrix, size_t rown, size_t cz) {
        matrix[rown][cz] = 0;
    }
    
    static bool rowToZero(const Matrix& matrix, size_t rown, size_t cz) {
        return matrix[rown][cz] == 0;
    }
    
    static bool colToZero(Matrix &matrix, size_t coln, size_t rz) {
        return matrix[rz][coln] == 0;
    }
    
    static void zeroRow(Matrix& matrix, size_t rown) {
        std::fill(matrix[rown].begin(), matrix[rown].end(), 0);
    }
};


