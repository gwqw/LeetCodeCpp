/**
    54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Algo:
4 path:
- i = r_first; j:c_first->c_last: r_first += 1
- j = c_last, i: r_first -> r_last: c_last -= 1
- i = r_last, j: c_last -> c_first: r_last -= 1
- j = c_first, i: r_last -> r_first: c_first += 1


*/

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        size_t r_first = 0, c_first = 0;
        size_t r_last = matrix.size() - 1;
        size_t c_last = matrix[0].size() - 1;
        vector<int> res;
        while (r_first <= r_last && c_first <= c_last) {
            // to right
            int i = r_first;
            for (int j = c_first; j <= c_last; ++j) {
                res.push_back(matrix[i][j]);
            }
            if (r_first == r_last) break;
            r_first++;
            // down
            int j = c_last;
            for (int i = r_first; i <= r_last; ++i) {
                res.push_back(matrix[i][j]);
            }
            if (c_last == c_first) break;
            c_last--;
            // left
            if (r_first > r_last) break;
            i = r_last;
            for (int j = c_last+1; j-->c_first; ) {
                res.push_back(matrix[i][j]);
            }
            if (r_last == r_first) break;
            r_last--;
            // up
            j = c_first;
            for (int i = r_last+1; i-->r_first; ) {
                res.push_back(matrix[i][j]);
            }
            c_first++;
        }
        return res;
    }
};



