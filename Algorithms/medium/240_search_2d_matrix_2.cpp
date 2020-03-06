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

Algo: O(NlogN) + O(1)
- get max row - binary search -- upper_bound
- for r in 0, max_row
    - use binary_search to find value: lower_bound
    
*/

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        auto max_row_it = find_max_row();
        );
        for (auto rit = matrix.begin(); rit != max_row_it; ++rit) {
            auto& row = *rit;
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) return true;
        }
        return false;
    }
};


