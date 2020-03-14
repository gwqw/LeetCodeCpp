/**
    1337. The K Weakest Rows in a Matrix
Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), 
return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, 
or they have the same number of soldiers but i is less than j. 
Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

Example 1:
Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]

Example 2:
Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]

Constraints:
m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.

Algo: naive O(M*N + klogM) + O(M)
- calc strenght for each row
- use min k element

Algo: short scheme, use priority_queue
- make max_heap
- while pq.size() < k
    - calc strength
    - add to pq
- max element in pq <- top
- go through rest rows
    - if strenght is greater than max when calculating:
        - continue
    - else:
        - push row strength to pq
        - pop max
- go through pq and form answer

*/

// 8ms
class Solution {
public:
    vector<int> kWeakestRows(const vector<vector<int>>& mat, int k) {
        size_t m = mat.size();
        size_t n = mat[0].size();
        vector<pair<int, int>> strengths;
        strengths.reserve(m);
        for (size_t i = 0; i < m; ++i) {
            const auto& row = mat[i];
            strengths.emplace_back(calc_strength(row), i);
        }
        partial_sort(strengths.begin(), strengths.begin() + k, strengths.end(), 
            [](const auto& lhs, const auto& rhs) {
                return lhs.first < rhs.first ||
                       (lhs.first == rhs.first && lhs.second < rhs.second);
            }
        );
        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; ++i) {
            res.push_back(strengths[i].second);
        }
        return res;
    }
    
private:
    static int calc_strength(const vector<int> row) {
        int strength = 0;
        for (auto v : row) {
            if (v == 0) break;
            ++strength;
        }
        return strength;
    }
};

//4ms
class Solution {
public:
    vector<int> kWeakestRows(const vector<vector<int>>& mat, int k) {
        size_t m = mat.size();
        size_t n = mat[0].size();
        // make pq with k-elements
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.first < rhs.first ||
                   (lhs.first == rhs.first && lhs.second < rhs.second);
        };
        priority_queue<pair<int, int>, 
                vector<pair<int, int>>,
                decltype(cmp)> strengths(cmp);
        for (size_t i = 0; i < k; ++i) {
            const auto& row = mat[i];
            strengths.emplace(calc_strength(row), i);
        }
        
        // check other rows
        auto max_str = strengths.top().first;
        for (size_t i = k; i < m; ++i) {
            max_str = strengths.top().first;
            if (max_str == 0) break;
            const auto& row = mat[i];
            if (row[max_str-1] == 1) continue;
            strengths.emplace(calc_strength(row), i);
            strengths.pop();
        }
        
        // form result
        vector<int> res(k);
        for (int i = k; i-->0; ) {
            res[i] = strengths.top().second;
            strengths.pop();
        }
        return res;
    }
    
private:
    static int calc_strength(const vector<int> row) {
        int strength = 0;
        for (auto v : row) {
            if (v == 0) break;
            ++strength;
        }
        return strength;
    }
};
