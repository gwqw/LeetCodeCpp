/**
    74. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

Algo: 2 binary searches O(logN*logM)
- binary search row: <- upper_bound -1
- binary_search col: <- lower_bound

*/

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        auto rit = upper_bound(matrix.begin(), matrix.end(), target, 
            [](int lhs, const auto& rhs) {
                return lhs < rhs[0];
            }
        );
        if (rit == matrix.begin()) return false;
        --rit;
        const auto& row = *rit;
        auto cit = lower_bound(row.begin(), row.end(), target);
        return cit != row.end() && *cit == target;
    }
};