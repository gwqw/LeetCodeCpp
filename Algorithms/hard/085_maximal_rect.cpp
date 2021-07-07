/**
    85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = 
[["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = []
Output: 0

Example 3:
Input: matrix = [["0"]]
Output: 0

Example 4:
Input: matrix = [["1"]]
Output: 1

Example 5:
Input: matrix = [["0","0"]]
Output: 0

Constraints:
rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

Algo: dp for heights in each column + max height in histogram

*/

class Solution {
public:
    int maximalRectangle(const vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        size_t n = matrix.size();
        size_t m = matrix[0].size();
        vector<int> heights(m);
        int max_area = 0;
        for (const auto& row : matrix) {
            vector<int> cur_heights(m);
            for (size_t j = 0; j < m; ++j) {
                cur_heights[j] = row[j] != '0' ? heights[j]+1 : 0;
            }
            swap(cur_heights, heights);
            max_area = max(max_area, largestRectangleArea(heights));
        }
        return max_area;
    }
    
private:
    int largestRectangleArea(const vector<int>& heights) {
        stack<pair<int, int>> st;
        int area = 0;
        for (int i = 0; i < (int)heights.size(); ++i) {
            area = max(area, heights[i]);
            while (!st.empty() && st.top().second >= heights[i]) {
                auto [j,h] = st.top();
                st.pop();
                j = st.empty() ? 0 : st.top().first+1;
                area = max(area, h * (i - j));
            }
            st.emplace(i, heights[i]);
        }
        int ei = (int)heights.size();
        while (!st.empty()) {
            auto [i, h] = st.top();
            st.pop();
            i = st.empty() ? 0 : st.top().first+1;
            area = max(area, h * (ei - i));
        }
        return area;
    }
};

[["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]]
 
  1    0   1   0   1
  2    0   2   1   1
  3    1   3   2   2
  4    0   0   3   0
  
  
[["0","0","0","0","0","0","1"],
 ["0","0","0","0","1","1","1"],
 ["1","1","1","1","1","1","1"],
 ["0","0","0","1","1","1","1"]]
                      2,2 3,2   
                      2,3 
