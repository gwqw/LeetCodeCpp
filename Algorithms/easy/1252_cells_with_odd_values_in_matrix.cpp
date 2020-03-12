/**
    1252. Cells with Odd Values in a Matrix
Given n and m which are the dimensions of a matrix initialized by zeros 
and given an array indices where indices[i] = [ri, ci]. 
For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.
Return the number of cells with odd values in the matrix after applying the increment to all indices.

Example 1:
Input: n = 2, m = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.

Example 2:
Input: n = 2, m = 2, indices = [[1,1],[0,0]]
Output: 0
Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.

Algo1: naive: O(k*(n+m) + n*m), O(m*n)
- make matrix
- for every i,j: O(k*(n+m))
    - inc cell in row[i] +1
    - inc cell in col[j] +1
- go through matrix and search odd nums O(N^2)

Algo: O(k+m+n), O(m*n)
- make dict row[r] = count, col[c] = count: O(k)
- odd_rows, even_rows, odd_cols, even_cols: O(m+n)
- answer = odd_rows*even_cols + even_rows*odd_cols O(1)

*/

// naive
class Solution {
    using Matrix = vector<vector<int>>;
public:
    int oddCells(int n, int m, const vector<vector<int>>& indices) {
        Matrix matr(n, vector<int>(m));
        for (const auto& ij : indices) {
            int i = ij[0];
            int j = ij[1];
            incRowValues(matr, i);
            incColValues(matr, j);
        }
        int odds = 0;
        for (const auto& row : matr) {
            for (auto v : row) {
                if (isOdd(v)) ++odds;
            }
        }
        return odds;
    }
    
private:
    static void incRowValues(Matrix& matr, int r) {
        auto& row = matr[r];
        for (auto& v : row) {
            ++v;
        }
    }
    
    static void incColValues(Matrix& matr, int c) {
        for (int i = 0; i < matr.size(); ++i) {
            ++matr[i][c];
        }
    }
    
    static bool isOdd(int n) {
        return n % 2 != 0;
    }
};

// count odd_rows and even_rows
/*
Algo: O(k+m+n), O(m*n)
- make dict row[r] = count, col[c] = count: O(k)
- odd_rows, even_rows, odd_cols, even_cols: O(m+n)
- answer = odd_rows*even_cols + even_rows*odd_cols O(1)
*/
class Solution {
public:
    int oddCells(int n, int m, const vector<vector<int>>& indices) {
        unordered_map<int, int> rows, cols;
        for (const auto& ij : indices) {
            int i = ij[0];
            int j = ij[1];
            ++rows[i];
            ++cols[j];
        }
        int odd_rows{0};
        for (auto [_,c] : rows) {
            if (isOdd(c)) {
                ++odd_rows;
            }
        }
        int even_rows = n - odd_rows;
        int odd_cols{0};
        for (auto [_,c] : cols) {
            if (isOdd(c)) {
                ++odd_cols;
            }
        }
        int even_cols = m - odd_cols;
        return odd_rows*even_cols + even_rows*odd_cols;
    }
    
private:
    static bool isOdd(int n) {
        return n % 2 != 0;
    }
};




