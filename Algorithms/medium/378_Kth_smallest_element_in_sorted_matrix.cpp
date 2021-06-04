/**
    378. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n^2.

Algo: O(k*N) + O(N)
- make vector<size_t> first unvisited idx in row, initialy 0 and first = 1
- iteration ki = 1
- cur r,c = 0,0, cur_value = m[r][c]
- while (ki < k)
    - init min: min mr, mc = r, c+1 (if c+1 != n) or mr = r+1, c = unvisited[mr] (if r+1 != n) else this is the end
    - find next element:
        - for every row take start sc in unvisited:
            - if unvisited[row] == n continue
            - if m[row][unvisited[row]] < min_value;
                - update(mr, mc, min_value)
                - if unvisited[row] == 0: break
    - update cur: r = mr, c = mc, cur_value = m[r][c]
    - update unvisited: ++unvisited[mr]
    - update: ++ki

Algo: binary search on range. O(N*logN*log(range)), range = a[0][0] -- a[n-1][n-1]
l = a[0][0]
r = a[n-1][n-1]
while l+1<r:
    m = l + (r-l) / 2
    count = [upper_bound() for every row].sum()
    if count > k:
        r = mid
    else:
        l = mid


*/

class Solution {
public:
    int kthSmallest(const vector<vector<int>>& m, int k) {
        assert(!m.empty());
        size_t n = m.size();
        vector<size_t> unvisited(n, 0);
        unvisited[0] = 1;
        size_t r = 0, c = 0;
        int cur_value = m[r][c];
        int ki = 1;
        while (ki < k) {
            size_t mr = r, mc = c;
            int min_value = 0;
            bool has_minvalue = false;
            // find next
            // TODO: enhance: use start idx for unvisited
            for (size_t row = 0; row < n; ++row) {
                size_t col = unvisited[row];
                assert(col <= n);
                if (col == n) continue;
                if (!has_minvalue || m[row][col] < min_value) {
                    has_minvalue = true;
                    mr = row;
                    mc = col;
                    min_value = m[row][col];
                    if (col == 0) break;
                }
            }
            // updates
            r = mr;
            c = mc;
            cur_value = min_value;
            ++unvisited[mr];
            ++ki;
        }
        return cur_value;
    }
};

class Solution {
public:
    int kthSmallest(const vector<vector<int>>& m, int k) {
        assert(!m.empty());
        size_t n = m.size();
        int l = m[0][0];
        int r = m.back().back();
        while (l < r) {
            int mid = l + (r-l)/2;
            size_t count = 0;
            for (size_t row = 0; row < n; ++row) {
                size_t c = upper_bound(m[row].begin(), m[row].end(), mid) - m[row].begin();
                if (c == 0) break;
                count += c;
            }
            if (count < k) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

class Solution {
public:
    int kthSmallest(const vector<vector<int>>& m, int k) {
        assert(!m.empty());
        size_t n = m.size();
        int l = m[0][0];
        int r = m.back().back();
        while (l < r) {
            int mid = l + (r-l)/2;
            size_t count = 0;
            auto eit = upper_bound(m.begin(), m.end(), mid, [](int lhs, const auto& rhs){return lhs < rhs[0];});
            for (auto it = m.begin(); it != eit; ++it) {
                size_t c = upper_bound(it->begin(), it->end(), mid) - it->begin();
                if (c == 0) break;
                count += c;
            }
            if (count < k) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

