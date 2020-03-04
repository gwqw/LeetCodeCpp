/**
    118. Pascal's Triangle
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Algo: calc row-by-row: O(N^2) + O(1)
 [a0 a1 a2 a3]
[b0 b1 b2 b3 b4]

bi = ai-1 + ai

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) return {};
        vector<vector<int>> res(numRows);
        res[0] = {1};
        for (int i = 1; i < numRows; ++i) {
            auto& prev_row = res[i-1];
            auto& row = res[i];
            row.resize(i+1);
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    row[j] = prev_row[j];
                } else if (j == i) {
                    row[j] = prev_row[j-1];
                } else {
                    row[j] = prev_row[j-1] + prev_row[j];
                }
            }
        }
        return res;
    }
};
