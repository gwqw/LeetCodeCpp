/**
    Write an algorithm such that if an element in an MxN matrix is 0, 
    its entire row and column is set to 0.
    
    Algo:
    - go through matrix if 0: cache raw_num and col_num to the set
    - go through stack and set whole raw or col to 0
    O(MxN) + O(M+N)
*/

#include <unordered_set>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    out << "Matrix: " << m.size() << " x " << m.at(0).size() << '\n';
    for (const auto& r : m) {
        for (auto c : r) {
            out << c << ' ';
        }
        out << '\n';
    }
    return out;
}

void zeroMatrixColsAndRaws(Matrix& matr) {
    size_t m = matr.size();
    if (m == 0) return;
    size_t n = matr[0].size();
    if (n == 0) return;
    
    // cache row and col numbers, which will be set to 0
    unordered_set<size_t> cols, rows;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (matr[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    
    // zero rows and cols
/*    for (auto c : cols) {
        for (size_t i = 0; i < m; ++i) {
            matr[i][c] = 0;
        }
    }
    for (auto r : rows) {
        for (size_t j = 0; j < n; ++j) {
            matr[r][j] = 0;
        }
    }
*/
    
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (rows.count(i) || cols.count(j)) {
                matr[i][j] = 0;
            }
        }
    }
}

