/**
    59. Spiral Matrix II
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

Algo:
- counter = 0
- top:
    - min_ri:
        - for ci in [min_ci, max_ci]:
            - v[min_ri][ci] = counter++
    - ++min_ri
- right:
    - max_ci;
        for ri in [min_ri, max_ri]: ...
    - --max_ci
- bottom:
    - max_ci:
        for ci in [max_ci,min_ci]: ...
    - --max_ci
- left:
    - min_ci:
        for ri in [max_ri, min_ri]: ...
    - ++min_ri

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        assert(n > 0);
        vector<vector<int>> m(n, vector<int>(n, 0));
        int min_ri = 0, max_ri = n-1;
        int min_ci = 0, max_ci = n-1;
        int counter = 1;
        while (true) {
            // top
            for (int ci = min_ci; ci <= max_ci; ++ci) {
                m[min_ri][ci] = counter++;
            }
            ++min_ri;
            if (min_ri > max_ri) break;
            // right
            for (int ri = min_ri; ri <= max_ri; ++ri) {
                m[ri][max_ci] = counter++;
            }
            --max_ci;
            if (min_ci > max_ci) break;
            // bottom
            for (int ci = max_ci; ci >= min_ci; --ci) {
                m[max_ri][ci] = counter++;
            }
            --max_ri;
            if (min_ri > max_ri) break;
            // left
            for (int ri = max_ri; ri >= min_ri; --ri) {
                m[ri][min_ci] = counter++;
            }
            ++min_ci;
            if (min_ri > max_ri) break;
        }
        return m;
    }
};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        assert(n > 0);
        vector<vector<int>> m(n, vector<int>(n, 0));
        size_t min_ri = 0, max_ri = n-1;
        size_t min_ci = 0, max_ci = n-1;
        int counter = 1;
        while (true) {
            // top
            for (size_t ci = min_ci; ci <= max_ci; ++ci) {
                m[min_ri][ci] = counter++;
            }
            ++min_ri;
            if (min_ri > max_ri) break;
            // right
            for (size_t ri = min_ri; ri <= max_ri; ++ri) {
                m[ri][max_ci] = counter++;
            }
            if (max_ci == 0) break;
            --max_ci;
            if (min_ci > max_ci) break;
            // bottom
            for (size_t ci = max_ci; ci >= min_ci; --ci) {
                m[max_ri][ci] = counter++;
                if (ci == 0) break;
            }
            if (max_ri == 0) break;
            --max_ri;
            if (min_ri > max_ri) break;
            // left
            for (size_t ri = max_ri; ri >= min_ri; --ri) {
                m[ri][min_ci] = counter++;
                if (ri == 0) break;
            }
            ++min_ci;
            if (min_ri > max_ri) break;
        }
        return m;
    }
};
