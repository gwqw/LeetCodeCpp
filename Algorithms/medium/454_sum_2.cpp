/**
    454. 4Sum II
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) 
there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

Algo1: naive brute-force O(N^4) (TLE) + O(1)
- for every i,j,k,l check sum
    - if sum == 0:
        - add it to ans 
500^4 = 5^4 * 10^8 ~ 6* 10^10 ~ 600s

Algo2: 3brute-force + set O(N^3) (TLE) + O(N)
- make set from d
- for every i,j,k:
    - find target = - (a[i]+a[j]+a[k])
    - if target in dset 
        - ++ans
500^3 = 5^3 * 10^6 ~ 1* 10^8 ~ 1s

Algo3: precalc every sums a+b and c+d
- precalc a+b sums to vector
- precalc c+d in dict sum -> count
- for every apb in a+b:
    - find in dict:
        res += dict[-(a+b)]

*/

class Solution {
public:
    int fourSumCount(const vector<int>& a, const vector<int>& b, const vector<int>& c, const vector<int>& d) {
        unordered_map<int, int> cd;
        for (auto cv : c) {
            for (auto dv : d) {
                ++cd[cv+dv];
            }
        }
        
        int ans = 0;
        for (auto av : a) {
            for (auto bv : b) {
                if (auto it = cd.find(-(av+bv)); it != cd.end()) {
                    ans += it->second;
                }
            }
        }
        return ans;        
    }
};
