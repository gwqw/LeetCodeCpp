/**
    Matrix rotation:
    1 2
    3 4
    rotates to
    3 1
    4 2
    
    in-place rotation for square matrix
    00, 01, ..., 0i, 0n-1
    10, 11, ..., 1i, 1n-1
    ...
    j0, j1, ..., ji, jn-1
    n-10, n-11, ..., n-1i, n-1n-1
    
    0,0 -> 0,n-1 -> n-1,n-1 -> n-1,0 -> 0,0
    0,i -> i,n-1 -> n-1,n-1-i -> n-1-i,0
    j,i -> i,n-1-j -> n-1-j,n-1-i -> n-1-i,j
*/


class Matrix {
public:
    Matrix(size_t row_count, size_t col_count) {
        if (!row_count || !col_count) return;
        data.resize(row_count);
        for (auto& r : data) {
            r.resize(col_count);
        }
    }
    size_t getRowCount() const {return data.size();}
    size_t getColCount() const {
        if (data.empty()) return 0;
        return data[0].size();
    }
    const std::vector<int>& operator[](size_t idx) const {return data[idx];}
    std::vector<int>& operator[](size_t idx) {return data[idx];}
private:
    std::vector<std::vector<int>> data;
};

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.getRowCount() != rhs.getRowCount() ||
        lhs.getColCount() != rhs.getColCount()) return false;
    for (size_t r = 0; r < lhs.getRowCount(); ++r) {
        for (size_t c = 0; c < lhs.getColCount(); ++c) {
            if (lhs[r][c] != rhs[r][c]) return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    out << "Matrix: " << m.getColCount() << " x " << m.getRowCount() << '\n';
    for (size_t r = 0; r < m.getRowCount(); ++r) {
        for (size_t c = 0; c < m.getColCount(); ++c) {
            out << m[r][c] << ' ';
        }
        out << '\n';
    }
    return out;
}

Matrix rotateMatrix(const Matrix& m) {
    size_t r = m.getRowCount();
    size_t c = m.getColCount();
    if (r == 0 || c == 0) return Matrix(0, 0);

    Matrix res(c, r);
    for (size_t j = 0; j < r; ++j) {
        for (size_t i = 0; i < c; ++i) {
            res[i][r-j-1] = m[j][i];
        }
    }
    return res;
}

void rotateMatrix2(Matrix& m) {
    // j,i -> i,n-1-j -> n-1-j,n-1-i -> n-1-i,j
    double t;
    size_t n = m.getRowCount();
    for (size_t i = 0; i < n / 2; ++i) {
        for (size_t j = 0; j < n / 2; ++j) {
            t = m[i][j];
            m[i][j] = m[n-1-i][j];
            m[n-1-i][j] = m[n-1-j][n-1-i];
            m[n-1-j][n-1-i] = m[i][n-1-j];
            m[i][n-1-j] = t;
        }
    }
}
