/**
    240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.

Algo1: O(NlogN) + O(1)
- get max row - binary search -- upper_bound
- for r in 0, max_row
    - use binary_search to find value: lower_bound

Algo2: O(rows + cols) ~O(N): search split line in every row
- find first lower_bound in first row
- if el == target: return true
- if el < target: go down # we found split line, new point at next row will be lefter
- if el > target: go left # search split line
    
*/

//256ms
class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        auto max_row_it = upper_bound(matrix.begin(), matrix.end(), target,
            [](int target, const auto& row){
                return target < row[0];
            }
        );
        for (auto rit = matrix.begin(); rit != max_row_it; ++rit) {
            auto& row = *rit;
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) return true;
        }
        return false;
    }
};

//68ms
class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        size_t cidx = distance(matrix[0].begin(),
            lower_bound(matrix[0].begin(), matrix[0].end(), target)
        );
        if (cidx == 0) {
            return matrix[0][cidx] == target;
        }
        if (cidx == matrix[0].size()) --cidx;
        size_t ridx = 0;
        while (ridx < matrix.size()) {
            if (matrix[ridx][cidx] > target) {
                if (cidx == 0) return false; 
                --cidx;
            } else if (matrix[ridx][cidx] < target) {
                ++ridx;
            } else {
                return true;
            }
        }
        return false;
    }
};
//48ms
class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        size_t cidx = matrix[0].size() - 1;
        size_t ridx = 0;
        while (ridx < matrix.size()) {
            if (matrix[ridx][cidx] > target) {
                if (cidx == 0) return false; 
                --cidx;
            } else if (matrix[ridx][cidx] < target) {
                ++ridx;
            } else {
                return true;
            }
        }
        return false;
    }
};



