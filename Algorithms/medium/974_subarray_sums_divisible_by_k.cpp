/**
    974. Subarray Sums Divisible by K
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

Example 1:
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Note:
1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000

Algo1: predicate sums + bruteforce O(N^2) + O(N) TLE

Algo2: predicate sum + dict O(N) + O(N)
- dict[resid] -> count

*/

class Solution {
public:
    int subarraysDivByK(const vector<int>& a, int k) {
        if (a.empty()) return 0;
        unordered_map<int, int> dict;
        int sum = 0;
        int sums = 0;
        for (auto n : a) {
            sum = mod(sum + n, k);
            if (sum == 0) {
                ++sums;
            }
            sums += dict[sum]++;
        }
        return sums;
    }
private:
    int mod(int num, int div) {
        int res = num % div;
        return res >= 0 ? res : div + res;
    }
};

class Solution {
public:
    int subarraysDivByK(const vector<int>& a, int k) {
        if (a.empty()) return 0;
        vector<int> dict(k, 0);
        int sum = 0;
        int sums = 0;
        for (auto n : a) {
            sum = mod(sum + n, k);
            if (sum == 0) {
                ++sums;
            }
            sums += dict[sum]++;
        }
        return sums;
    }
private:
    int mod(int num, int div) {
        int res = num % div;
        return res >= 0 ? res : div + res;
    }
};
