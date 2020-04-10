/**
    1395. Count Number of Teams
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
You have to form a team of 3 soldiers amongst them under the following rules:
Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: 
(rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. 
(soldiers can be part of multiple teams).

Example 1:
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

Example 2:
Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:
Input: rating = [1,2,3,4]
Output: 4

Constraints:
n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5

Algo1: brute-force: O(N^2) + O(1)
- select j:
    - find lesser i-s count i1:  r[i] < r[j]: i < j
    - find greater i-s count i2: r[i] > r[j]: i < j
    - find greater k-s count k1: r[i] < r[k]: j < k
    - find lesser k-s count k2:  r[i] > r[k]: j < k
- return i1*k1 + i2*k2

Algo2: use multiset: O(N^2) + O(N)
- for j in 1, size-1:
    - set[r[i]] left: i < j
    - set[r[k]] right: k > j
    - find i*: count 0 to i*, count i*+1 to size
    - find k*: count k*+1 to size, count 0 to k*
    - add to res
    - j++
    - right[r[j]] -> left[r[j]]


*/

class Solution {
public:
    int numTeams(const vector<int>& r) {
        if (r.size() < 3) return 0;
        int res = 0;
        for (int j = 1; j+1 < (int)r.size(); ++j) {
            auto [i1, i2] = countLesserGreater(r, 0, j, r[j]);
            auto [k2, k1] = countLesserGreater(r, j+1, r.size(), r[j]);
            res += i1*k1 + i2*k2;
        }
        return res;
    }
    
private:
    static pair<int,int> countLesserGreater(const vector<int>& r, int from, int to, int value) {
        int l{0}, g{0};
        for (int i = from; i < to; ++i) {
            if (r[i] < value) {
                ++l;
            } else if (r[i] > value) {
                ++g;
            }
        }
        return {l,g};
    }
};

class Solution {
public:
    int numTeams(const vector<int>& r) {
        if (r.size() < 3) return 0;

    }
};
