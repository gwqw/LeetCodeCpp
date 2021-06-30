/**
    1380. Lucky Numbers in a Matrix
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
A lucky number is an element of the matrix such that 
it is the minimum element in its row and maximum in its column.

Example 1:
Input: matrix = 
[[ 3, 7, 8],
 [ 9,11,13],
 [15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column

Example 2:
Input: matrix = 
[[ 1,10, 4, 2],
 [ 9, 3, 8, 7],
 [15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 3:
Input: matrix = [[7,8],[1,2]]
Output: [7]

Constraints:
m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.

Algo: naive: O(N*M + N*N)
- find minimum in row:
    - dict [col_idx] -> min_value (max for all of mins)
- check if it is lucky

*/

class Solution {
    using Matrix = vector<vector<int>>;
public:
    vector<int> luckyNumbers (const vector<vector<int>>& matrix) {
        unordered_map<size_t, int> mins;
        for (const auto& row : matrix) {
            auto it = min_element(row.begin(), row.end());
            size_t ci = distance(row.begin(), it);
            if (mins.count(ci)) {
                if (mins[ci] < *it) {
                    mins[ci] = *it;
                }
            } else {
                mins[ci] = *it;
            }
        }
        vector<int> res;
        for (auto [ci, value] : mins) {
            if (isMaxInCol(ci, value, matrix)) {
                res.push_back(value);
            }
        }
        return res;
    }
    
private:
    static bool isMaxInCol(size_t ci, int value, const Matrix& matrix) {
        for (const auto& row : matrix) {
            if (row[ci] > value) return false;
        }
        return true;
    }

};

